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
  Napi::HandleScope scope(env);

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
                   InstanceMethod("bFS", &MyMesh::BFSNeigh)
                   });

  // Napi::FunctionReference* constructor = new Napi::FunctionReference();
  // *constructor = Napi::Persistent(func);
  // env.SetInstanceData(constructor);
  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("MyMesh", func);
  return exports;
}

MyMesh::MyMesh(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<MyMesh>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

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
    //Napi::Number::New(info.Env(),&new_vh);

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
      // neighboursIdxArray[i] = (int)vv_it->idx();
      // std::cout << "temp_vh type: " <<typeid(temp_vh).name()<< std::endl;
      i++;
    }
    return neighboursVHArray;

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
      // neighboursIdxArray[i] = (int)vv_it->idx();
      // std::cout << "temp_vh type: " <<typeid(temp_vh).name()<< std::endl;
      i++;
    }
    return neighboursVHArray;

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
    // std::cout << "CPP running: read 3 vhs as input to make a new face" << std::endl;
    // std::cout << "vh1 : " << vh1 << "  type: " << typeid(vh1).name() << std::endl;
    // std::cout << "&vhs[0] : "  << &vhs[0] << "  type: " << typeid(&vhs[0]).name() << std::endl;
    // std::cout << "&(this->vHStorage_)[0] : "  << &(this->vHStorage_)[0] << "  type: " << typeid(&(this->vHStorage_)[0]).name() << std::endl;
    int vh1_idx = (vh1)-(this->ptrVHS); 
    int vh2_idx =  (vh2)-(this->ptrVHS);
    int vh3_idx =  (vh3)-(this->ptrVHS);
    // std::cout << "vh1-(this->ptrVHS) = " << vh1_idx << "  type: " << typeid(vh1_idx).name() << std::endl;
    temp_face_vhandles.push_back(vhs[vh1_idx]);
    temp_face_vhandles.push_back(vhs[vh2_idx]);
    temp_face_vhandles.push_back(vhs[vh3_idx]);
    // std::cout << "CPP running: pushed 3 vhs into face_vhandles" << std::endl;
    mesh.add_face(temp_face_vhandles);
    // std::cout << "CPP success: A new face added" << std::endl;
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
    // std::cout << "CPP new point x,y,z from vHS: [ "<< newPointX << ", "<<newPointY<< ", "<<newPointZ<< " ]" << std::endl;
    // std::cout << "CPP success: update a point. " << std::endl;
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
    // std::cout << "CPP running: read 3 vhs_id as input to make a new face" << std::endl;
    temp_face_vhandles.push_back(vhs[info[0].As<Napi::Number>().Int32Value()]);
    temp_face_vhandles.push_back(vhs[info[1].As<Napi::Number>().Int32Value()]);
    temp_face_vhandles.push_back(vhs[info[2].As<Napi::Number>().Int32Value()]);
    // std::cout << "CPP running: pushed 3 vhs into face_vhandles" << std::endl;
    mesh.add_face(temp_face_vhandles);
    // std::cout << "CPP success: A new face added" << std::endl;
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
    // std::cout << "CPP new point x,y,z from vHS: "<< this->vHStorage_[input_vidx]  << std::endl;
    // std::cout << "CPP success: update a point. " << std::endl;
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
        // std::cout << "start reading points idx(*v_it)  : " << *v_it << std::endl;
        OpenMesh::VectorT<float, 3> point = mesh.point(*v_it);
        // std::cout << "point info : " << point << std::endl;
        Napi::Array pointArray = Napi::Array::New(info.Env(),3);
        unsigned int i = 0 ;
        while (i<3) {
          pointArray[i] = Napi::Number::New(info.Env(), point[i]);
          i++;
        }
        // std::cout << "put into pointsArr. " << std::endl;
        pointsArray[iv++] = pointArray;
      }
    
    // std::cout << "CPP success: update a point. " << std::endl;
    return pointsArray ;
  }
}