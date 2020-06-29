#ifndef CUBEFACTORY_H
#define CUBEFACTORY_H

#include <memory>

class Cube;
class Cubic;
class VertexData;

class CubeFactory
{
public:
    CubeFactory();
    std::unique_ptr<Cube> createCube();
private:
    std::shared_ptr<Cubic> makeCubic();
    std::array<VertexData, 24>&& createDefaultCubicVerts();
    std::array<VertexData, 24>&& createInsideVerts();
};

#endif // CUBEFACTORY_H
