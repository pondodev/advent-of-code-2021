#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <vector>
#include <string>
#include <functional>
#include <fstream>

namespace Helpers {
    template<typename T>
    std::vector<T> parse_file( std::string file_name, std::function< T( std::string ) > parser )
    {
        std::ifstream f;
        std::string line;
        std::vector<T> to_return;

        f.open( file_name );

        while ( std::getline( f, line ) )
            to_return.push_back( parser( line ) );

        f.close();

        return to_return;
    }
}

#endif
