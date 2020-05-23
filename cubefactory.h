#ifndef CUBEFACTORY_H
#define CUBEFACTORY_H

#include <memory>

class Cube;
class Cubic;

class CubeFactory
{
public:
    CubeFactory();
    std::unique_ptr<Cube> createCube();
private:
    std::shared_ptr<Cubic> makeCubic();
};

#endif // CUBEFACTORY_H
