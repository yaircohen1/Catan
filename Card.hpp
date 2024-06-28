// coheny405@gmail.com
#pragma once
#include <iostream>
#include <string>

#include "Player.hpp"


enum class CardType {
    ROAD_BUILDING,
    YEAR_OF_PLENTY,
    MONOPOLY,
    KNIGHTS,
    VICTORY_POINT
};

class Card {
    protected:
        CardType type;
    public: 
        virtual ~Card() = default;
        virtual std:: string getDescription() const = 0;
        virtual CardType getType() const = 0;
        std::string getCardType() {
            switch (type) {
                case CardType::ROAD_BUILDING:
                    return "Road Building";
                case CardType::YEAR_OF_PLENTY:
                    return "Year of Plenty";
                case CardType::MONOPOLY:
                    return "Monopoly";
                case CardType::KNIGHTS:
                    return "Knight";
                case CardType::VICTORY_POINT:
                    return "Victory Point";
                default: 
                    return "Unknown";
            }
        }

        // Operator== for comparison
        virtual bool operator==(const Card& other) const = 0;



};