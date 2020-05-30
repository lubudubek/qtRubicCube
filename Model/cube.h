#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include <memory>

class Cubic;


class Cube
{
public:
    Cube();
    void addCubic(std::shared_ptr<Cubic> cubic);
private:
    std::vector<std::shared_ptr<Cubic>> cubics;
};

#endif // CUBE_H
