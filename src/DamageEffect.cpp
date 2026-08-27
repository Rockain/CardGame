#include "DamageEffect.h"
#include "Player.h"

DamageEffect::DamageEffect(unsigned int damageValue) : damageValue(damageValue) {};

void DamageEffect::applyEffect(Player* user, Player* target)
{
    target->takeDamage(damageValue);
}