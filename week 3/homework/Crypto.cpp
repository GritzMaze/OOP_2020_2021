
#include "Crypto.h"

void Crypto::erase() {
    delete [] this->name;
}

Crypto::Crypto()
{
    this->name = new char[6];
    strcpy(this->name, "Empty");
    this->currentPrice = 0;
    this->lastPrice = 0;
}

Crypto::Crypto(char* _name, double _currentPrice, double _lastPrice) {
    this->setName(_name);
    this->setCurrPrice(_currentPrice);
    this->setLastPrice(_lastPrice);
}

Crypto::~Crypto() {
    this->erase();
}

double Crypto::PriceDifference() {
    return ((getCurrPrice() - getLastPrice())*100) / getLastPrice();
}

void Crypto::setName(const char* _name) {
    delete[] this->name;
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
}

void Crypto::setCurrPrice(const double _currentPrice) {
    this->currentPrice = _currentPrice;
}

void Crypto::setLastPrice(const double _lastPrice) {
    this->lastPrice = _lastPrice;
}

const char *Crypto::getName() const {
    return this->name;
}

const double Crypto::getCurrPrice() const {
    return this->currentPrice;
}

const double Crypto::getLastPrice() const {
    return this->lastPrice;
}

const void Crypto::print() const {
    std::cout << name << std::endl;
    std::cout << currentPrice << std::endl;
    std::cout << lastPrice << std::endl;
}