// coheny405@gmail.com
#include "KnightCard.hpp"

std::string KnightCard::getDescription() const {
    return "Get 3 'KNIGHT' cards to get 2 victory points!";
}

CardType KnightCard::getType() const {
     return CardType::KNIGHTS;
}

bool KnightCard::operator==(const Card& other) const {
    return other.getType() == CardType::KNIGHTS;
}