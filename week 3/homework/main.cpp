#include <iostream>
#include "Crypto.h"
#include "Film.h"
#include "FilmRanking.h"

int main() {

// Task 1

    Crypto bitcoin;
    bitcoin.setName("Bitcoin");
    bitcoin.setCurrPrice(60000);
    bitcoin.setLastPrice(55000);
    std::cout << bitcoin.PriceDifference();
    
    std::cout << std::endl;
    //Task 2

    Film film1;
    film1.setName("Titatic");
    film1.setDirector("azis");
    film1.setAwards(2);
    film1.print();


    // Task3

    int size = 3;
    Film movies[3];
    movies[0].setName("Name01");
    movies[0].setAwards(11);
    movies[1].setName("Name02");
    movies[1].setAwards(12);
    movies[2].setName("Name03");
    movies[2].setAwards(2);

    FilmRanking films = FilmRanking(movies, size);
    films.printTop(3);
    return 0;
}