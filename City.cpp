// coheny405@gmail.com
#include "City.hpp"

City::City(Player* owner) {
    this->owner = owner;
    this->V = nullptr;
}

City::City(Player* owner, Vertex* vertex) {
    this->owner = owner;
    this->V = vertex;
}

void City::getDescription() const {
    std::cout << "City in " << V->getId() << " owned by player " << owner->getPlayerName() << std::endl;
}

AreaPieceType City::getType() const {
    return AreaPieceType::CITY;
}

int City::bindVertex(Vertex* vertex) {
    V = vertex;
    return 1;
}

