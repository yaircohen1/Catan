// coheny405@gmail.com
#pragma once 

#include <iostream>
#include <vector>
#include <utility> // For std::pair
#include <algorithm> // For std::find

// Forward declarations
class AreaPiece;
class Edge;
enum class ResourceType;

class Vertex {
private:
    int VertexId; // Identifier of the vertex.
    AreaPiece* piece;
    std::vector<Edge*> connectedEdges; // Connected edges to this vertex.
    std::vector<std::pair<int,ResourceType>> connectedResources; // Pairs of vertex ID and resource type connected to this vertex.

public:
    //Constructors
    Vertex();
    Vertex(int index);

    //Destructor
    ~Vertex(); 

    // Get the id of V
    int getId() const;

    // Set connected edges to the vertex.
    void setConnectedEdge(Edge* edge1, Edge* edge2, Edge* edge3);

    // Get connected edges to the vertex.
    std::vector<Edge*> getConnectedEdges() const;

    //  Set & Get a connected resource to the vertex.
    void setResource(std::pair<int, ResourceType> resource1, std::pair<int, ResourceType> resource2, std::pair<int, ResourceType> resource3);
    std::vector<std::pair<int,ResourceType>> getResources() const;

    
    // Set and Get piece on the vertex
    int bindPiece(AreaPiece* piece);
    AreaPiece* getPiece() const;
    void SetPiece(AreaPiece* piece);

    // Remove piece from the vertex
    void removePiece();

};
