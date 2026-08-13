#include "Player.h"
#include "Deck.h"
#include "Card.h"

#include <iostream>

Player::Player(std::string name, unsigned int health, unsigned int mana)
    : name(name), health(health), mana(mana) {}

std::string  Player::getName()   const { return name; }
unsigned int Player::getMana()   const { return mana; }
unsigned int Player::getHealth() const { return health; }

void Player::giveDeck(Deck&& deck)
{
    this->deck = std::move(deck);
}

void Player::drawCard()
{
    if (deck.size() > 0)
    {
        hand.emplace_back(deck.draw());
    }
}

void Player::playCard(int i)
{
    if (i < 0 || i >= static_cast<int>(hand.size()))
    {
        return;
    }

    if (mana >= hand[i]->getCost())
    {
        std::cout << name << " - Play " << hand[i]->getName() << " for " << hand[i]->getCost() << std::endl;

        hand[i]->applyEffects(this);
        mana -= hand[i]->getCost();
        hand.erase(hand.begin() + i);
    }
}

void Player::takeDamage(unsigned int damage)
{
    if (damage >= health) { health = 0; }
    else                  { health -= damage; }

    std::cout << name << " - Take " << damage << ", health remaining : " << health << std::endl;
}