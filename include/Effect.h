#pragma once

class Player;

class Effect
{
    public:
        virtual ~Effect() = default;
        virtual void applyEffect(Player* user, Player* target) = 0;
};