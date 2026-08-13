#include "Deck.h"
#include "Card.h"

void Deck::addCard(std::unique_ptr<Card> card)
{
    cards.emplace_back(std::move(card));
}

std::unique_ptr<Card> Deck::draw()
{
    auto card = std::move(cards.back());
    cards.pop_back();

    return card;
}

unsigned int Deck::size() const
{
    return static_cast<unsigned int>(cards.size());
}