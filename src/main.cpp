#include <iostream>
#include <memory>

#include "Player.h"
#include "SpellCard.h"

int main()
{
    Player player1("Player 1");
    Player player2("Player 2");

    Deck strongDeck;
    Deck weakDeck;

    for (int i = 0; i < 20; i++)
    {
        strongDeck.addCard(std::make_unique<SpellCard>("StrongSpell", 0, Effects(10)));
        weakDeck.addCard(std::make_unique<SpellCard>("WeakSpell", 1, Effects(1)));
    }

    player1.giveDeck(std::move(strongDeck));
    player2.giveDeck(std::move(weakDeck));

    while (player1.getHealth() > 0 && player2.getHealth() > 0)
    {
        player1.drawCard();
        player1.playCard(0);

        player2.drawCard();
        player2.playCard(0);
    }

    return 0;
}