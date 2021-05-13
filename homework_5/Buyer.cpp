#include "Buyer.h"

Buyer::Buyer()
{
    this->acoin = 0;
    this->gcoin = 0;
    this->bcoin = 0;
}

Buyer::Buyer(const AmericanCoin &_acoin, const BulgarianCoin &_bcoin, const GermanCoin &_gcoin) : acoin(_acoin), bcoin(_bcoin), gcoin(_gcoin) {}

void Buyer::incrementAmerican()
{
    acoin++;
}

void Buyer::incrementBulgarian()
{
    bcoin++;
}

void Buyer::incrementGerman()
{
    gcoin++;
}

void Buyer::buy(const Product &prod)
{
    double price = prod.getPrice();
    double discountedPrice = price - (price * prod.getDiscount() / 100);
    int drawCoin = 0;
    srand(time(NULL));
    drawCoin = rand() % 3 + 1;
    if (drawCoin == 1)
    {
        acoin.flip();
        (acoin.getFace() == prod.getFace() ? payWithA(acoin, discountedPrice, prod) : this->payWithA(acoin, price, prod));
    }
    else if (drawCoin == 2)
    {
        bcoin.flip();
        (bcoin.getFace() == prod.getFace() ? this->payWithB(bcoin, discountedPrice, prod) : this->payWithB(bcoin, price, prod));
    }

    else
    {
        gcoin.flip();
        (gcoin.getFace() == prod.getFace() ? this->payWithG(gcoin, discountedPrice, prod) : this->payWithG(gcoin, price, prod));
    }
}

void Buyer::payWithA(AmericanCoin &acoin, const double &price, const Product &prod)
{
    acoin.convertFromBoth(bcoin.getValue(), gcoin.getValue());
    if (acoin.getValue() < price)
    {
        std::cout << "Not enough money! \n";
        return;
    }
    else
    {
        std::cout << "Succesufuly bought with AmericanCoin! \n";
        products.pushBack(prod);
        acoin.setValue(acoin.getValue() - price);
    }
}

void Buyer::payWithB(BulgarianCoin &acoin, const double &price, const Product &prod)
{
    bcoin.convertFromBoth(acoin.getValue(), gcoin.getValue());
    if (bcoin.getValue() < price)
    {
        std::cout << "Not enough money! \n";
        return;
    }
    else
    {
        std::cout << "Succesufuly bought with BulgarianCoin! \n";
        products.pushBack(prod);
        bcoin.setValue(bcoin.getValue() - price);
    }
}

void Buyer::payWithG(GermanCoin &acoin, const double &price, const Product &prod)
{
    gcoin.convertFromBoth(acoin.getValue(), bcoin.getValue());
    if (gcoin.getValue() < price)
    {
        std::cout << "Not enough money! \n";
        return;
    }
    else
    {
        std::cout << "Succesufuly bought with GermanCoin! \n";
        products.pushBack(prod);
        gcoin.setValue(gcoin.getValue() - price);
    }
}

const void Buyer::print() const {
    std::cout << products;
}

