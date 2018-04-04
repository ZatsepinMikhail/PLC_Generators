//
// Created by user on 04/04/2018.
//

#include "FibonacciGenerator.h"

CFibonacciGenerator::CFibIterator::CFibIterator( int id, int previousNumber, int number ) :
    id( id ),
    previousNumber( previousNumber ),
    number( number )
{
}

bool CFibonacciGenerator::CFibIterator::operator==( const CFibIterator& other ) const
{
    return id == other.id;
}

bool CFibonacciGenerator::CFibIterator::operator!=( const CFibIterator& other ) const
{
    return !( *this == other );
}

CFibonacciGenerator::CFibIterator& CFibonacciGenerator::CFibIterator::operator++()
{
    id++;
    int tmp = previousNumber;
    previousNumber = number;
    number += tmp;
    return *this;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CFibonacciGenerator::CFibonacciGenerator( int numberCount ) :
    numberCount( numberCount )
{
}
