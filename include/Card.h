#pragma once

#include <string>
#include "Effects.h"

class Player;

class Card
{
private:
    std::string name;
    unsigned int cost;
    Effects effects;

public:
    Card(std::string name = "NONE", unsigned int cost = 0, Effects effects = {});
    virtual ~Card() = default;

    std::string getName() const;
    unsigned int getCost() const;
    const Effects& getEffects() const;

    virtual void applyEffects(Player* target);
};