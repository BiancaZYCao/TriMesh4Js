#ifndef MYMESH_H
#define MYMESH_H

#include <napi.h>
// -------------------- OpenMesh
#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>

typedef OpenMesh::TriMesh_ArrayKernelT<>  TriMesh;

class MyMesh : public Napi::ObjectWrap<MyMesh> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  MyMesh(const Napi::CallbackInfo& info);

 private:
  static Napi::FunctionReference constructor;
  OpenMesh::TriMesh_ArrayKernelT<>  myTriMesh_;
  std::vector<TriMesh::VertexHandle>  vHStorage_;
  std::vector<TriMesh::VertexHandle> * const ptrVHS = &vHStorage_;
  
  Napi::Value GetFaceValue(const Napi::CallbackInfo& info);
  Napi::Value AddVertex(const Napi::CallbackInfo& info);
  void AddFace(const Napi::CallbackInfo& info);
  void AddFaceById(const Napi::CallbackInfo& info);

  void SetPointById(const Napi::CallbackInfo& info);
  void SetPoint(const Napi::CallbackInfo& info);
  Napi::Value GetPoints(const Napi::CallbackInfo& info);

  Napi::Value VVIter(const Napi::CallbackInfo& info);
  Napi::Value BFSNeighWeights(const Napi::CallbackInfo& info);

  // int valueOfFace;
};

#endif
