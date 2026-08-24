#pragma once

class Effects
{
private:
    unsigned int damage;
    unsigned int heal;

public:
    Effects(unsigned int damage = 0, unsigned int heal = 0);

    unsigned int getDamage() const;
    unsigned int getHeal() const;
};