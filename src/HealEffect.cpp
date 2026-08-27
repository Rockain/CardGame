#include "HealEffect.h"
#include "Player.h"

HealEffect::HealEffect(unsigned int healValue) : healValue(healValue) {};

void HealEffect::applyEffect(Player* user, Player* target)
{
    user->heal(healValue);
}