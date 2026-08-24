#include "Effects.h"

Effects::Effects(unsigned int damage, unsigned int heal) : damage(damage), heal(heal) {}

unsigned int Effects::getDamage() const { return damage; }
unsigned int Effects::getHeal()   const { return heal; }