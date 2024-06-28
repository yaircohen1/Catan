// coheny405@gmail.com

#include "Settlement.hpp"
#include "City.hpp" 

Settlement::Settlement(Player* owner) {
    this->owner = owner;
    this->V = nullptr; 
}

Settlement::Settlement(Player* owner, Vertex* vertex){
    this->owner = owner;
    this->V = vertex;
}    

void Settlement::getDescription() const {
     std::cout << "Settlement in" << V->getId() << "owned by player " << owner->getPlayerName() << std::endl;
}

AreaPieceType Settlement::getType() const {
     return AreaPieceType::SETTLEMENT;
}

 int Settlement::bindVertex(Vertex* vertex) {
        if (V != nullptr) {
            std::cout << "Error: Vertex already set for settlement" << std::endl;
            return 0;
        }
        V = vertex;
        return 1;
    }





