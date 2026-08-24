#include "Card.h"
#include "Effects.h"

Card::Card(std::string name, unsigned int cost, Effects effects)
    : name(name), cost(cost), effects(effects) {}

std::string    Card::getName()    const { return name; }
unsigned int   Card::getCost()    const { return cost; }
const Effects& Card::getEffects() const { return effects;}

void Card::applyEffects(Player* target) {}