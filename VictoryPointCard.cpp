// coheny405@gmail.com
#include "VictoryPointCard.hpp"


std::string VictoryPointCard::getDescription() const {
    return "Congratulations! You got a victory point.";
}

CardType VictoryPointCard::getType() const {
     return CardType::VICTORY_POINT;
}

bool VictoryPointCard::operator==(const Card& other) const {
    return other.getType() == CardType::VICTORY_POINT;
}