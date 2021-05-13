#include "BulgarianCoin.h"

BulgarianCoin::BulgarianCoin() : Coin()
{
    nationality = "BG";
}

BulgarianCoin::BulgarianCoin(const side &face, const char *nationality,
                             const double &value) : Coin(face, nationality, value) {}

BulgarianCoin::BulgarianCoin(const BulgarianCoin& other) : Coin(other) {}

BulgarianCoin& BulgarianCoin::operator=(const BulgarianCoin& other) {
    if(this != &other) {
        Coin::operator=(other);
    }
    return *this;
}

BulgarianCoin &BulgarianCoin::operator=(const double &other)
{
    this->value = other;
    return *this;
}

void BulgarianCoin::flip()
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

void BulgarianCoin::convertFromAmerican(const double& value) {
    this->value = value/3;
    if (this->value < 0)
        this->value = 0;
} 

void BulgarianCoin::convertFromGerman(const double& value) {
    this->value = value/6;
    if (this->value < 0)
        this->value = 0;
}

void BulgarianCoin::convertFromBoth(const double &value, const double &value2)
{
    this->convertFromAmerican(value);
    this->convertFromGerman(value2);
}
