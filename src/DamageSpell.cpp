#include "DamageSpell.h"
#include "Player.h"

#include <iostream>

DamageSpell::DamageSpell(std::string name, unsigned int cost, Effects effects)
    : Card(name, cost, effects) {}

void DamageSpell::applyEffects(Player* target)
{
    unsigned int damage = getEffects().getDamage();
    target->takeDamage(damage);
}