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

    int turn = 0;
    while (player1.getHealth() > 0 && player2.getHealth() > 0)
    {
        std::cout << "### Turn " << ++turn << " ###" << std::endl;
        player1.draw(1);
        player1.playCard(0, &player2);

        player2.draw(1);
        player2.playCard(0, &player1);
    }

    return 0;
}