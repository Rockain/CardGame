#include <iostream>
#include <memory>
#include <random>

#include "Random.h"
#include "Player.h"
#include "DamageSpell.h"
#include "HealSpell.h"

int main()
{
    Random random;

    Player player1("Player 1");
    Player player2("Player 2");

    Deck deck1;
    Deck deck2;

    for (int i = 0; i < 10; i++)
    {
        deck1.addCard(std::make_unique<DamageSpell>("Fireball", 0, Effects(15)));
        deck1.addCard(std::make_unique<HealSpell>("LickWound", 1, Effects(0, 1)));

        deck2.addCard(std::make_unique<DamageSpell>("WaterWhip", 1, Effects(5)));
        deck2.addCard(std::make_unique<HealSpell>("RegrowFlesh", 0, Effects(0, 5)));
    }

    player1.giveDeck(std::move(deck1));
    player1.draw(4);

    player2.giveDeck(std::move(deck2));
    player2.draw(5);

    int turn = 0;
    while (player1.getHealth() > 0 && player2.getHealth() > 0)
    {
        unsigned int test = random.getInt(0, player1.getHandSize());

        std::cout << "### Turn " << ++turn << " ###" <<test << std::endl;
        player1.draw(1);
        player1.playCard(rand() % player1.getHandSize(), &player2);

        player2.draw(1);
        player2.playCard(rand() % player2.getHandSize(), &player1);
    }

    return 0;
}