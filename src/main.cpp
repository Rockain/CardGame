#include <iostream>
#include <memory>
#include <random>

#include "Random.h"
#include "Player.h"
#include "CardFactory.h"

int main()
{
    Random random;
    CardFactory cardFactory;

    Player player1("Player 1");
    Player player2("Player 2");

    Deck deck1;
    Deck deck2;

    for (int i = 0; i < 20; i++)
    {
        deck1.addCard(cardFactory.createCard(DRAIN));

        if (i%2 == 0)
        {
            deck2.addCard(cardFactory.createCard(FIREBALL));
            deck2.addCard(cardFactory.createCard(REGROW_FLESH));
        }
    }

    player1.giveDeck(std::move(deck1));
    player1.draw(4);

    player2.giveDeck(std::move(deck2));
    player2.draw(5);

    int turn = 0;
    while ((player1.getHealth() > 0 && player2.getHealth() > 0) && turn < 50)
    {
        std::cout << "### Turn " << ++turn << " ###" << std::endl;
        player1.draw(1);
        player1.playCard(random.getInt(0, player1.getHandSize()), &player2);

        player2.draw(1);
        player2.playCard(random.getInt(0, player2.getHandSize()), &player1);
    }

    if (player1.getHealth() == 0 && player2.getHealth() == 0)
    {
        std::cout << "EGALITY" << std::endl;
    }
    if (player1.getHealth() == 0)
    {
        std::cout << "PLAYER 2 WIN" << std::endl;
    }
    if (player2.getHealth() == 0)
    {
        std::cout << "PLAYER 1 WIN" << std::endl;
    }

    return 0;
}