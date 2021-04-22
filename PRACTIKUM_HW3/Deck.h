#pragma once
#include <iostream>
#include <time.h>
#include "Vector.h"

template <typename T>
class Deck {
    private:
    Vector<T> arr;

    public:

    void addCard(const T&);
    T drawCard();
    void shuffle();
    Deck<T>& operator=(const Deck&);
    Deck<T> operator+(const T&);
    Deck<T>& operator+=(const T&);
    const void print() const;

};

template <typename T>
void Deck<T>::addCard(const T& elem)
{

    if (arr.getSize() >= 30)
    {
        std::cout << "Error: Deck is full!";
        return;
    }
    else
    {
        for (int i = 0; i < arr.getSize(); i++)
        {
            if (arr[i].getName() == elem.getName())
            {
                std::cout << "Error: Card with this name already exist.";
                return;
            }
        }
        arr.pushBack(elem);
    }
}

template <typename T>
T Deck<T>::drawCard()
{
    T card = arr.back();
    arr.popBack();
   // arr.pushFront(card);
    return card;
}

// Fisher–Yates shuffle
template <typename T>
void Deck<T>::shuffle()
{
    int currentIndex = arr.getSize();
    T temporaryValue;
    int randomIndex = 0;

    srand(time(0));

    while (0 != currentIndex)
    {

        randomIndex = rand() % (currentIndex);
        currentIndex -= 1;

        temporaryValue = arr[currentIndex];
        arr[currentIndex] = arr[randomIndex];
        arr[randomIndex] = temporaryValue;
    }
}

template <typename T>
Deck<T>& Deck<T>::operator=(const Deck &other)
{
    arr = other.arr;
    return *this;
}

template <typename T>
Deck<T> Deck<T>::operator+(const T &card)
{
    Deck temp;
    temp = *this;
    temp.addCard(card);
    return temp;
}

template <typename T>
Deck<T>& Deck<T>::operator+=(const T &card)
{
    addCard(card);
    return *this;
}

template <typename T>
const void Deck<T>::print() const
{
    arr.print();
}