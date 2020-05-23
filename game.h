#ifndef GAME_H
#define GAME_H

#include "cube.h"
#include <memory>

class Game
{
public:
    Game();

private:
    std::unique_ptr<Cube> m_cube;
};

#endif // GAME_H
