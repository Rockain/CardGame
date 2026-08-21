#pragma once

#include <vector>
#include <memory>

class Card;

class Deck
{
    private:
        std::vector<std::unique_ptr<Card>> cards;
    
    public:
        void addCard(std::unique_ptr<Card> card);
        std::unique_ptr<Card> draw();
        unsigned int size() const;
};
