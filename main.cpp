#include <iostream>

#include "FibonacciGenerator.h"
#include "Tokenizer.h"

int main( int argc, char* argv[] ) {

    for( auto number : CFibonacciGenerator( 20 ) ) {
        std::cout << number << " ";
    }
    std::cout << "\n\n";


    if( argc > 1 ) {

        CTokenizer tokenizer( argv[1], new CTokenCapitalizer() );
        for( auto token : tokenizer ) {
            std::cout << token << "\n";
        }
    }
    return 0;
}
