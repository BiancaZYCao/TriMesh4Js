/* This is a simple test file for current bindings.*/
const assert = require("assert")
let addon = require("bindings")("addon-trimesh")

let points = [
  [0, 1, 0],
  [1, 0, 0],
  [2, 1, 0],
  [0, -1, 0],
  [2, -1, 0],
]

describe("TriMesh Setup", function () {
  let mesh = new addon.MyMesh()
  describe("Init a TriMesh", function () {
    it("should return an Object", function () {
      assert(typeof mesh, "object")
    })
  })
  //add some vertices
  let vhandle = []
  vhandle.push(mesh.addVertex(0, 1, 0))
  vhandle.push(mesh.addVertex(1, 0, 0))
  vhandle.push(mesh.addVertex(2, 1, 0))
  vhandle.push(mesh.addVertex(0, -1, 0))
  vhandle.push(mesh.addVertex(2, -1, 0))
  describe("add vertices", function () {
    it("should return # of vertices added to mesh", function () {
      let points = mesh.points()
      assert.strictEqual(points.length, 5)
    })
  })
  //add some face
  mesh.addFace(vhandle[0], vhandle[1], vhandle[2])
  mesh.addFace(vhandle[1], vhandle[3], vhandle[4])
  mesh.addFace(vhandle[0], vhandle[3], vhandle[1])
  mesh.addFace(vhandle[2], vhandle[1], vhandle[4])
  /*     Test setup:
  //       0-----------2
  //       | \       / |
  //       |   \   /   |
  //       |     1     |
  //       |   /   \   |
  //       | /       \ |
  //       3-----------4 */
  describe("add faces", function () {
    it("should return # of faces added to mesh", function () {
      let nFaces = mesh.getNumFace()
      assert.strictEqual(nFaces, 4)
    })
  })

  describe("check points", function () {
    it("should equals to input", function () {
      let pointsFromMesh = mesh.points()
      assert.deepStrictEqual(pointsFromMesh, points)
    })
  })
  describe("update point position", function () {
    it("should equals to newPoint position", function () {
      //     update point:
      //       0-----------2
      //       | \       //
      //       |   \   / /
      //       |     1  /
      //       |   / | /
      //       | /   |/
      //       3-----4     X
      const newPoint = [1, -1, 0]
      mesh.setPoint(vhandle[4], newPoint)
      assert.deepStrictEqual(mesh.points()[4], newPoint)
    })
  })
})
