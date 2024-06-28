// coheny405@gmail.com
#pragma once

#include "AreaPiece.hpp"
#include "Vertex.hpp"


class City : public AreaPiece {
public:
    // Constructor
    City(Player* owner);

    City(Player* owner, Vertex* vertex);

    ~City() {};

    // Functions
    void getDescription() const override;

    AreaPieceType getType() const override;

    int bindVertex(Vertex* vertex) override;
};


