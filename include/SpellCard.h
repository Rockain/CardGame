#pragma once

#include <string>

#include "Card.h"

class Player;

class SpellCard : public Card
{
public:
    SpellCard(
        std::string name = "SpellCard",
        unsigned int cost = 0,
        Effects effects = {}
    );

    void applyEffects(Player* target) override;
};