#include "Coin.h"

void Coin::copy(const Coin& other) {
    face = other.face;
    nationality = new char[strlen(other.nationality) + 1];
    strncpy(nationality, other.nationality, strlen(other.nationality) + 1);
    value = other.value;
}

void Coin::erase() {
    if(this->nationality != nullptr) {
        delete [] this->nationality;
    }

    value = 0;
}

Coin::Coin() {
    this->flip();
    nationality = new char[1];
    nationality[1] = '\0';
    value = 0;
}

Coin::Coin(const side& face, const char* nationality, const double& value) {
    this->face = face;
    this->nationality = new char[strlen(nationality) + 1];
    strncpy(this->nationality, nationality, strlen(nationality) + 1);
    this->value = value;
}

Coin::Coin(const Coin& other) {
    copy(other);
}

Coin::~Coin() {
    erase();
}

Coin& Coin::operator=(const Coin& other) {
    if(this != &other) {
    copy(other);
    }
    return *this;
}

// Coin& Coin::operator=(const double& other) {
//     this->value = other; 
//     return *this;
// }

Coin& Coin::operator++() {
    this->value++;
    return *this;
}

Coin Coin::operator++(int) {
    Coin temp = *this;
    temp.operator++();
    return temp;
}

void Coin::flip() {
    int result;
    srand(time(NULL));
    result = rand() % 2 + 1;
    if(result == 1) {
        face = HEADS;
    }
    else {
        face = TAILS;
    }
}

side Coin::flipr() {
    int result;
    srand(time(NULL));
    result = rand() % 2 + 1;
    if (result == 1)
    {
        return HEADS;
    }
    else
    {
        return TAILS;
    }
}

const side Coin::getFace() const {
    return this->face;
}

const int Coin::getValue() const {
    return this->value;
}

void Coin::setValue(const double& num) {
    this->value = num;
}

const void Coin::print() const {
    std::cout << "Side:";
    face ? std::cout << "Tails" : std::cout << "Heads";
    std::cout << std::endl;
    std::cout << "Nationality: " << nationality << std::endl;
    std::cout << "Value: " << value << std::endl;
}

