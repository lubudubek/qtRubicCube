#include "cubefactory.h"
#include "cube.h"
#include "cubic.h"

CubeFactory::CubeFactory()
{

}

std::unique_ptr<Cube> CubeFactory::createCube()
{
    auto cubePtr = std::make_unique<Cube>();
    cubePtr->addCubic(makeCubic());
    return cubePtr;
}

std::array<VertexData, 24>&& CubeFactory::createDefaultCubicVerts()
{
    std::array<VertexData, 24> vertices = {
        // Vertex data for face 0

        // Vertex data for face 1
        VertexData{
         QVector3D( 1.0f, -1.0f,  1.0f), QVector4D(1.0f, 0.0f, 0.0f, 1.0f), 1.0f}, // v4
        {QVector3D( 1.0f, -1.0f, -1.0f), QVector4D(1.0f, 0.0f, 0.0f, 1.0f), 1.0f}, // v5
        {QVector3D( 1.0f,  1.0f,  1.0f), QVector4D(1.0f, 0.0f, 0.0f, 1.0f), 1.0f}, // v6
        {QVector3D( 1.0f,  1.0f, -1.0f), QVector4D(1.0f, 0.0f, 0.0f, 1.0f), 1.0f}, // v7

        // Vertex data for face 2
        {QVector3D( 1.0f, -1.0f, -1.0f), QVector4D(1.0f, 1.0f, 0.0f, 1.0f), 1.0f}, // v8
        {QVector3D(-1.0f, -1.0f, -1.0f), QVector4D(1.0f, 1.0f, 0.0f, 1.0f), 1.0f}, // v9
        {QVector3D( 1.0f,  1.0f, -1.0f), QVector4D(1.0f, 1.0f, 0.0f, 1.0f), 1.0f}, // v10
        {QVector3D(-1.0f,  1.0f, -1.0f), QVector4D(1.0f, 1.0f, 0.0f, 1.0f), 1.0f}, // v11

        // Vertex data for face 3
        {QVector3D(-1.0f, -1.0f, -1.0f), QVector4D(1.0f, 0.0f, 0.0f, 1.0f), 1.0f}, // v12
        {QVector3D(-1.0f, -1.0f,  1.0f), QVector4D(1.0f, 0.0f, 0.0f, 1.0f), 1.0f}, // v13
        {QVector3D(-1.0f,  1.0f, -1.0f), QVector4D(1.0f, 0.0f, 0.0f, 1.0f), 1.0f}, // v14
        {QVector3D(-1.0f,  1.0f,  1.0f), QVector4D(1.0f, 0.0f, 0.0f, 1.0f), 1.0f}, // v15

        // Vertex data for face 4
        {QVector3D(-1.0f, -1.0f, -1.0f), QVector4D(1.0f, 0.0f, 0.0f, 1.0f), 1.0f}, // v16
        {QVector3D( 1.0f, -1.0f, -1.0f), QVector4D(1.0f, 0.0f, 0.0f, 1.0f), 1.0f}, // v17
        {QVector3D(-1.0f, -1.0f,  1.0f), QVector4D(1.0f, 0.0f, 0.0f, 1.0f), 1.0f}, // v18
        {QVector3D( 1.0f, -1.0f,  1.0f), QVector4D(1.0f, 0.0f, 0.0f, 1.0f), 1.0f}, // v19

        // Vertex data for face 5
        {QVector3D(-1.0f,  1.0f,  1.0f), QVector4D(1.0f, 0.0f, 0.0f, 1.0f), 1.0f}, // v20
        {QVector3D( 1.0f,  1.0f,  1.0f), QVector4D(1.0f, 0.0f, 0.0f, 1.0f), 1.0f}, // v21
        {QVector3D(-1.0f,  1.0f, -1.0f), QVector4D(1.0f, 0.0f, 0.0f, 1.0f), 1.0f}, // v22
        {QVector3D( 1.0f,  1.0f, -1.0f), QVector4D(1.0f, 0.0f, 0.0f, 1.0f), 1.0f},  // v23

        {QVector3D(-1.0f, -1.0f,  1.0f), QVector4D(1.0f, 0.0f, 1.0f, 1.0f), 1.0f},  // v0
        {QVector3D( 1.0f, -1.0f,  1.0f), QVector4D(1.0f, 0.0f, 1.0f, 1.0f), 1.0f}, // v1
        {QVector3D(-1.0f,  1.0f,  1.0f), QVector4D(1.0f, 0.0f, 1.0f, 1.0f), 1.0f},  // v2
        {QVector3D( 1.0f,  1.0f,  1.0f), QVector4D(1.0f, 0.0f, 1.0f, 1.0f), 1.0f} // v3

    };

    return std::move(vertices);
}

std::array<VertexData, 24>&& CubeFactory::createInsideVerts()
{
    std::array<VertexData, 24> vertices = createDefaultCubicVerts();
    std::for_each(vertices.begin(), vertices.end(), [](auto& vert){vert.position[0] *= 0.8;
                                                                   vert.position[1] *= 0.8;});

    return std::move(vertices);
}

std::shared_ptr<Cubic> CubeFactory::makeCubic()
{
    std::array<VertexData, 24> redCubicVerts = createDefaultCubicVerts();

    std::array<GLushort, 34> indices = {
         0,  1,  2,  3,  3,     // Face 0 - triangle strip ( v0,  v1,  v2,  v3)
         4,  4,  5,  6,  7,  7, // Face 1 - triangle strip ( v4,  v5,  v6,  v7)
         8,  8,  9, 10, 11, 11, // Face 2 - triangle strip ( v8,  v9, v10, v11)
        12, 12, 13, 14, 15, 15, // Face 3 - triangle strip (v12, v13, v14, v15)
        16, 16, 17, 18, 19, 19, // Face 4 - triangle strip (v16, v17, v18, v19)
        20, 20, 21, 22, 23      // Face 5 - triangle strip (v20, v21, v22, v23)
    };

    QMatrix4x4 initMatrix;
    initMatrix.translate(0.0f, 0.0f,  2.0f);

    auto cubicPtr = std::make_shared<Cubic>(std::move(redCubicVerts), move(indices), std::move(initMatrix));
    return cubicPtr;
}
