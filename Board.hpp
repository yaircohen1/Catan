// coheny405@gmail.com
#pragma once

#include <vector>
#include <iostream>
#include <map>

#include "Vertex.hpp"
#include "Edge.hpp"
#include "Settlement.hpp"
#include "City.hpp"
#include "RoadPiece.hpp"
#include "ResourceType.hpp"

class Board {
private:
    static constexpr int numVertices = 54;
    static constexpr int numEdges = 72;
    std::vector<Vertex> vertices; // List of all vertices
    std::vector<Edge> edges; // List of all edges

    // Private constructor to prevent instantiation
    Board();

    // Delete copy constructor and assignment operator
    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;
    

public:
    // Static method to get the singleton instance
    static Board& getInstance();

    // Destructor
    ~Board() = default;

    // Function to initialize the board
    void initializeBoard();

    // Function to get all vertices
    std::vector<Vertex>& getVertices();
    
    // Function to get a vertex by ID
    Vertex& getVertex(int id);
    
    // Function to get an edge by ID
    Edge& getEdge(int id);

    // Function to get random number
    int getRandomNumber();
};

