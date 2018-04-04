//
// Created by user on 04/04/2018.
//

#include "Tokenizer.h"

std::string CTokenCapitalizer::operator()( std::string token )
{
    std::transform( token.begin(), token.end(), token.begin(), ::toupper);
    return token;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CTokenizer::CTokenizer( const std::string& filename, ITokenCallback* callback ) :
    callback( callback ),
    fin( filename )
{
}

std::string CTokenizer::getNextToken()
{
    std::string newToken;
    fin >> newToken;
    return ( *callback )( newToken );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CTokenizer::CTokenIterator::CTokenIterator( CTokenizer &tokenizer, std::string token ) :
    tokenizer(tokenizer),
    token(std::move(token))
{
}

bool CTokenizer::CTokenIterator::operator==( const CTokenIterator &other ) const
{
    return token == other.token;
}

bool CTokenizer::CTokenIterator::operator!=( const CTokenIterator &other ) const
{
    return !(*this == other);
}

CTokenizer::CTokenIterator& CTokenizer::CTokenIterator::operator++()
{
    token = tokenizer.getNextToken();
    return *this;
}
