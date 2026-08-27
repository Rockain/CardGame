#include "Card.h"

Card::Card(std::string name, unsigned int cost, std::vector<std::unique_ptr<Effect>> effects)
    : name(name), cost(cost), effects(std::move(effects)) {}

std::string  Card::getName()     const { return name; }
unsigned int Card::getCost()     const { return cost; }
unsigned int Card::getNbEffects() const { return static_cast<unsigned int>(effects.size()); }

void Card::applyEffects(Player* user, Player* target)
{
    for (const auto& effect : effects)
    {
        effect->applyEffect(user, target);
    }
}