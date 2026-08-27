#pragma once

#include <memory>
#include "Card.h"
#include "CardNames.h"

class CardFactory
{
    public:
        CardFactory() = default;

        std::unique_ptr<Card> createCard(CARD_NAME cardName);
};