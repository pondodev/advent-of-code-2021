#include "helpers.hpp"
#include "types.hpp"

#include <iostream>
#include <string>
#include <sstream>

const std::string INPUT_FILE_NAME = "input.txt";

void part1();
void part2();

int main() {
    part1();
    part2();

    return 0;
}

void part1() {
    auto instructions = Helpers::parse_file<Instruction>( INPUT_FILE_NAME,
    []( std::string line ) {
        std::stringstream ss( line );
        std::string dir;
        std::string dist;

        ss >> dir;
        ss >> dist;

        Instruction to_return;

        if ( dir == "up" )
            to_return.direction = Direction::Up;
        else if ( dir == "down" )
            to_return.direction = Direction::Down;
        else if ( dir == "forward" )
            to_return.direction = Direction::Forward;

        to_return.distance = std::stoi( dist );

        return to_return;
    } );

    Position pos;
    for ( auto i : instructions ) {
        switch ( i.direction ) {
            case Direction::Up:
                pos.depth -= i.distance;
                break;

            case Direction::Down:
                pos.depth += i.distance;
                break;

            case Direction::Forward:
                pos.horizontal += i.distance;
                break;
        }
    }

    printf( "depth: %d horizontal: %d\n", pos.depth, pos.horizontal );
    printf( "part 1 answer: %d\n", pos.depth * pos.horizontal );
}

void part2() {
    // TODO: solve!
}
