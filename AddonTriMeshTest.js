var addon = require("bindings")("addon-trimesh")
let points = [
  [1, 2, 0],
  [1, 0, 0],
  [-1, 0.5, 0],
  [4, 3, 0],
  [3, 5, 0],
  [4, 0, 0],
  [7, 2, 0],
]
// let vert_idx = [0, 1, 2, 3, 4, 5, 6,7 ];
// console.log("Js make a tri mesh: mesh");
// let mesh = new addon.MyMesh();
// let vert = [];
// vert.push(mesh.addVertex(1, 2, 0));
// vert.push(mesh.addVertex(1, 0, 0));
// vert.push(mesh.addVertex(-1, 0.5, 0));
// vert.push(mesh.addVertex(4, 3, 0));
// vert.push(mesh.addVertex(3, 5, 0));
// vert.push(mesh.addVertex(4, 0, 0));
// vert.push(mesh.addVertex(7, 2, 0));
// // console.log("final vertex idx", vert[6]); //
// // console.log("Js first 3 points", vert[0], vert[1], vert[2]); //

// console.log("Js add2FaceById : {0,1,2};{2,4,3} ", 0, 1, 2);
// mesh.addFaceById(0, 1, 2);
// mesh.addFaceById(2, 4, 3);

// console.log("Js current num of faces in mesh :   ", mesh.getNumFace()); // 2

// console.log("Js change vertex id=6 into (4.9,-0.9,0) in mesh2 :   ");
// mesh.setPoint(2, [-1.9, 0.49, 0]);

console.log("Js make another tri mesh: mesh2")
let mesh2 = new addon.MyMesh()
// console.log("typeof : ", typeof mesh2)
let vert2 = []
vert2.push(mesh2.addVertex(1, 2, 0))
// console.log(temp); // 0
vert2.push(mesh2.addVertex(1, 0, 0))
vert2.push(mesh2.addVertex(-1, 0.5, 0))
vert2.push(mesh2.addVertex(3, 5, 0))
vert2.push(mesh2.addVertex(4, 0, 0))
vert2.push(mesh2.addVertex(7, 2, 0))
// console.log(mesh2.getNumFace()) // 5
// console.log("Js first 3 points of mesh2 (ref)", vert2[0], vert2[1], vert2[2]) //
// console.log("Js addFaceByRef : vert2[0,1,2]")
mesh2.addFace(vert2[0], vert2[1], vert2[2])
// console.log("Js add 2 more Face By Ref")
mesh2.addFace(vert2[2], vert2[4], vert2[3])
mesh2.addFace(vert2[3], vert2[4], vert2[5])

// console.log("Js current num of faces in mesh2 :   ", mesh2.getNumFace()) // 2
// mesh2.setPoint(vert2[5], [9, 2.9, 1])

vert = []
let getPointsFromMesh = mesh2.points()
// console.log("getPointsFromMesh: ", getPointsFromMesh)
console.log(mesh2.vv(vert2[3]))
// console.log("size: ", getPointsFromMesh.length())
