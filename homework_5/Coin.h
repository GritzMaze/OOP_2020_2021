#pragma once
#include <iostream>
#include <cstring>
#include <time.h>

enum side
{
    HEADS,
    TAILS
};

class Coin {
    protected:
    side face;
    char* nationality;
    double value;

    private:
    void copy(const Coin&);
    void erase();

    public:
    Coin();
    Coin(const side&, const char*, const double&);
    Coin(const Coin&);
    ~Coin();
    Coin& operator=(const Coin&);
   // Coin& operator=(const double&);
    Coin& operator++();
    Coin operator++(int);
    void flip();
    static side flipr();
    const side getFace() const;
    const int getValue() const;
    void setValue(const double&);
    const void print() const;


};