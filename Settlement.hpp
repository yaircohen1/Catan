// coheny405@gmail.com
#pragma once 

#include "AreaPiece.hpp"
#include "Vertex.hpp"

class Settlement : public AreaPiece {
    public:
    // Constructor
    Settlement(Player* owner);

    Settlement(Player* owner, Vertex* vertex);

    // Destructor
    ~Settlement() {};

    // Functions
    void getDescription() const override;

    AreaPieceType getType() const override;

    int bindVertex(Vertex* vertex) override;

};