#include "helpers.hpp"

#include <iostream>
#include <string>

const std::string INPUT_FILE_NAME = "input.txt";

void part1();
void part2();

uint16_t power( uint16_t value, uint16_t exponent );

int main() {
    part1();
    part2();

    return 0;
}

void part1() {
    // store the weight of each place--+1 for a 1, -1 for a 0
    int weights[ 12 ] = { 0 };

    // we don't actually need the output here
    Helpers::parse_file<int>( INPUT_FILE_NAME,
    [&weights]( std::string line ) {
        for ( size_t i = 0; i < 12; ++i ) {
            switch ( line.at( i ) ) {
                case '1':
                    ++weights[ i ];
                    break;

                case '0':
                    --weights[ i ];
                    break;
            }
        }

        return 0;
    } );

    // figure out the gamma rate in binary, decoding from bin to dec on the fly
    uint16_t gamma = 0;
    uint16_t epsilon = 0;
    std::string g, e;
    for ( size_t i = 0; i < 12; ++i ) {
        auto val = power( 2, 11 - i );
        if ( weights[ i ] > 0 ) gamma += val;
        else epsilon += val;
    }

    printf( "gamma: %d epsilon: %d\n", gamma, epsilon );
    printf( "part 1: %d\n", gamma * epsilon );
}

void part2() {
    // TODO: solve!
}

// this is so jank lol
uint16_t power( uint16_t value, uint16_t exponent ) {
    if ( exponent == 0 ) return 1;

    uint16_t to_return = value;
    for ( int i = 0; i < exponent - 1; ++i ) {
        to_return *= value;
    }

    return to_return;
}
