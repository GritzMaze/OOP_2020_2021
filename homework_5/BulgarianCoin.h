#pragma once
#include "Coin.h"

class BulgarianCoin : public Coin {

    public:
    BulgarianCoin();
    BulgarianCoin(const side &, const char *, const double&);
    BulgarianCoin(const BulgarianCoin& );

    BulgarianCoin& operator=(const BulgarianCoin&);
    BulgarianCoin &operator=(const double &);

    void flip();
    void convertFromAmerican(const double&);
    void convertFromGerman(const double&);
    void convertFromBoth(const double &, const double &);
};