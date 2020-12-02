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
let vert_idx = [0, 1, 2, 3, 4, 5, 6, 7]
console.log("Js make a tri mesh: mesh")
let mesh = new addon.MyMesh()
let vert = []
vert.push(mesh.addVertex(1, 2, 0))
vert.push(mesh.addVertex(1, 0, 0))
vert.push(mesh.addVertex(-1, 0.5, 0))
vert.push(mesh.addVertex(4, 3, 0))
vert.push(mesh.addVertex(3, 5, 0))
vert.push(mesh.addVertex(4, 0, 0))
vert.push(mesh.addVertex(7, 2, 0))

console.log("Js add 2 Faces By Id : {0,1,2};{2,4,3} ")
mesh.addFaceById(0, 1, 2)
mesh.addFaceById(2, 4, 3)

console.log("Js current num of faces in mesh :   ", mesh.getNumFace()) // 2

console.log("-------------------------------------------------------")

console.log("Js change vertex id=6 into (4.9,-0.9,0) in mesh2 :   ")
mesh.setPointById(2, [-1.9, 0.49, 0])

console.log("Js make another tri mesh: mesh2")
let mesh2 = new addon.MyMesh()
let vert2 = []
vert2.push(mesh2.addVertex(1, 2, 0))
vert2.push(mesh2.addVertex(1, 0, 0))
vert2.push(mesh2.addVertex(-1, 1, 0))
vert2.push(mesh2.addVertex(3, 5, 0))
vert2.push(mesh2.addVertex(4, 0, 0))
vert2.push(mesh2.addVertex(2, -1, 0))
vert2.push(mesh2.addVertex(-1, -1, 0))

mesh2.addFace(vert2[0], vert2[2], vert2[1])
mesh2.addFace(vert2[0], vert2[3], vert2[2])
mesh2.addFace(vert2[0], vert2[4], vert2[3])
mesh2.addFace(vert2[0], vert2[1], vert2[4])
mesh2.addFace(vert2[5], vert2[4], vert2[1])
console.log("Js current num of faces in mesh2 :   ", mesh2.getNumFace()) // 2
mesh2.setPoint(vert2[5], [9, 2.9, 1])

let getPointsFromMesh2 = mesh2.points()
console.log("neighbor vert-5 [2,-1,0] : ", mesh2.vv(vert2[5]))
console.log("BFS vert-1:", mesh2.bFSNeighWeights(vert2[1]))

console.log("#Of Points in Mesh2: ", getPointsFromMesh2.length)
