#pragma once
#include <iostream>
#include "String.h"
#include "Deck.h"

template <typename T, typename U>
class Player {
    private:
    String name;
    size_t wins;
    size_t loses;
    Deck<T> deck1;
    Deck<U> deck2;

    public:
    Player();
    Player(const String&, const size_t&, const size_t&, const Deck<T>&, const Deck<U>&);
    Player(const Player<T,U>&);

    T drawCardDeck1();
    U drawCardDeck2();
    void savePlayer(std::ofstream &) const;
    void loadPlayer(std::ifstream &);

    void setName(const String& name);
    void setWins(const size_t& wins);
    void setLoses(const size_t& loses);

    const String getName() const;
    const size_t getWins() const;
    const size_t getLoses() const;

    const void print() const;

};

template <typename T, typename U>
Player<T,U>::Player() {
    name = "Empty";
    wins = 0;
    loses = 0;
}

template <typename T, typename U>
Player<T, U>::Player(const String& other, const size_t& wins, const size_t& loses, const Deck<T>& deck1, const Deck<U>& deck2) 
{
    name = other;
    this->wins = wins;
    this->loses = loses;
    this->deck1 = deck1;
    this->deck2 = deck2;
}

template <typename T, typename U>
Player<T,U>::Player(const Player<T,U>& other) {
    this->name = other.name;
    this->wins = other.wins;
    this->loses = other.loses;
    this->deck1 = other.deck1;
    this->deck2 = other.deck2;
}

template <typename T, typename U>
T Player<T, U>::drawCardDeck1()
{
        return deck1.drawCard();
}

template <typename T, typename U>
U Player<T, U>::drawCardDeck2()
{
        return deck2.drawCard();
}

template <typename T, typename U>
void Player<T,U>::savePlayer(std::ofstream &out) const
{
    if (out.is_open())
    {
        out << this->name.getString() << "\n";
        out << this->wins << "\n";
        out << this->loses << "\n";
        out.close();
    }
    else
    {
        std::cerr << "Unable to open the file.\n";
    }
}

template <typename T, typename U>
void Player<T,U>::loadPlayer(std::ifstream& in)
{
    if (in.is_open())
    {
        in >> name;
        in >> wins;
        in >> loses;
        in.close();
    }
    else
    {
        std::cerr << "Unable to open the file.\n";
    }
}

template <typename T, typename U>
void Player<T,U>::setName(const String &name){ 
    this->name = name;
}

template <typename T, typename U>
void Player<T,U>::setWins(const size_t &wins) {
    this->wins = wins;
}

template <typename T, typename U>
void Player<T,U>::setLoses(const size_t &loses) {
    this->loses = loses;
}

template <typename T, typename U>
const String Player<T,U>::getName() const {
    return this->name;
}

template <typename T, typename U>
const size_t Player<T,U>::getWins() const {
    return this->wins;
}

template <typename T, typename U>
const size_t Player<T,U>::getLoses() const {
    return this->loses;
}

template<typename T, typename U>
const void Player<T,U>::print() const {
    std::cout << "Name: " << this->name;
    std::cout << "Wins: " << this->wins << "\n";
    std::cout << "Loses: " << this->loses << "\n";
}