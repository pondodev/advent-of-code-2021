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
    std::ifstream f;
    f.open( INPUT_FILE_NAME );

    std::string line;
    size_t count = 0;

    std::getline( f, line );
    auto last_val = std::stoi( line );

    while ( std::getline( f, line ) ) {
        auto val = std::stoi( line );

        if ( val > last_val ) ++count;
        last_val = val;
    }

    printf( "part 1 count: %d\n", count );

    f.close();
}

void part2() {
    std::ifstream f;
    f.open( INPUT_FILE_NAME );

    std::vector<int> values;
    std::string line;
    size_t count = 0;

    while ( std::getline( f, line ) )
        values.push_back( std::stoi( line ) );

    auto last_sum = values[ 0 ] + values[ 1 ] + values[ 2 ];

    for ( size_t i = 1; i < values.size() - 2; ++i ) {
        auto sum = values[ i ] + values[ i + 1 ] + values[ i + 2 ];

        if ( sum > last_sum ) ++count;
        last_sum = sum;
    }

    printf( "part 2 count: %d\n", count );

    f.close();
}
