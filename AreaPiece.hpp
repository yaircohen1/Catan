// coheny405@gmail.com

#pragma once 

#include <iostream>
#include <string>

#include "Vertex.hpp"
#include "Player.hpp"

// Forward declaration
class Vertex;
class Player;


enum class AreaPieceType {
   SETTLEMENT,
   CITY
};

class AreaPiece {
protected:
    Player* owner; // Piece's owner
    Vertex* V; // Piece's vertex

public:
    // Destructor
    virtual ~AreaPiece() {} // Not delete owner and vertex since they are managed elsewhere

    // Pure virtual function for getting description about the piece
    virtual void getDescription() const = 0;

    // Pure virtual function for getting the type of piece
    virtual AreaPieceType getType() const = 0;

    // Function for getting the owner of the piece
    Player* getOwner() const {
        return owner;
    }

    // Function for setting the owner of the piece
    void setOwner(Player* newOwner) { 
        owner = newOwner;
    }

    // Function to get the vertex ID of the piece
    int getVID() const {
            return V->getId();
    }

     Vertex* getVertex() const {
        return V;
    }

    // Function to set the vertex of the piece
    virtual int bindVertex(Vertex* vertex) = 0;


};