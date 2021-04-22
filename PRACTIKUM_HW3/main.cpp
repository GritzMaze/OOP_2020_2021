#include <iostream>
#include <fstream>
#include "String.h"
#include "WaterCard.h"
#include "EarthCard.h"
#include "WindCard.h"
#include "FireCard.h"
#include "Deck.h"
#include "Vector.h"
#include "Player.h"

void add_cards_water(Deck<WaterCard> &d)
{
    WaterCard w1("Voda1", 10, 1);
    WaterCard w2("Voda2", 11, 2);
    WaterCard w3("Voda3", 12, 3);
    WaterCard w4("Voda4", 13, 4);
    WaterCard w5("Voda5", 14, 5);
    WaterCard w6("Voda6", 15, 6);
    WaterCard w7("Voda7", 16, 7);
    WaterCard w8("Voda8", 17, 8);
    WaterCard w9("Voda9", 18, 9);

    d.addCard(w1);
    d.addCard(w2);
    d.addCard(w3);
    d.addCard(w4);
    d.addCard(w5);
    d.addCard(w6);
    d.addCard(w7);
    d.addCard(w8);
    d.addCard(w9);

    d.shuffle();
}

void add_cards_fire(Deck<FireCard> &d)
{
    FireCard f1("Fire1", 10, 1);
    FireCard f2("Fire2", 11, 2);
    FireCard f3("Fire3", 12, 3);
    FireCard f4("Fire4", 13, 4);
    FireCard f5("Fire5", 14, 5);
    FireCard f6("Fire6", 15, 6);
    FireCard f7("Fire7", 16, 7);
    FireCard f8("Fire8", 17, 8);
    FireCard f9("Fire9", 18, 9);

    d.addCard(f1);
    d.addCard(f2);
    d.addCard(f3);
    d.addCard(f4);
    d.addCard(f5);
    d.addCard(f6);
    d.addCard(f7);
    d.addCard(f8);
    d.addCard(f9);

    d.shuffle();
}

void add_cards_earth(Deck<EarthCard> &d)
{
    EarthCard e1("Earth1", 10, 1);
    EarthCard e2("Earth2", 11, 2);
    EarthCard e3("Earth3", 12, 3);
    EarthCard e4("Earth4", 13, 4);
    EarthCard e5("Earth5", 14, 5);
    EarthCard e6("Earth6", 15, 6);
    EarthCard e7("Earth7", 16, 7);
    EarthCard e8("Earth8", 17, 8);
    EarthCard e9("Earth9", 18, 9);

    d.addCard(e1);
    d.addCard(e2);
    d.addCard(e3);
    d.addCard(e4);
    d.addCard(e5);
    d.addCard(e6);
    d.addCard(e7);
    d.addCard(e8);
    d.addCard(e9);

    d.shuffle();
}

void add_cards_wind(Deck<WindCard> &d)
{
    WindCard w1("Wind1", 10, 1);
    WindCard w2("Wind2", 11, 2);
    WindCard w3("Wind3", 12, 3);
    WindCard w4("Wind4", 13, 4);
    WindCard w5("Wind5", 14, 5);
    WindCard w6("Wind6", 15, 6);
    WindCard w7("Wind7", 16, 7);
    WindCard w8("Wind8", 17, 8);
    WindCard w9("Wind9", 18, 9);

    d.addCard(w1);
    d.addCard(w2);
    d.addCard(w3);
    d.addCard(w4);
    d.addCard(w5);
    d.addCard(w6);
    d.addCard(w7);
    d.addCard(w8);
    d.addCard(w9);

    d.shuffle();
}

