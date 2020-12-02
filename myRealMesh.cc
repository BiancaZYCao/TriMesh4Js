#include "myRealMesh.h"

#include <iostream>
#include <iterator>
// -------------------- OpenMesh
#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>

//internal use snack_case || external use camelCase
typedef OpenMesh::TriMesh_ArrayKernelT<>  TriMesh;

Napi::FunctionReference MyMesh::constructor;

Napi::Object MyMesh::Init(Napi::Env env, Napi::Object exports) {
  //Napi::HandleScope scope(env); //not necessary

  Napi::Function func =
      DefineClass(env,
                  "MyMesh",
                  {InstanceMethod("addVertex", &MyMesh::AddVertex),
                   InstanceMethod("getNumFace", &MyMesh::GetFaceValue),
                   InstanceMethod("addFace", &MyMesh:: AddFace),
                   InstanceMethod("addFaceById", &MyMesh:: AddFaceById),
                   InstanceMethod("points", &MyMesh::GetPoints),
                   InstanceMethod("setPointById", &MyMesh::SetPointById),
                   InstanceMethod("setPoint", &MyMesh::SetPoint),
                   InstanceMethod("vv", &MyMesh::VVIter),
                   InstanceMethod("bFSNeighWeights", &MyMesh::BFSNeighWeights)
                   });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("MyMesh", func);
  return exports;
}

