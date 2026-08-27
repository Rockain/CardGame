#include "Player.h"
#include "Deck.h"
#include "Card.h"

#include <iostream>

Player::Player(std::string name, unsigned int health, unsigned int mana)
    : name(name), health(health), mana(mana) {}

std::string  Player::getName()   const { return name; }
unsigned int Player::getMana()   const { return mana; }
unsigned int Player::getHealth() const { return health; }

unsigned int Player::getHandSize() const
{
    return static_cast<unsigned int>(hand.size());
}

void Player::giveDeck(Deck&& deck)
{
    this->deck = std::move(deck);
}

void Player::draw(unsigned int x)
{
    if (deck.size() > 0)
    {
        std::cout << name << " - Draw " << x << " card from his deck" << std::endl;
        for (int i = 0; i < x; i++)
            hand.emplace_back(deck.draw());
    }
}

void Player::playCard(int i, Player* target)
{
    if (i < 0 || i >= static_cast<int>(hand.size()))
    {
        return;
    }

    if (mana >= hand[i]->getCost())
    {
        std::cout << name << " - Play " << hand[i]->getName() << " for " << hand[i]->getCost() << " mana" << std::endl;

        hand[i]->applyEffects(this, target);
        mana -= hand[i]->getCost();
        hand.erase(hand.begin() + i);

        std::cout << name << " - Mana remaining : " << mana << std::endl;
    }
    else
    {
        std::cout << name << " - Can't play card, not enought mana : " << mana << std::endl;
    }
}

void Player::takeDamage(unsigned int damage)
{
    if (damage >= health) { health = 0; }
    else                  { health -= damage; }

    std::cout << name << " - Take " << damage << ", health remaining : " << health << std::endl;
}

void Player::heal(unsigned int value)
{
    health += value;

    std::cout << name << " - Heal " << value << ", current health : " << health << std::endl;
}