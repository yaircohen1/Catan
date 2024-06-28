// coheny405@gmail.com
#include "RoadPiece.hpp"
#include "Player.hpp"
#include "Edge.hpp"


RoadPiece::RoadPiece(Player* owner) : owner(owner), E(nullptr) {}


void RoadPiece::getDescription() const {
    std::cout << "Road on edge " << E->getId() << " owned by player " << owner->getPlayerName() << std::endl;
}

int RoadPiece::getEID() const {
    return E->getId();
}

int RoadPiece::bindEdge(Edge* edge) {
        if (E != nullptr) {
            std::cerr << "Error: Edge already set for road piece" << std::endl;
            return 0;
        }
        E = edge;
        return 1;
    }