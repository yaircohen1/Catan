// coheny405@gmail.com
#pragma once 

#include <iostream>
#include <string>

class Player; // Forward declaration
class Edge; // Forward declaration

class RoadPiece {
private:
    Player* owner; // Piece's owner
    Edge* E; // Piece's Edge

public:
    // Constructor
    RoadPiece(Player* owner);
    
    // Destructor
    ~RoadPiece() {} // Don't delete owner and edge since they are managed elsewhere

    // Function for getting description about the piece
    void getDescription() const;

    // Function for getting the owner of the piece
    Player* getOwner() const {
        return owner;
    }

    // Function for setting the owner of the piece
    void setOwner(Player* newOwner) { 
        owner = newOwner;
    }

    // Function to get the edge ID of the piece
    int getEID() const;

    // Function to set the edge of the piece
    int bindEdge(Edge* edge);

};