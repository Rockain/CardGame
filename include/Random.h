#pragma once

#include <random>

class Random
{
    private:
        std::random_device rd;
        std::mt19937 generator;

    public:
        Random();

        int getInt(int min, int max);
};