#pragma once
#include <iostream>
#include "String.h"

class WindCard
{
private:
    String name;
    size_t power;
    size_t bonus;
    int type = 4;

    void copy(const WindCard &other)
    {
        setName(other.name);
        setPower(other.power);
        setBonus(other.bonus);
    }

public:
    WindCard()
    {
        name = "Empty";
        power = 0;
        bonus = 0;
    }
    WindCard(const String &o_name, const size_t &o_power = 0, const size_t &o_bonus = 0)
    {
        name = o_name;
        power = o_power;
        bonus = o_bonus;
    }

    WindCard(const WindCard &other)
    {
        copy(other);
    }

    void setName(const String &other)
    {
        this->name = other;
    }

    void setPower(const size_t &other)
    {
        this->power = other;
    }

    void setBonus(const size_t &other)
    {
        this->bonus = other;
    }

    String getName() const
    {
        return this->name.getString();
    }

    const size_t getPower() const
    {
        return this->power;
    }

    const size_t getBonus() const
    {
        return this->bonus;
    }
    const size_t getType() const
    {
        return this->type;
    }

    WindCard &operator=(const WindCard &other)
    {
        name = other.name;
        power = other.power;
        bonus = other.power;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, const WindCard &other)
    {
        out << "Name: " << other.getName();
        out << "Power: " << other.getPower() << "\n";
        out << "Bonus power: " << other.getBonus() << "\n";
        out << "Type: " << other.getType() << "\n";

        return out;
    }
    friend std::istream &operator>>(std::istream &in, WindCard &other)
    {
        std::cout << "Enter name: ";
        in >> other.name;
        std::cout << "Enter power strength";
        in >> other.power;
        std::cout << "Enter bonus power strength";
        in >> other.bonus;

        return in;
    }

    // const void print() const {
    //     std::cout << "Name: ";
    //     std::cout << name  << std::endl;
    //     std::cout << "Power: "       << this->power << std::endl;
    //     std::cout << "Bonus power: " << this->bonus << std::endl;
    // }
};
