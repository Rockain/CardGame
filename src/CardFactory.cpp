#include "CardFactory.h"

#include "HealEffect.h"
#include "DamageEffect.h"

std::unique_ptr<Card> CardFactory::createCard(CARD_NAME cardName)
{
    std::string name;
    unsigned int cost;
    std::vector<std::unique_ptr<Effect>> effects;

    switch (cardName)
    {
        case FIREBALL:
            name = "Fireball";
            cost = 1;
            effects.emplace_back(std::make_unique<DamageEffect>(15));
            break;
        case REGROW_FLESH:
            name = "Regrow Flesh";
            cost = 0;
            effects.emplace_back(std::make_unique<HealEffect>(5));
            break;
        case DRAIN:
            name = "Drain";
            cost = 1;
            effects.emplace_back(std::make_unique<HealEffect>(5));
            effects.emplace_back(std::make_unique<DamageEffect>(15));
            break;
        default:
            name = "Unknown";
            cost = 0;
            break;
    }

    return std::make_unique<Card>(name, cost, std::move(effects));
}