// coheny405@gmail.com
#include "YearOfPlentyCard.hpp"
#include "ResourceType.hpp"
#include "Player.hpp"


YearOfPlentyCard::YearOfPlentyCard() {
    this->type = CardType::YEAR_OF_PLENTY;
}

std::string YearOfPlentyCard::getDescription() const {
    return "Congratulations! You can choose two resources from the resources cards.";
}

CardType YearOfPlentyCard::getType() const {
     return CardType::YEAR_OF_PLENTY;
}

bool YearOfPlentyCard::operator==(const Card& other) const {
    return other.getType() == CardType::YEAR_OF_PLENTY;
}

void YearOfPlentyCard::use(Player& player, ResourceType resource1, ResourceType resource2) {
    player.addResource(resource1, 1);
    player.addResource(resource2, 1);
    player.removeCard(this);
}

void YearOfPlentyCard::use(Player& player) {
    ResourceType resource1 = player.getResourceInput();
    ResourceType resource2 = player.getResourceInput();
    if (resource1 != ResourceType::SEABORDER && resource2 != ResourceType::SEABORDER) {
        player.addResource(resource1, 1);
        player.addResource(resource2, 1);
        player.removeCard(this);
    } else {
        return;
    }
}