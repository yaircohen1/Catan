// coheny405@gmail.com
#pragma once 
#include "Card.hpp"

class KnightCard : public Card {
    public:
    KnightCard(){};
    std::string getDescription() const override;
    CardType getType() const override;
    bool operator==(const Card& other) const override;

};