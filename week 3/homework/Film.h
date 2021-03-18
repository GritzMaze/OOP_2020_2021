#pragma once
#include <iostream>
#include <cstring>

class Film
{
private:
    char* name;
    char* director;
    int awards;

    void copy(const Film& _film);
    void erase();

public:
    Film();
    Film &operator=(const Film& _Film);
    Film(const Film &_Film);
    ~Film();

    void setName(const char* _name);
    void setDirector(const char* _director);
    void setAwards(const double _awards);

    const char* getName() const;
    const char* getDirector() const;
    const int getAwards() const;

    const void print() const;
};
