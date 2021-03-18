#include "FilmRanking.h"
#include "Film.h"

void FilmRanking::copy(const FilmRanking& _Film)
{
    setSize(_Film.size);
    setFilms(_Film.name);
}

void FilmRanking::erase() {
    this->size = 0;
    delete [] name;
}

void FilmRanking::swap(Film *a, Film *b) {
    Film temp = *a;
    *a = *b;
    *b = temp;
}

void FilmRanking::sortAwards() {
    for(int i = 0; i < getSize() - 1; i++) {
        for(int j = i + 1; j < getSize(); j++)
        {
            if(name[i].getAwards() < name[j].getAwards()) {
                this->swap(&name[i], &name[j]);
            }
        }
    }
}

FilmRanking::FilmRanking() {
    size = 1;
    name = new Film[size];
    if (!name)
        throw "No memory";
}

FilmRanking::FilmRanking(const FilmRanking& _Film) {
    copy(_Film);
}

FilmRanking::FilmRanking(const Film* _Film, const int& _size)
{
    setSize(size);
    setFilms(_Film);
}

FilmRanking& FilmRanking::operator=(const FilmRanking& _Film) {
    if(this != &_Film) {
        erase();
        copy(_Film);
    }
    return *this;
}

FilmRanking::~FilmRanking() {
    erase();
}


void FilmRanking::setFilms(const Film* _films) {
    this->name = new Film[getSize()];
    if (!this->name)
        throw "No memory!";
    for (int i = 0; i < getSize(); i++)
    {
        this->name[i] = name[i];
    }
}

void FilmRanking::setSize(const int& _size) {
    if (size > 100)
        throw "Too big size.";
    this->size = size;
}

const Film *FilmRanking::getFilms() const {
    return this->name;
}

const int FilmRanking::getSize() const {
    return this->size;
}

void FilmRanking::printTop(const int &n) {
    sortAwards();
    for(int i = 0; i < n; i++) {
        name[i].print();
    }
}