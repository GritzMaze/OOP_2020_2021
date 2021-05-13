#pragma once
#include "Coin.h"

class AmericanCoin : public Coin
{

public:
    AmericanCoin();
    AmericanCoin(const side &, const char *, const double &);
    AmericanCoin(const AmericanCoin &);

    AmericanCoin &operator=(const AmericanCoin &);
    AmericanCoin &operator=(const double &);

        void flip();
    void convertFromBulgarian(const double &);
    void convertFromGerman(const double &);
    void convertFromBoth(const double &, const double &);
};