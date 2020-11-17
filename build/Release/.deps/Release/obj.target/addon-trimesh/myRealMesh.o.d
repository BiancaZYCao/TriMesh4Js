cmd_Release/obj.target/addon-trimesh/myRealMesh.o := c++ -o Release/obj.target/addon-trimesh/myRealMesh.o ../myRealMesh.cc '-DNODE_GYP_MODULE_NAME=addon-trimesh' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-DV8_DEPRECATION_WARNINGS' '-DV8_IMMINENT_DEPRECATION_WARNINGS' '-D_DARWIN_USE_64_BIT_INODE=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DOPENSSL_NO_PINSHARED' '-DOPENSSL_THREADS' '-DNAPI_DISABLE_CPP_EXCEPTIONS' '-DBUILDING_NODE_EXTENSION' -I/Users/margret/Library/Caches/node-gyp/14.15.0/include/node -I/Users/margret/Library/Caches/node-gyp/14.15.0/src -I/Users/margret/Library/Caches/node-gyp/14.15.0/deps/openssl/config -I/Users/margret/Library/Caches/node-gyp/14.15.0/deps/openssl/openssl/include -I/Users/margret/Library/Caches/node-gyp/14.15.0/deps/uv/include -I/Users/margret/Library/Caches/node-gyp/14.15.0/deps/zlib -I/Users/margret/Library/Caches/node-gyp/14.15.0/deps/v8/include -I/usr/local/Cellar/open-mesh/8.1/include -I/Users/margret/TriMesh4Js/node_modules/node-addon-api  -O3 -gdwarf-2 -mmacosx-version-min=10.13 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-strict-aliasing -mmacosx-version-min=10.7 -std=c++11 -stdlib=libc++ -MMD -MF ./Release/.deps/Release/obj.target/addon-trimesh/myRealMesh.o.d.raw   -c
Release/obj.target/addon-trimesh/myRealMesh.o: ../myRealMesh.cc \
  ../myRealMesh.h \
  /Users/margret/TriMesh4Js/node_modules/node-addon-api/napi.h \
  /Users/margret/Library/Caches/node-gyp/14.15.0/include/node/node_api.h \
  /Users/margret/Library/Caches/node-gyp/14.15.0/include/node/js_native_api.h \
  /Users/margret/Library/Caches/node-gyp/14.15.0/include/node/js_native_api_types.h \
  /Users/margret/Library/Caches/node-gyp/14.15.0/include/node/node_api_types.h \
  /Users/margret/TriMesh4Js/node_modules/node-addon-api/napi-inl.h \
  /Users/margret/TriMesh4Js/node_modules/node-addon-api/napi-inl.deprecated.h \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/MeshIO.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/System/config.h \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/System/compiler.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/System/OpenMeshDLLMacros.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/SR_store.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/SR_types.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/SR_rbo.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/System/omstream.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/System/mostream.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/GenProg.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/SR_binary.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/SR_binary_spec.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Geometry/VectorT.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Geometry/Vector11T.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/Status.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/SR_binary_vector_of_fundamentals.inl \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/SR_binary_vector_of_string.inl \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/SR_binary_vector_of_bool.inl \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/StoreRestore.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/IOManager.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/Options.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/reader/BaseReader.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/importer/BaseImporter.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/BaseKernel.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/PropertyContainer.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/Property.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/Handles.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/BaseProperty.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/typename.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/SingletonT.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/SingletonT_impl.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/writer/BaseWriter.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/exporter/BaseExporter.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/importer/ImporterT.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/vector_cast.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/vector_traits.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/color_cast.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/Attributes.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/exporter/ExporterT.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/OMFormat.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/Endian.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/OMFormatT_impl.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/TriConnectivity.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/PolyConnectivity.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/ArrayKernel.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/ArrayItems.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/ArrayKernelT_impl.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/SmartRange.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/PolyConnectivity_inline_impl.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/IteratorsT.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/SmartHandles.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/CirculatorsT.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/Traits.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/FinalMeshItemsT.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/AttribKernelT.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/TriMeshT.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/PolyMeshT.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Geometry/MathDefs.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/Tags.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/PolyMeshT_impl.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Geometry/LoopSchemeMaskT.hh \
  /usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/TriMeshT_impl.hh
../myRealMesh.cc:
../myRealMesh.h:
/Users/margret/TriMesh4Js/node_modules/node-addon-api/napi.h:
/Users/margret/Library/Caches/node-gyp/14.15.0/include/node/node_api.h:
/Users/margret/Library/Caches/node-gyp/14.15.0/include/node/js_native_api.h:
/Users/margret/Library/Caches/node-gyp/14.15.0/include/node/js_native_api_types.h:
/Users/margret/Library/Caches/node-gyp/14.15.0/include/node/node_api_types.h:
/Users/margret/TriMesh4Js/node_modules/node-addon-api/napi-inl.h:
/Users/margret/TriMesh4Js/node_modules/node-addon-api/napi-inl.deprecated.h:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/MeshIO.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/System/config.h:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/System/compiler.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/System/OpenMeshDLLMacros.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/SR_store.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/SR_types.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/SR_rbo.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/System/omstream.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/System/mostream.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/GenProg.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/SR_binary.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/SR_binary_spec.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Geometry/VectorT.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Geometry/Vector11T.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/Status.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/SR_binary_vector_of_fundamentals.inl:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/SR_binary_vector_of_string.inl:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/SR_binary_vector_of_bool.inl:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/StoreRestore.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/IOManager.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/Options.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/reader/BaseReader.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/importer/BaseImporter.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/BaseKernel.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/PropertyContainer.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/Property.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/Handles.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/BaseProperty.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/typename.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/SingletonT.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/SingletonT_impl.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/writer/BaseWriter.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/exporter/BaseExporter.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/importer/ImporterT.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/vector_cast.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/vector_traits.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/color_cast.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/Attributes.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/exporter/ExporterT.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/OMFormat.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Utils/Endian.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/IO/OMFormatT_impl.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/TriConnectivity.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/PolyConnectivity.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/ArrayKernel.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/ArrayItems.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/ArrayKernelT_impl.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/SmartRange.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/PolyConnectivity_inline_impl.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/IteratorsT.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/SmartHandles.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/CirculatorsT.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/Traits.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/FinalMeshItemsT.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/AttribKernelT.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/TriMeshT.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/PolyMeshT.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Geometry/MathDefs.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/Tags.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/PolyMeshT_impl.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Geometry/LoopSchemeMaskT.hh:
/usr/local/Cellar/open-mesh/8.1/include/OpenMesh/Core/Mesh/TriMeshT_impl.hh:
