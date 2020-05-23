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

std::shared_ptr<Cubic> CubeFactory::makeCubic()
{
    auto cubicPtr = std::make_shared<Cubic>();
    return cubicPtr;
}
