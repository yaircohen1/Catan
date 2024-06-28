// coheny405@gmail.com
#pragma once 
#include "Card.hpp"

enum class ResourceType;

class VictoryPointCard : public Card {
    public:
    VictoryPointCard(){};
    std::string getDescription() const override;
    CardType getType() const override;
    bool operator==(const Card &other) const;
};