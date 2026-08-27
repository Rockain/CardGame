#pragma once

#include <memory>
#include <string>
#include <vector>
#include "Effect.h"

class Player;

class Card
{
private:
    std::string name;
    unsigned int cost;
    std::vector<std::unique_ptr<Effect>> effects;

public:
    Card(std::string name = "NONE", unsigned int cost = 0, std::vector<std::unique_ptr<Effect>> effects = {});

    std::string  getName() const;
    unsigned int getCost() const;
    unsigned int getNbEffects() const;

    void applyEffects(Player* user, Player* target);
};