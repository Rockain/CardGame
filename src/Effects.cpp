#include "Effects.h"

Effects::Effects(unsigned int damage) : damage(damage) {}

unsigned int Effects::getDamage() const { return damage; }