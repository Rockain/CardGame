#include "Random.h"

Random::Random() : generator(rd()) {}

int Random::getInt(int min, int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}