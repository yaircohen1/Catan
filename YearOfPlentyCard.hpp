// coheny405@gmail.com
#pragma once

#include "Card.hpp"

class YearOfPlentyCard : public Card {
public:
    YearOfPlentyCard();
    std::string getDescription() const override;
    CardType getType() const override;
    bool operator==(const Card& other) const override;
    void use(Player& player);
    void use(Player& player, ResourceType resource1, ResourceType resource2); // Overloaded use function for testing
};