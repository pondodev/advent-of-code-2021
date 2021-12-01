#include <iostream>
#include <fstream>
#include <string>

const std::string INPUT_FILE_NAME = "input.txt";

int main() {
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

    printf("count: %d\n", count);

    f.close();

    return 0;
}

