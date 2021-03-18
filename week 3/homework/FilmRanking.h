#pragma once
#include <iostream>
#include <cstring>
#include "Film.h"

class FilmRanking
{
private:
    Film *name;
    int size;

    void copy(const FilmRanking& _Film);
    void swap(Film *a, Film *b);
    void erase();
    void sortAwards();
public:
    FilmRanking();
    FilmRanking &operator=(const FilmRanking& _Film);
    FilmRanking(const FilmRanking& _Film);
    FilmRanking(const Film* _Film, const int& _size);
    ~FilmRanking();

    void printTop(const int &n);

    void setFilms(const Film* _films);
    void setSize(const int& _size);

    const Film* getFilms() const;
    const int getSize() const;
};