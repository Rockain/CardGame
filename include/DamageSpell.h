#pragma once

#include <string>
#include "Card.h"

class Player;

class DamageSpell : public Card
{
public:
    DamageSpell(std::string name = "DamageSpell", unsigned int cost = 0, Effects effects = {});

    void applyEffects(Player* target) override;
};