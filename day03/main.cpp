#include "helpers.hpp"

#include <iostream>
#include <string>

const std::string INPUT_FILE_NAME = "input.txt";

void part1();
void part2();

uint16_t power( uint16_t value, uint16_t exponent );

int main() {
    part1();
    printf("\n----\n\n");
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
    // store the weight of each place--+1 for a 1, -1 for a 0
    int weights[ 12 ] = { 0 };

    // we actually want the output this time!
    auto oxygen_pool = Helpers::parse_file<uint16_t>( INPUT_FILE_NAME,
    [&weights]( std::string line ) {
        uint16_t to_return = 0;

        for ( size_t i = 0; i < 12; ++i ) {
            switch ( line.at( i ) ) {
                case '1':
                    ++weights[ i ];
                    to_return += power( 2, 11 - i );
                    break;

                case '0':
                    --weights[ i ];
                    break;
            }
        }

        return to_return;
    } );

    auto co2_pool = oxygen_pool;

    // find oxygen generator rating
    for ( size_t i = 0; i < 12; ++i ) {
        uint16_t mask = 0b1 << 11 - i;
        auto it = oxygen_pool.begin();
        while ( it != oxygen_pool.end() ) {
            bool has_1 = *it & mask; // check if there's a 1 in this spot
            bool want_1 = weights[ i ] >= 0; // check if we're looking for a 1

            if ( want_1 == has_1 ) it = oxygen_pool.erase( it );
            else ++it;
        }

        if ( oxygen_pool.size() == 1 ) break; // we have our value
    }

    if ( oxygen_pool.size() == 1 ) printf( "found oxygen value!\n" );
    else printf( "there are %d oxygen values left\n", oxygen_pool.size() );

    // find co2 scrubber rating
    for ( size_t i = 0; i < 12; ++i ) {
        uint16_t mask = 0b1 << 11 - i;
        auto it = co2_pool.begin();
        while ( it != co2_pool.end() ) {
            bool has_1 = *it & mask; // check if there's a 1 in this spot
            bool want_1 = weights[ i ] <= 0; // check if we're looking for a 1

            if ( want_1 == has_1 ) it = co2_pool.erase( it );
            else ++it;
        }

        if ( co2_pool.size() == 1 ) break; // we have our value
    }

    if ( co2_pool.size() == 1 ) printf( "found co2 value!\n" );
    else printf( "there are %d co2 values left\n", co2_pool.size() );

    printf( "oxygen: %d co2: %d\n", oxygen_pool[ 0 ], co2_pool[ 0 ] );
    printf( "part 2: %d\n", oxygen_pool[ 0 ] * co2_pool[ 0 ] );
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