MyMesh::MyMesh(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<MyMesh>(info) {
  // Napi::Env env = info.Env(); 
  // Napi::HandleScope scope(env); //not necessary

  TriMesh mesh;
  this->myTriMesh_ = mesh;

  std::vector<TriMesh::VertexHandle>  storage_vhandles;
  this->vHStorage_ = storage_vhandles;
  
  // request vertex normals, so the mesh reader can use normal information
  // if available
  mesh.request_vertex_normals();
  // assure we have vertex normals
  if (!mesh.has_vertex_normals())
  {
    std::cerr << "ERROR: Standard vertex property 'Normals' not available!\n";
  }
}

Napi::Value MyMesh::GetFaceValue(const Napi::CallbackInfo& info) {
  TriMesh mesh =  this->myTriMesh_;
  // int num = mesh.n_faces().Int32Value(); error: member reference base type 'size_t' (aka 'unsigned long') is not a structure or union
  size_t nFace = mesh.n_faces();
  int num = static_cast<int>(nFace);

  return Napi::Number::New(info.Env(), num);
}

Napi::Value MyMesh::AddVertex(const Napi::CallbackInfo& info) {
  TriMesh mesh =  this->myTriMesh_;
  if (info.Length() != 3 || !info[0].IsNumber() || !info[1].IsNumber() || !info[2].IsNumber() ) {
    Napi::TypeError::New(_env, "Napi AddVertex_Err: 3 numbers expected.").ThrowAsJavaScriptException();
    return Napi::Number::New(info.Env(), -1);
  } else {
    double pointX = info[0].As<Napi::Number>().DoubleValue();
    double pointY = info[1].As<Napi::Number>().DoubleValue();
    double pointZ = info[2].As<Napi::Number>().DoubleValue();
    TriMesh::VertexHandle new_vh = mesh.add_vertex(TriMesh::Point(pointX,pointY,pointZ));
    this->vHStorage_.push_back(new_vh);
    this->myTriMesh_ = mesh;
    // if ((int)mesh.n_vertices()<=3){
    //   std::cout << "const ptrVHS : "  << this->ptrVHS << "  type: " << typeid(this->ptrVHS).name() << std::endl;
    //   std::cout << "CPP success: a new vertex added.  ref: " << this->ptrVHS+(int)mesh.n_vertices()-1 << std::endl;
    // }
    return Napi::External<std::vector<TriMesh::VertexHandle>>::New(info.Env(), this->ptrVHS+(int)mesh.n_vertices()-1); 

  }
 
}

Napi::Value MyMesh::VVIter(const Napi::CallbackInfo& info) {
  TriMesh mesh =  this->myTriMesh_;
  std::vector<OpenMesh::TriMesh_ArrayKernelT<>::VertexHandle> vhs =  this->vHStorage_;
  TriMesh::VertexVertexIter    vv_it;
  if (info.Length() != 1) {
    Napi::TypeError::New(_env, "Napi VVIter_Err: 1 param expected.").ThrowAsJavaScriptException();
    return Napi::Number::New(info.Env(), -1);
  } else {
    int num_neigh = 0 ;
    auto vh = info[0].As<Napi::External<std::vector<TriMesh::VertexHandle>>>().Data(); 
    int vh_idx = (vh)-(this->ptrVHS); 
    for (vv_it=mesh.vv_iter(vhs[vh_idx]); vv_it.is_valid(); ++vv_it){
      //  std::cout << "neighbor point idx : " << vv_it->idx() << std::endl;
      //  std::cout << "neighbor point data : " << mesh.point( *vv_it ) << std::endl; 
       num_neigh++;
    }
    unsigned int i = 0 ;
    Napi::Array neighboursVHArray = Napi::Array::New(info.Env(),num_neigh);
    for (vv_it=mesh.vv_iter(vhs[vh_idx]); vv_it.is_valid(); ++vv_it){
      std::vector<TriMesh::VertexHandle> * temp_vh_ptr = this->ptrVHS + (int)vv_it->idx();
      neighboursVHArray[i] = Napi::External<std::vector<TriMesh::VertexHandle>>::New(info.Env(), temp_vh_ptr);
      i++;
    }
    return neighboursVHArray;

  }
 
}

Napi::Value MyMesh::BFSNeighWeights(const Napi::CallbackInfo& info) {
  TriMesh mesh =  this->myTriMesh_;
  std::vector<OpenMesh::TriMesh_ArrayKernelT<>::VertexHandle> vhs =  this->vHStorage_;
  TriMesh::VertexVertexIter    vv_it;
  if (info.Length() != 1) {
    Napi::TypeError::New(_env, "Napi VVIter_Err: 1 param expected.").ThrowAsJavaScriptException();
    return Napi::Number::New(info.Env(), -1);
  } else {
    // init Napi:Object-weights and temp_vhs
    Napi::Object weights = Napi::Object::New(info.Env());
    auto vh = info[0].As<Napi::External<std::vector<TriMesh::VertexHandle>>>().Data(); 
    int vh_idx = (vh)-(this->ptrVHS); 
    weights.Set(vh_idx,(double)0);
    std::vector<TriMesh::VertexHandle> new_added_points;
   
    new_added_points.push_back(vhs[vh_idx]);
    unsigned int i = 0;
    while (new_added_points.size()>0){
       std::vector<TriMesh::VertexHandle> temp_points;
       temp_points.clear();
       for (i=0;i<new_added_points.size();i++) {
          int f = new_added_points[i].idx();
          for (vv_it=mesh.vv_iter(new_added_points[i]); vv_it.is_valid(); ++vv_it){
            uint32_t k = (int)vv_it->idx();
            if (!weights.Has(k)){
              double weightVal =  weights.Get(f).As<Napi::Number>().DoubleValue() + 1.0; 
              weights.Set(k,weightVal);
              temp_points.push_back(*vv_it);
            }
          }
       }
       new_added_points = temp_points;
    }
    for (i=0;i<mesh.n_vertices();i++){
      if (!weights.Has(i)){
        weights.Set(i,1000);
      }
    }
       return weights;
    }
    

  }
 
void MyMesh::AddFace(const Napi::CallbackInfo& info) {
  TriMesh mesh =  this->myTriMesh_;
  std::vector<OpenMesh::TriMesh_ArrayKernelT<>::VertexHandle> vhs =  this->vHStorage_;
  if (info.Length() != 3 ){ 
     Napi::TypeError::New(_env, "Napi 3 VertexHandles expected.").ThrowAsJavaScriptException();
  } else {
    std::vector<TriMesh::VertexHandle>  temp_face_vhandles;
    temp_face_vhandles.clear();
    auto vh1 = info[0].As<Napi::External<std::vector<TriMesh::VertexHandle>>>().Data(); 
    auto vh2 = info[1].As<Napi::External<std::vector<TriMesh::VertexHandle>>>().Data();
    auto vh3 = info[2].As<Napi::External<std::vector<TriMesh::VertexHandle>>>().Data();

    int vh1_idx = (vh1)-(this->ptrVHS); 
    int vh2_idx =  (vh2)-(this->ptrVHS);
    int vh3_idx =  (vh3)-(this->ptrVHS);
    
    temp_face_vhandles.push_back(vhs[vh1_idx]);
    temp_face_vhandles.push_back(vhs[vh2_idx]);
    temp_face_vhandles.push_back(vhs[vh3_idx]);
    
    mesh.add_face(temp_face_vhandles);
    
    temp_face_vhandles.clear();
    this->myTriMesh_ = mesh;
  }
  return;
}
void MyMesh::SetPoint(const Napi::CallbackInfo& info) {
  if (info.Length() != 2 || !info[1].IsArray()) {
    Napi::TypeError::New(_env, "Napi Err: 2 params expected: first as vertex_id second as new_point_array").ThrowAsJavaScriptException();
    return ;// Napi::Number::New(info.Env(), -1);
  } 
  else if (info[1].As<Napi::Array>().Length() != 3){
      Napi::TypeError::New(_env, "Napi Err: second param must be an array with 3 numbers.").ThrowAsJavaScriptException();
      return ;//Napi::Number::New(info.Env(), -1);
    }
  else {
    TriMesh mesh =  this->myTriMesh_;
    std::vector<OpenMesh::TriMesh_ArrayKernelT<>::VertexHandle> vhs =  this->vHStorage_;

    auto vh = info[0].As<Napi::External<std::vector<TriMesh::VertexHandle>>>().Data(); 
    int input_vidx = (vh)-(this->ptrVHS); 

    const Napi::Array newPointArray = info[1].As<Napi::Array>();
    unsigned int i = 0 ;
    double  newPointX  = newPointArray[i++].As<Napi::Number>().DoubleValue();
    double  newPointY = newPointArray[i++].As<Napi::Number>().DoubleValue();
    double  newPointZ = newPointArray[i++].As<Napi::Number>().DoubleValue();

    mesh.set_point( vhs[input_vidx], 
      TriMesh::Point(newPointX,newPointY,newPointZ));

    this->myTriMesh_ = mesh;
    return ;

  }
 
}

void MyMesh::AddFaceById(const Napi::CallbackInfo& info) {
  TriMesh mesh =  this->myTriMesh_;
  std::vector<OpenMesh::TriMesh_ArrayKernelT<>::VertexHandle> vhs =  this->vHStorage_;
  if (info.Length() != 3 || !info[0].IsNumber() || !info[1].IsNumber() || !info[2].IsNumber() ) {
     Napi::TypeError::New(_env, "Napi 3 numbers expected.").ThrowAsJavaScriptException();
  } else {
    std::vector<TriMesh::VertexHandle>  temp_face_vhandles;
    temp_face_vhandles.clear();
    
    temp_face_vhandles.push_back(vhs[info[0].As<Napi::Number>().Int32Value()]);
    temp_face_vhandles.push_back(vhs[info[1].As<Napi::Number>().Int32Value()]);
    temp_face_vhandles.push_back(vhs[info[2].As<Napi::Number>().Int32Value()]);

    mesh.add_face(temp_face_vhandles);
  
    temp_face_vhandles.clear();
    this->myTriMesh_ = mesh;
  }
  return;
}

void MyMesh::SetPointById(const Napi::CallbackInfo& info) {
  if (info.Length() != 2 || !info[0].IsNumber() || !info[1].IsArray()) {
    Napi::TypeError::New(_env, "Napi Err: 2 params expected: first as vertex_id second as new_point_array").ThrowAsJavaScriptException();
    return ;//Napi::Number::New(info.Env(), -1);
  } else {
    if (info[1].As<Napi::Array>().Length() != 3){
      Napi::TypeError::New(_env, "Napi Err: second param must be an array with 3 numbers.").ThrowAsJavaScriptException();
      return ;//Napi::Number::New(info.Env(), -1);
    }
    TriMesh mesh =  this->myTriMesh_;
    std::vector<OpenMesh::TriMesh_ArrayKernelT<>::VertexHandle> vhs =  this->vHStorage_;

    int input_vidx = info[0].As<Napi::Number>().Int32Value();

    const Napi::Array newPointArray = info[1].As<Napi::Array>();
    unsigned int i = 0 ;
    double newPointX = newPointArray[i++].As<Napi::Number>().DoubleValue();
    double newPointY = newPointArray[i++].As<Napi::Number>().DoubleValue();
    double newPointZ = newPointArray[i++].As<Napi::Number>().DoubleValue();

    mesh.set_point( vhs[input_vidx], 
      TriMesh::Point(newPointX,newPointY,newPointZ));
    this->myTriMesh_ = mesh;
    
    return ;
  }
}

Napi::Value MyMesh::GetPoints(const Napi::CallbackInfo& info) {
  if (info.Length() != 0) {
    Napi::TypeError::New(_env, "Napi Err: 0 params expected.").ThrowAsJavaScriptException();
    return Napi::Number::New(info.Env(), -1);
  } else {
    TriMesh mesh =  this->myTriMesh_;
    std::vector<OpenMesh::TriMesh_ArrayKernelT<>::VertexHandle> vhs =  this->vHStorage_;
    Napi::Array pointsArray = Napi::Array::New(info.Env(),(int)mesh.n_vertices());
    unsigned int iv = 0 ;//error: no viable overloaded operator[] for type 'Napi::Array'
    for (TriMesh::VertexIter v_it = mesh.vertices_begin();
      v_it != mesh.vertices_end(); 
      ++v_it){
        
        OpenMesh::VectorT<float, 3> point = mesh.point(*v_it);
        
        Napi::Array pointArray = Napi::Array::New(info.Env(),3);
        unsigned int i = 0 ;
        while (i<3) {
          pointArray[i] = Napi::Number::New(info.Env(), point[i]);
          i++;
        }
        
        pointsArray[iv++] = pointArray;
      }
    
    return pointsArray ;
  }
}