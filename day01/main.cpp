#include "helpers.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

const std::string INPUT_FILE_NAME = "input.txt";

void part1();
void part2();

int main() {
    part1();
    part2();

    return 0;
}

void part1() {
    std::vector<int> values = Helpers::parse_file<int>( INPUT_FILE_NAME,
        [](std::string line) {
            return std::stoi( line );
        } );

    size_t count = 0;

    for ( size_t i = 1; i < values.size(); ++i )
        if ( values[ i ] > values[ i - 1 ] ) ++count;

    printf( "part 1 count: %d\n", count );
}

void part2() {
    std::vector<int> values = Helpers::parse_file<int>( INPUT_FILE_NAME,
        [](std::string line) {
            return std::stoi( line );
        } );

    auto last_sum = values[ 0 ] + values[ 1 ] + values[ 2 ];
    size_t count = 0;

    for ( size_t i = 1; i < values.size() - 2; ++i ) {
        auto sum = values[ i ] + values[ i + 1 ] + values[ i + 2 ];

        if ( sum > last_sum ) ++count;
        last_sum = sum;
    }

    printf( "part 2 count: %d\n", count );
}
