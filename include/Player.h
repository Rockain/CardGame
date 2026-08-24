#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Deck.h"

class Card;

class Player
{
private:
    std::string name;
    unsigned int health;
    unsigned int mana;
    Deck deck;

    std::vector<std::unique_ptr<Card>> hand;

public:
    Player(std::string name = "Player", unsigned int health = 100, unsigned int mana = 10);

    std::string getName() const;
    unsigned int getMana() const;
    unsigned int getHealth() const;
    unsigned int getHandSize() const;

    void giveDeck(Deck&& deck);
    void draw(unsigned int x);
    void playCard(int i, Player* target);
    void takeDamage(unsigned int damage);
    void heal(unsigned int value);
};