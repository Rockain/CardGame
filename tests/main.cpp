#include <iostream>
#include <memory>
#include <cassert>

#include "Card.h"
#include "CardFactory.h"

int main()
{
    std::cout << "=========== TESTS ==========" << std::endl;

    CardFactory cardFactory;

    std::unique_ptr<Card> drainCard    = cardFactory.createCard(DRAIN);
    std::unique_ptr<Card> fireballCard = cardFactory.createCard(FIREBALL);

    assert(drainCard->getName() == "Drain");
    assert(drainCard->getCost() == 1);
    assert(drainCard->getNbEffects() == 2);

    assert(fireballCard->getName() == "Fireball");
    assert(fireballCard->getCost() == 1);
    assert(fireballCard->getNbEffects() == 1);


    return 0;
}