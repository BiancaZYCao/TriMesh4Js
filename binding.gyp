{
  "targets": [
    {
      "target_name": "addon-trimesh",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-rtti","-fno-exceptions" ],
      "ldflags": ["-Wl,-rpath,-flat_namespace,'$$ORIGIN'"],
      "sources": [ "addon.cc", "myRealMesh.cc" ],
      "include_dirs": [
        "/usr/local/Cellar/open-mesh/8.1/include",
        "<!@(node -p \"require('node-addon-api').include\")",
      ],
      'link_settings': {
        # 'library_dirs': ['/usr/local/Cellar/open-mesh/8.1/lib/'],
         "libraries": ["-Wl,-rpath,/usr/local/Cellar/open-mesh/8.1/lib"]
      },
      "libraries":[
        "libOpenMeshTools.8.1.dylib",
        "libOpenMeshCore.8.1.dylib"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      "conditions": [
        [
          "OS==\"mac\"", {
            "xcode_settings": {
              "OTHER_CFLAGS": [
                "-mmacosx-version-min=10.7",
                "-std=c++11",
                "-stdlib=libc++"
              ],
              "GCC_ENABLE_CPP_RTTI": "YES",
              "GCC_ENABLE_CPP_EXCEPTIONS": "YES"
            }
          }
        ]
      ]
    }
  ]
}
