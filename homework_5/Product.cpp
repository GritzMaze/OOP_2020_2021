#include "Product.h"

Product::Product() : price(0), discount(0), face(Coin::flipr()) {}

Product::Product(const String& _name, const double& _price,
const int& _discount) : name(_name), price(_price), discount(_discount) {}

const side Product::getFace() const {
    return Coin::flipr();
}  

const double& Product::getPrice() const {
    return this->price;
}  

const int& Product::getDiscount() const {
    return this->discount;
} 

std::ostream& operator<<(std::ostream& out, const Product& prod) {
    out << "Name: " << prod.name << "\n";
    out << "Price: " << prod.price << "\n";
    return out;
}