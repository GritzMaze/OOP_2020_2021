#pragma once
#include <iostream>
#include "String.h"

class WaterCard {
    private:
    String name;
    size_t power;
    size_t bonus;
    int type = 1;

    void copy(const WaterCard& other) {
        setName(other.name);
        setPower(other.power);
        setBonus(other.bonus);
    }

    public:
    WaterCard() {
        name = "Empty";
        power = 0;
        bonus = 0;
    }
    WaterCard(const String& o_name, const size_t& o_power = 0, const size_t& o_bonus = 0)
    {
        name = o_name;
        power = o_power;
        bonus = o_bonus;
    }
    WaterCard(const WaterCard& other) { 
        copy(other);
        }

    void setName(const String& other) {
        this->name = other;
    }

    void setPower(const size_t& other) {
        this->power = other;
    }

    void setBonus(const size_t& other) {
        this->bonus = other;
    }

    String getName() const {
        return this->name.getString();
    }

    size_t getPower() const {
        return this->power;
    }

    size_t getBonus() const {
        return this->bonus;
    }

    size_t getType() const {
        return this->type;
    }

    WaterCard &operator=(const WaterCard &other)
    {
        name = other.name;
        power = other.power;
        bonus = other.power;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const WaterCard& other) {
        out << "Name: " << other.getName();
        out << "Power: " << other.power << "\n";
        out << "Bonus power: " << other.bonus << "\n";
        out << "Type: " << other.type << "\n";

        return out;
    } 
    friend std::istream& operator>>(std::istream& in, WaterCard& other) {
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

