// coheny405@gmail.com
#include "Edge.hpp"

Edge::Edge() : EdgeId(-1), piece(nullptr) {
    edgeVertices.resize(2, nullptr);
    connectedEdges.resize(4, nullptr);
}

Edge::Edge(int EdgeId) : EdgeId(EdgeId), piece(nullptr) {
    edgeVertices.resize(2, nullptr);
    connectedEdges.resize(4, nullptr);
}

void Edge::setVertices(Vertex* v1, Vertex* v2) {
    edgeVertices[0] = v1;
    edgeVertices[1] = v2;  
}

const std::vector<Vertex*>& Edge::getVertices() const {
    return edgeVertices;
}

bool Edge::isConnectedToVertex(Vertex* vertex) const {
    return edgeVertices[0] == vertex || edgeVertices[1] == vertex;
}

void Edge::setConnectedEdges(Edge* e1, Edge* e2, Edge* e3, Edge* e4) {
    connectedEdges[0] = e1;
    connectedEdges[1] = e2;
    connectedEdges[2] = e3;
    connectedEdges[3] = e4;
}

const std::vector<Edge*>& Edge::getConnectedEdges() const {
    return connectedEdges;
}

int Edge::getId() const {
    return EdgeId;
}

int Edge::bindRoadPiece(RoadPiece* piece) {
    if(this->piece != nullptr) {
        std::cerr << "Edge " << EdgeId << " already has a road piece on it." << std::endl;
        return 0;
    }   
    this->piece = piece;
    return 1;
}

RoadPiece* Edge::getRoadPiece() const {
    return piece;
}