bool isContra(int a, int b)
{
    if ((a == 1 && b == 2) || (b == 1 && a == 2))
        return true; // Water and Fire
    else if ((a == 2 && b == 4) || (b == 2 && a == 4))
        return true; // Wind and Fire
    else if ((a == 1 && b == 3) || (b == 1 && a == 3))
        return true; // Water and Earth
    else if ((a == 3 && b == 4) || (b == 3 && a == 4))
        return true; // Wind and Earth
    else
        return false;
}
template <class T, class U>
void game(T& card_p1, U& card_p2, size_t& score_p1, size_t& score_p2) {
    int battleScore_p1 = 0;
    int battleScore_p2 = 0;
    
    std::cout << "Card " << card_p1.getName() << " is drawn for player 1! \n";
    std::cout << "Card " << card_p2.getName() << " is drawn for player 2! \n";


    if (isContra(card_p1.getType(), card_p2.getType()))
    {
        battleScore_p1 = card_p1.getPower() + card_p1.getBonus();
        battleScore_p2 = card_p2.getPower() + card_p2.getBonus();
        if(battleScore_p1 > battleScore_p2) {
            score_p1++;
            std::cout << "Player 1 takes a point! \n";
            std::cout << "He has " << score_p1 << " points now! \n";
        return;
        }
        else if (battleScore_p1 == battleScore_p2)
        {
            score_p2++;
            std::cout << "Player 2 takes a point! \n";
            std::cout << "He has " << score_p2 << " points now! \n";
            return;
        }
    }
    else {
        battleScore_p1 = card_p1.getPower();
        battleScore_p2 = card_p2.getPower();
        if (battleScore_p1 > battleScore_p2)
        {
            score_p1++;
            std::cout << "Player 1 takes a point! \n";
            std::cout << "He has " << score_p1 << " points now! \n";
            return;
        }
        else if( battleScore_p1 == battleScore_p2)
        {
            score_p2++;
            std::cout << "Player 2 takes a point! \n";
            std::cout << "He has " << score_p2 << " points now! \n";
            return;
        }
    }
    return;
}

int main()
{
    // The GAME

    // Iniatiliazing the decks

    Deck<WaterCard> deck_w;
    add_cards_water(deck_w);
    Deck<FireCard> deck_f;
    add_cards_fire(deck_f);
    Deck<WindCard> deck_wi;
    add_cards_wind(deck_wi);
    Deck<EarthCard> deck_e;
    add_cards_earth(deck_e);

    // Make the players

    Player<WaterCard, FireCard> player1("Vesselin", 0, 0, deck_w, deck_f);
    Player<WindCard, EarthCard> player2("Martin", 0, 0, deck_wi, deck_e);

    // Save the information of the players

    std::ifstream playerOut1("player1.txt");
    player1.loadPlayer(playerOut1);
    std::ifstream playerOut2("player2.txt");
    player2.loadPlayer(playerOut2);

    std::srand(time(NULL));
    size_t random = rand() % 4 + 1;

    WaterCard water;
    FireCard fire;
    WindCard wind;
    EarthCard earth;
    size_t score_p1 = 0;
    size_t score_p2 = 0;

    while (score_p1 < 5 && score_p2 < 5) {
    if (random == 1)
    {
        water = player1.drawCardDeck1();
        wind = player2.drawCardDeck1();
        game<WaterCard, WindCard>(water, wind, score_p1, score_p2);
    }
    else if( random == 2) {
        fire = player1.drawCardDeck2();
        earth = player2.drawCardDeck2();
        game<FireCard, EarthCard>(fire, earth, score_p1, score_p2);
    }
    else if(random == 3) {
        water = player1.drawCardDeck1();
        earth = player2.drawCardDeck2();
        game<WaterCard, EarthCard>(water, earth, score_p1, score_p2);
    }
    else if (random == 4) {
        fire = player1.drawCardDeck2();
        wind = player2.drawCardDeck1();
        game<FireCard, WindCard>(fire, wind, score_p1, score_p2);
    }
    }
    if(score_p1 == 5) {
        std::cout << "Player " << player1.getName() << " wins!";
        std::ofstream playerIn1("player1.txt");
        player1.setWins(player1.getWins() + 1);
        player1.savePlayer(playerIn1);
    }
    else if(score_p2 == 5) {
        std::cout << "Player " << player2.getName() << " wins!";
        std::ofstream playerIn2("player2.txt");
        player2.setWins(player2.getWins() + 1);
        player2.savePlayer(playerIn2);
    }
    else {
        std::cout << "Nobody wins! Something broke.";
    }

    return 0;
}