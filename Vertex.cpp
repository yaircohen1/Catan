// coheny405@gmail.com
#include "Vertex.hpp"
#include "Edge.hpp"
#include "AreaPiece.hpp"
#include "ResourceType.hpp"


Vertex::Vertex() : VertexId(0), piece(nullptr) {}

Vertex::Vertex(int index) : VertexId(index), piece(nullptr), connectedEdges(3, nullptr), connectedResources(3){}

Vertex::~Vertex() {
    delete piece;
}

int Vertex::getId() const {
    return VertexId;
}

 void Vertex::setConnectedEdge(Edge* edge1, Edge* edge2, Edge* edge3) {
    connectedEdges[0] = edge1;
    connectedEdges[1] = edge2;
    connectedEdges[2] = edge3;
 }

std::vector<Edge*> Vertex::getConnectedEdges() const {
    return connectedEdges;
}

 void Vertex::setResource(std::pair<int, ResourceType> resource1, std::pair<int, ResourceType> resource2, std::pair<int, ResourceType> resource3) {
    connectedResources[0] = resource1;
    connectedResources[1] = resource2;
    connectedResources[2] = resource3;
 }
 
 std::vector<std::pair<int, ResourceType>> Vertex::getResources() const {
    std::vector<std::pair<int, ResourceType>> filteredResources;
    std::copy_if(connectedResources.begin(), connectedResources.end(), std::back_inserter(filteredResources),
                 [](const std::pair<int, ResourceType>& resource) {
                     return resource.second != ResourceType::SEABORDER && resource.second != ResourceType::DESERT;
                 });
    return filteredResources;
}


int Vertex::bindPiece(AreaPiece* newPiece) { 
   if (piece != nullptr) {
            std::cerr << "Vertex " << VertexId << " already has a piece on it." << std::endl;
            return 0;
        }
        piece = newPiece;
        return 1;
    }

AreaPiece* Vertex::getPiece() const {
    return piece;
}

void Vertex::SetPiece(AreaPiece* newPiece) {
    piece = newPiece;
}

void Vertex::removePiece() {
    piece = nullptr;
} 

