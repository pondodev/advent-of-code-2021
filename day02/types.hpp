#ifndef TYPES_HPP
#define TYPES_HPP

#include <cstdlib>

enum class Direction { Up, Down, Forward };

struct Instruction {
    Direction   direction;
    size_t      distance;
};

struct Position {
    int depth       = 0;
    int horizontal  = 0;
    int aim         = 0;
};

#endif
