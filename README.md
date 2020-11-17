# TriMesh4Js

OpenMesh binding via node-addon-napi

Node.js wrapper for [OpenMesh](https://www.graphics.rwth-aachen.de:9000/OpenMesh/OpenMesh) C++ library using [node-addon-api](https://github.com/nodejs/node-addon-api).

TriMesh-js is a Node.js addon, written in C++, that can be loaded into Node.js using the require() function, and used just as if they were an ordinary Node.js module.

The aim of the project is to provide a FFI between JavaScript running in Node.js and OpenMesh C++ library.

## Prerequisites

Before starting to use MAVJS you need to assure you have the following prerequisites:

- **Node.js**: see [download and install Node.js](https://nodejs.org/en/download/) Node.js 14.0 or higher is required.
- **node-gyp**: see [node-gyp](https://github.com/nodejs/node-gyp)
  > Another Option is Cmake to use [CMake.js](https://github.com/cmake-js/cmake-js) to build the addon
- **CMake**: see [CMake download](https://cmake.org/download/)
- A proper C/C++ compiler tool: For Mac OS, can be Clang/GCC or CMake/make
- **OpenMesh** **C++**: see guide [compiling OpenMesh](https://www.graphics.rwth-aachen.de/media/openmesh_static/Documentations/OpenMesh-7.0-Documentation/a03933.html)
  or you can easily install via brew `brew install open-mesh`

## Installation

## Getting started

## Examples

To view the examples, check AddonTriMeshTest.js

## Project Status

Plugins implementation - TriMesh:

- [x] Init a TriMesh
- [x] Add Vertex
- [x] Add Face By Vertex Id
- [x] Set Point By Vertex Id
- [x] Add Face
- [ ] Set Point
- [ ] Get Points
- [ ] More Pending ...

## Tests

There is a basic test file under /test folder using [mocha](https://mochajs.org) with assert.

## License
