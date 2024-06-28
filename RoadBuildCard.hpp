// coheny405@gmail.com
#pragma once

#include "Card.hpp"

class RoadBuildCard : public Card {
public:
    RoadBuildCard();
    std::string getDescription() const override;
    CardType getType() const override;
    bool operator==(const Card& other) const override;
    void use(Player& player);
    void use(Player& player, int edgeID1, int edgeID2); // Overloaded use function for testing
};