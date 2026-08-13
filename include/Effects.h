#pragma once

class Effects
{
private:
    unsigned int damage;

public:
    Effects(unsigned int damage = 0);

    unsigned int getDamage() const;
};