//
// Created by user on 04/04/2018.
//

#ifndef GENERATORS_C_TOKENIZER_H
#define GENERATORS_C_TOKENIZER_H

#include <fstream>
#include <memory>
#include <string>

class ITokenCallback {
public:
    virtual std::string operator()( std::string ) = 0;
};

class CTokenCapitalizer : public ITokenCallback {
public:
    std::string operator()( std::string token ) override;
};

class CTokenizer {
public:
    class CTokenIterator {
    public:
        std::string operator*() const { return token; }

        bool operator==( const CTokenIterator &other ) const;
        bool operator!=( const CTokenIterator &other ) const;

        CTokenIterator &operator++();

    private:
        std::string token;
        CTokenizer &tokenizer;

        explicit CTokenIterator( CTokenizer &tokenizer, std::string token );

        friend class CTokenizer;
    };

    explicit CTokenizer( const std::string& filename, ITokenCallback* callback );
    CTokenIterator begin() { return CTokenIterator( *this, getNextToken() ); }
    CTokenIterator end() { return CTokenIterator( *this, std::string() ); }

private:
    std::ifstream fin;
    std::unique_ptr<ITokenCallback> callback;

    std::string getNextToken();

    friend class CTokenIterator;
};

#endif //GENERATORS_C_TOKENIZER_H
