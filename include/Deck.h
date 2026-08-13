#pragma once

#include <memory>
#include <vector>

class Card;

class Deck
{
private:
    std::vector<std::unique_ptr<Card>> cards;

public:
    Deck() = default;
    ~Deck() = default;

    Deck(const Deck&) = delete;
    Deck& operator=(const Deck&) = delete;

    Deck(Deck&&) = default;
    Deck& operator=(Deck&&) = default;

    void addCard(std::unique_ptr<Card> card);

    std::unique_ptr<Card> draw();

    unsigned int size() const;
};