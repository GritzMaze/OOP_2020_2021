#pragma once
#include <iostream>
#include <cstring>

class Crypto {
    private: 
        char* name;
        double currentPrice;
        double lastPrice;

        void erase();

    public: 
    Crypto();
    Crypto(char* _name, double _currentPrice, double _lastPrice);
    ~Crypto();

    double PriceDifference();

    void setName(const char* _name);
    void setCurrPrice(const double _currentPrice);
    void setLastPrice(const double _lastPrice);

    const char* getName() const;
    const double getCurrPrice() const;
    const double getLastPrice() const;

    const void print() const;
};