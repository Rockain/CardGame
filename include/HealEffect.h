#pragma once

#include "Effect.h"

class Player;

class HealEffect : public Effect
{
    private:
        unsigned int healValue;

    public:
        HealEffect(unsigned int healValue = 0);

        void applyEffect(Player* user, Player* target) override;
};