#pragma once

#include <string>
#include "Card.h"

class Player;

class HealSpell : public Card
{
public:
    HealSpell(std::string name = "HealSpell", unsigned int cost = 0, Effects effects = {});

    void applyEffects(Player* target) override;
};