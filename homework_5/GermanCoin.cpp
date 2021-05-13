#include "GermanCoin.h"

GermanCoin::GermanCoin() : Coin()
{
    nationality = "BG";
}

GermanCoin::GermanCoin(const side &face, const char *nationality,
                             const double &value) : Coin(face, nationality, value) {}

GermanCoin::GermanCoin(const GermanCoin &other) : Coin(other) {}

GermanCoin &GermanCoin::operator=(const GermanCoin &other)
{
    if (this != &other)
    {
        Coin::operator=(other);
    }
    return *this;
}

GermanCoin &GermanCoin::operator=(const double &other)
{
    this->value = other;
    return *this;
}

void GermanCoin::flip()
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

void GermanCoin::convertFromAmerican(const double &value)
{
    this->value = value * 2.5;
    if (this->value < 0)
        this->value = 0;
}

void GermanCoin::convertFromBulgarian(const double &value)
{
    this->value = value * 3;
    if(this->value < 0) this->value = 0;
}

void GermanCoin::convertFromBoth(const double& value, const double& value2) {
    this->convertFromAmerican(value);
    this->convertFromBulgarian(value2);
}
