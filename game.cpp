#include "game.h"
#include "cubefactory.h"

Game::Game()
{
    CubeFactory cubeFactory;
    m_cube = cubeFactory.createCube();
}
