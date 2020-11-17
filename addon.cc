#include <napi.h>

#include "myRealMesh.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return MyMesh::Init(env, exports);
}

NODE_API_MODULE(addon, InitAll)
