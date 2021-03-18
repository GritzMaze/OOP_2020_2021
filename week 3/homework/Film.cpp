#include "Film.h"

void Film::copy(const Film& _Film) {
    this->name = new char[strlen(_Film.name) + 1];
    strcpy(this->name, _Film.name);
    this->director = new char[strlen(_Film.director) + 1];
    strcpy(this->director, _Film.director);
    this->awards = _Film.awards;

}

void Film::erase() {
    delete [] this->name;
    delete [] this->director;
}

Film::Film() {
    this->name = new char[6];
    this->director = new char[6];
    strcpy(this->name, "Empty");
    strcpy(this->director, "Empty");
    this->awards = 0;
}

Film& Film::operator=(const Film& _Film) {
    if(this != &_Film) {
        this->erase();
        this->copy(_Film);
    }
    return *this;
}

Film::~Film() {
    this->erase();
}

void Film::setName(const char *_name) {
    delete [] this->name;
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
}

void Film::setDirector(const char *_director) {
    delete[] this->director;
    this->director = new char[strlen(_director) + 1];
    strcpy(this->director, _director);
}

void Film::setAwards(const double _awards) {
    this->awards = _awards;
}

const char* Film::getName() const {
    return this->name;
}

const char* Film::getDirector() const {
    return this->director;
}

const int Film::getAwards() const {
    return this->awards;
}

const void Film::print() const
{
    std::cout << "Film's name: " << name << std::endl;
    std::cout << "Director: " << director << std::endl;
    std::cout << "Awards: " << awards << std::endl;
}

Film::Film (const Film& _Film) {
    this->copy(_Film);
}