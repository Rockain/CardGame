#include "SpellCard.h"
#include "Player.h"

#include <iostream>

SpellCard::SpellCard(std::string name, unsigned int cost, Effects effects)
    : Card(name, cost, effects) {}

void SpellCard::applyEffects(Player* target)
{
    unsigned int damage = getEffects().getDamage();
    target->takeDamage(damage);
}