#include "HealSpell.h"
#include "Player.h"

#include <iostream>

HealSpell::HealSpell(std::string name, unsigned int cost, Effects effects)
    : Card(name, cost, effects) {}

void HealSpell::applyEffects(Player* target)
{
    unsigned int value = getEffects().getHeal();
    target->heal(value);
}