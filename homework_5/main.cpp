#include <iostream>
#include "Product.h"
#include "Buyer.h"

int main() {
    AmericanCoin acoin;
    BulgarianCoin bcoin;
    GermanCoin gcoin;
    acoin = 50;
    bcoin = 20;
    gcoin = 80;
    Buyer Pesho(acoin, bcoin, gcoin);
    Product prod1("Chanta", 25, 10);
    Product prod2("Chanta2", 40, 5);
    Product prod3("Chanta3", 5, 20);
    Product prod4("Chanta4", 6, 26);
    Pesho.buy(prod1);
    Pesho.buy(prod2);
    Pesho.buy(prod3);
    Pesho.buy(prod4);
    Pesho.print();

    return 0;
}