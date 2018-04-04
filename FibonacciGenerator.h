//
// Created by user on 04/04/2018.
//

#ifndef GENERATORS_C_FIBONACCIGENERATOR_H
#define GENERATORS_C_FIBONACCIGENERATOR_H

class CFibonacciGenerator {
public:

    class CFibIterator {
    public:
        int operator*() const { return number; }

        bool operator==( const CFibIterator& other ) const;
        bool operator!=( const CFibIterator& other ) const;

        CFibIterator& operator++();

    private:

        explicit CFibIterator( int id, int previousNumber, int number );
        int id;
        int previousNumber;
        int number;

        friend class CFibonacciGenerator;
    };

    explicit CFibonacciGenerator( int numberCount );

    CFibIterator begin() { return CFibIterator( 1, 0, 1 ); }
    CFibIterator end() { return CFibIterator( numberCount + 1, -1, -1 ); }

private:
    int numberCount;
};

#endif //GENERATORS_C_FIBONACCIGENERATOR_H
