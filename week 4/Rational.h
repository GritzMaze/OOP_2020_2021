#pragma once
#include <iostream>

class Rational {
    private:
    int numerator;
    int denominator;

    void copy(const Rational& _Rational);
    int findGCD(const int& numerator1, const int& numerator2);
    int findLCM(const int& denominator1, const int& denominator2);
    void simplify(int &numerator, int &denominator);

        public : Rational();
    Rational(const int& numerator, const int& denominator);
    Rational(Rational& _Rational);

    void setNumerator(const int& numerator);
    void setDenominator(const int& denominator);

    const int getNumerator() const;
    const int getDenominator() const;

    const void print() const;

    Rational& operator+(const Rational& _Rational);
    Rational& operator-(const Rational& _Rational);
    Rational& operator*(const Rational& _Rational);
    Rational& operator/(const Rational& _Rational);
    Rational& operator=(const Rational& _Rational);
    Rational& operator+=(const Rational& _Rational);
    Rational& operator-=(const Rational& _Rational);
    Rational& operator*=(const Rational& _Rational);
    Rational& operator/=(const Rational& _Rational);
    bool operator>=(const Rational& _Rational);
    bool operator<=(const Rational& _Rational);
    bool operator==(const Rational& _Rational);
    bool operator!=(const Rational& _Rational);
};