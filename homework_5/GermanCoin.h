#pragma once
#include "Coin.h"

class GermanCoin : public Coin
{

public:
    GermanCoin();
    GermanCoin(const side &, const char *, const double &);
    GermanCoin(const GermanCoin &);

    GermanCoin &operator=(const GermanCoin &);
    GermanCoin &operator=(const double &);

        void flip();
    void convertFromAmerican(const double &);
    void convertFromBulgarian(const double &);
    void convertFromBoth(const double &value, const double &value2);
};