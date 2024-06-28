// coheny405@gmail.com
#pragma once

#include "Card.hpp"

class Player;  // Forward declaration


class MonopolyCard : public Card {
public:
    MonopolyCard();
    std::string getDescription() const override;
    CardType getType() const override;
    bool operator==(const Card& other) const override;
    void use(Player& player);
    void use(Player& player, ResourceType resource); // Overloaded use function for testing
};