#pragma once
#include "Product.h"
#include "Vector.h"

class Buyer {
    private:
    AmericanCoin acoin;
    BulgarianCoin bcoin;
    GermanCoin gcoin;
    Vector<Product> products;

    public:
    Buyer();
    Buyer(const AmericanCoin&, const BulgarianCoin&, const GermanCoin&);
    void incrementAmerican();
    void incrementBulgarian();
    void incrementGerman();

    void buy(const Product&);
    void payWithA(AmericanCoin &, const double &, const Product&);
    void payWithB(BulgarianCoin &, const double &, const Product&);
    void payWithG(GermanCoin &, const double &, const Product&);

    const void print() const;
};

