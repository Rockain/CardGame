#pragma once

#include "Effect.h"

class Player;

class DamageEffect : public Effect
{
    private:
        unsigned int damageValue;

    public:
        DamageEffect(unsigned int damageValue = 0);

        void applyEffect(Player* user, Player* target) override;
};