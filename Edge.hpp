// coheny405@gmail.com
#pragma once 

#include <iostream>
#include <vector>


// Forward declaration
class Vertex;
class RoadPiece;

class Edge {
    
    private:
    int EdgeId;
    std::vector <Vertex*> edgeVertices;
    std::vector<Edge*> connectedEdges;
    RoadPiece* piece;
    
    public:
        // Constructor
        Edge();
        Edge(int EdgeId);
        
        // Set & Get edge's vertex.
        void setVertices(Vertex* v1, Vertex* v2);
        const std::vector<Vertex*>& getVertices() const;

        // Function is connected to vertex
        bool isConnectedToVertex(Vertex* vertex) const;

        // Set & Get connected edges to the edge.
        void setConnectedEdges(Edge* e1, Edge* e2, Edge* e3, Edge* e4);
        const std::vector<Edge*>& getConnectedEdges() const;

        int getId() const;

        // Bind and Get piece on the Edge
        int bindRoadPiece(RoadPiece* piece);
        RoadPiece* getRoadPiece () const; 


        

    };