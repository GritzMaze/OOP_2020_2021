#include "AmericanCoin.h"

AmericanCoin::AmericanCoin() : Coin()
{
    nationality = "BG";
}

AmericanCoin::AmericanCoin(const side &face, const char *nationality,
                             const double &value) : Coin(face, nationality, value) {}

AmericanCoin::AmericanCoin(const AmericanCoin &other) : Coin(other) {}

AmericanCoin &AmericanCoin::operator=(const AmericanCoin &other)
{
    if (this != &other)
    {
        Coin::operator=(other);
    }
    return *this;
}

AmericanCoin &AmericanCoin::operator=(const double &other)
{
    this->value = other;
    return *this;
}

void AmericanCoin::flip()
{
    int result = 0;
    srand(time(NULL));
    result = rand() % 10 + 1;
    if (result > 7)
    {
        face = HEADS;
    }
    else
    {
        face = TAILS;
    }
}

void AmericanCoin::convertFromBulgarian(const double &value)
{
    this->value = value * 3;
    if (this->value < 0)
        this->value = 0;
}

void AmericanCoin::convertFromGerman(const double &value)
{
    this->value = (2 * value) / 5;
    if (this->value < 0)
        this->value = 0;
}

void AmericanCoin::convertFromBoth(const double &value, const double &value2)
{
    this->convertFromBulgarian(value);
    this->convertFromGerman(value2);
}
