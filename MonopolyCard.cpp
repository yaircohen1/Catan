// coheny405@gmail.com
#include "MonopolyCard.hpp"
#include "Player.hpp"
#include "Catan.hpp"
#include "ResourceType.hpp"

MonopolyCard::MonopolyCard() {
    this->type = CardType::MONOPOLY;
}

std::string MonopolyCard::getDescription() const {
    return "Congratulations! You can choose a resource and take all the resources of that type from the other players.";
}

CardType MonopolyCard::getType() const {
    return CardType::MONOPOLY;
}

bool MonopolyCard::operator==(const Card& other) const {
    return other.getType() == CardType::MONOPOLY;
}

void MonopolyCard::use(Player& player) {
    ResourceType resource = player.getResourceInput();
    if (resource == ResourceType::SEABORDER) {
        return;
    }
    for (auto& otherPlayer : player.getCatanGame().getPlayers()) {
        if (otherPlayer->getPlayerName() != player.getPlayerName()) {
            int amount = otherPlayer->getResourceCount(resource);
            otherPlayer->removeResource(resource, amount);
            player.addResource(resource, amount);
        }
    }
    player.removeCard(this);         
}  

void MonopolyCard::use(Player& player, ResourceType resource) {
    for (auto& otherPlayer : player.getCatanGame().getPlayers()) {
        if (otherPlayer->getPlayerName() != player.getPlayerName()) {
            int amount = otherPlayer->getResourceCount(resource);
            otherPlayer->removeResource(resource, amount);
            player.addResource(resource, amount);
        }
    }
    player.removeCard(this);         
}

   
    
    
    