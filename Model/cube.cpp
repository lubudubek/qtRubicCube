#include "cube.h"

Cube::Cube()
{

}

void Cube::addCubic(std::shared_ptr<Cubic> cubic)
{
    cubics.push_back(cubic);
}
