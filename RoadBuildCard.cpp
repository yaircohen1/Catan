// coheny405@gmail.com
#include "RoadBuildCard.hpp"

RoadBuildCard::RoadBuildCard() {
    this->type = CardType::ROAD_BUILDING;
}   

std::string RoadBuildCard::getDescription() const {
    return "Road Building Card";
}

CardType RoadBuildCard::getType() const {
    return this->type;
}

bool RoadBuildCard::operator==(const Card& other) const {
    return this->type == other.getType();
}

void RoadBuildCard::use(Player& player) {
    int choice = player.getInput(2);
    player.buildRoad(choice, false);
    choice = player.getInput(2);
    player.buildRoad(choice, false);
    player.removeCard(this);
}

void RoadBuildCard::use(Player& player, int edgeID1, int edgeID2) {
    player.buildRoad(edgeID1, false);
    player.buildRoad(edgeID2, false);
    player.removeCard(this);
}


