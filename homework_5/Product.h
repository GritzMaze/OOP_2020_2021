#pragma once
#include "AmericanCoin.h"
#include "BulgarianCoin.h"
#include "GermanCoin.h"
#include "Coin.h"
#include "String.h"

class Product {
    private:
    String name;
    double price;
    int discount;
    side face;

    public:
    Product();
    Product(const String&, const double&, const int&);
    const side getFace() const;
    const double& getPrice() const;
    const int& getDiscount() const;

    friend std::ostream& operator<<(std::ostream&, const Product&);
};