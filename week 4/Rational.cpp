#include "Rational.h"

void Rational::copy(const Rational& _Rational) {
    setNumerator(_Rational.numerator);
    setDenominator(_Rational.denominator);
}

Rational::Rational() {
    setNumerator(1);
    setDenominator(1);
}

Rational::Rational(const int &numerator, const int &denominator) {
    setNumerator(numerator);
    setDenominator(denominator);
}

Rational::Rational(Rational& _Rational) {
    this->copy(_Rational);
}

void Rational::setNumerator(const int& numerator) {
    this->numerator = numerator;
}

void Rational::setDenominator(const int& denominator) {
    this->denominator = denominator;
}

const int Rational::getNumerator() const {
    return this->numerator;
}

const int Rational::getDenominator() const {
    return this-> denominator;
}

const void Rational::print() const {
    std::cout << this->numerator << "/" << this->denominator << std::endl;
}

int Rational::findGCD(const int& numerator1, const int& numerator2) {
    int gcd;
    for(int i = 1; i < numerator1 && i < numerator2; i++)
    {
        if(numerator1 % i == 0 && numerator2 % i == 0) gcd = i;
    }
    return gcd;
}

void Rational::simplify(int &numerator, int &denominator)
{
    int common_factor = findGCD(numerator, denominator);

    numerator = numerator / common_factor;
    denominator = denominator / common_factor;
}

int Rational::findLCM(const int &denominator1, const int &denominator2) {
    return (denominator1 * denominator2)/findGCD(denominator1, denominator2);
}

Rational& Rational::operator+(const Rational& _Rational) {
    int lcm = findLCM(this->denominator, _Rational.denominator);
    int sum = (this->numerator*lcm/this->denominator) + (_Rational.numerator*lcm/_Rational.denominator);
    this->numerator = sum/findGCD(sum, lcm);
    this->denominator = lcm/findGCD(sum, lcm);
    return *this;
}

Rational& Rational::operator-(const Rational& _Rational) {
    this->denominator = -(this->denominator);
    this->numerator = (this->numerator);
    int lcm = findLCM(this->denominator, _Rational.denominator);
    int sum = (this->numerator * lcm / this->denominator) + (_Rational.numerator * lcm / _Rational.denominator);
    this->numerator = sum / findGCD(sum, lcm);
    this->denominator = lcm / findGCD(sum, lcm);
    return *this;
}

Rational& Rational::operator*(const Rational& _Rational) {
    this->numerator *= _Rational.numerator;
    this->denominator *= _Rational.denominator;
    simplify(this->numerator, this->denominator);
    return *this;
}

Rational& Rational::operator/(const Rational& _Rational) {
    this->numerator *= _Rational.denominator;
    this->denominator *= _Rational.numerator;
    simplify(this->numerator, this->denominator);
    return *this;
}

bool Rational::operator>=(const Rational& _Rational) {
    return (this->numerator/this->denominator >= _Rational.numerator/_Rational.denominator);
}

bool Rational::operator<=(const Rational& _Rational) {
    return (this->numerator / this->denominator <= _Rational.numerator / _Rational.denominator);
}

bool Rational::operator==(const Rational& _Rational) {
    int num1 = this->numerator;
    int num2 = _Rational.numerator;
    int denom1 = this->denominator;
    int denom2 = _Rational.denominator;
    simplify(num1, denom1);
    simplify(num2, denom2);
    if(num1 == num2 && denom1 == denom2) return true;
    else return false;
}

bool Rational::operator!=(const Rational& _Rational) {
    return !(*this == _Rational);
}

Rational &Rational::operator=(const Rational &_Rational)
{
    if(this != &_Rational)
    {
    this->copy(_Rational);
    }
    return *this;
}

Rational &Rational::operator+=(const Rational &_Rational)
{
    return *this + _Rational;
}

Rational &Rational::operator-=(const Rational &_Rational)
{
    return *this - _Rational;
}

Rational &Rational::operator*=(const Rational &_Rational)
{
    return *this * _Rational;
}

Rational &Rational::operator/=(const Rational &_Rational)
{
    return *this / _Rational;
}


