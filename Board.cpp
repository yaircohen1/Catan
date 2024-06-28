// coheny405@gmail.com
#include "Board.hpp"

// Private constructor
Board::Board() {
    vertices.resize(numVertices);
    edges.resize(numEdges);
    initializeBoard();
}

// Static method to get the singleton instance
Board& Board::getInstance() {
    static Board instance;
    return instance;
}

void Board::initializeBoard() {
    // Initialize vertices
    for (int i = 0; i < numVertices; ++i) {
        vertices[i] = Vertex(i);
    }

    // Initialize edges
    for (int i = 0; i < numEdges; ++i) {
        edges[i] = Edge(i);
    }

    // connect each vertice to edges
    vertices[0].setConnectedEdge(&edges[0], &edges[1], nullptr);
    vertices[1].setConnectedEdge(&edges[2], &edges[3], nullptr);
    vertices[2].setConnectedEdge(&edges[4], &edges[5], nullptr);

    vertices[3].setConnectedEdge(&edges[0], &edges[6], nullptr);
    vertices[4].setConnectedEdge(&edges[1], &edges[2], &edges[7]);
    vertices[5].setConnectedEdge(&edges[3], &edges[4], &edges[8]);
    vertices[6].setConnectedEdge(&edges[5], &edges[9], nullptr);
    
    vertices[7].setConnectedEdge(&edges[6], &edges[10], &edges[11]);
    vertices[8].setConnectedEdge(&edges[7], &edges[12], &edges[13]);
    vertices[9].setConnectedEdge(&edges[8], &edges[14], &edges[15]);
    vertices[10].setConnectedEdge(&edges[9], &edges[16], &edges[17]);

    vertices[11].setConnectedEdge(&edges[10], &edges[18], nullptr);
    vertices[12].setConnectedEdge(&edges[11], &edges[12], &edges[19]);
    vertices[13].setConnectedEdge(&edges[13], &edges[14], &edges[20]);
    vertices[14].setConnectedEdge(&edges[15], &edges[16], &edges[21]);
    vertices[15].setConnectedEdge(&edges[17], &edges[22], nullptr);

    vertices[16].setConnectedEdge(&edges[18], &edges[23], &edges[24]);
    vertices[17].setConnectedEdge(&edges[19], &edges[25], &edges[26]);
    vertices[18].setConnectedEdge(&edges[20], &edges[27], &edges[28]);
    vertices[19].setConnectedEdge(&edges[21], &edges[29], &edges[30]);
    vertices[20].setConnectedEdge(&edges[22], &edges[31], &edges[32]);

    vertices[21].setConnectedEdge(&edges[23], &edges[33], nullptr);
    vertices[22].setConnectedEdge(&edges[24], &edges[25], &edges[34]);
    vertices[23].setConnectedEdge(&edges[26], &edges[27], &edges[35]);
    vertices[24].setConnectedEdge(&edges[28], &edges[29], &edges[36]);
    vertices[25].setConnectedEdge(&edges[30], &edges[31], &edges[37]);
    vertices[26].setConnectedEdge(&edges[32], &edges[38], nullptr);

    vertices[27].setConnectedEdge(&edges[33], &edges[39], nullptr);
    vertices[28].setConnectedEdge(&edges[34], &edges[40], &edges[41]);
    vertices[29].setConnectedEdge(&edges[35], &edges[42], &edges[43]);
    vertices[30].setConnectedEdge(&edges[36], &edges[44], &edges[45]);
    vertices[31].setConnectedEdge(&edges[37], &edges[46], &edges[47]);
    vertices[32].setConnectedEdge(&edges[38], &edges[48], nullptr);

    vertices[33].setConnectedEdge(&edges[39], &edges[40], &edges[49]);
    vertices[34].setConnectedEdge(&edges[41], &edges[42], &edges[50]);
    vertices[35].setConnectedEdge(&edges[43], &edges[44], &edges[51]);
    vertices[36].setConnectedEdge(&edges[45], &edges[46], &edges[52]);
    vertices[37].setConnectedEdge(&edges[47], &edges[48], &edges[53]);

    vertices[38].setConnectedEdge(&edges[49], &edges[54], nullptr);
    vertices[39].setConnectedEdge(&edges[50], &edges[55], &edges[56]);
    vertices[40].setConnectedEdge(&edges[51], &edges[57], &edges[58]);
    vertices[41].setConnectedEdge(&edges[52], &edges[59], &edges[60]);
    vertices[42].setConnectedEdge(&edges[53], &edges[61], nullptr);

    vertices[43].setConnectedEdge(&edges[54], &edges[55], &edges[62]);
    vertices[44].setConnectedEdge(&edges[56], &edges[57], &edges[63]);
    vertices[45].setConnectedEdge(&edges[58], &edges[59], &edges[64]);
    vertices[46].setConnectedEdge(&edges[60], &edges[61], &edges[65]);

    vertices[47].setConnectedEdge(&edges[62], &edges[66], nullptr);
    vertices[48].setConnectedEdge(&edges[63], &edges[67], &edges[68]);
    vertices[49].setConnectedEdge(&edges[64], &edges[69], &edges[70]);
    vertices[50].setConnectedEdge(&edges[65], &edges[71], nullptr);

    vertices[51].setConnectedEdge(&edges[66], &edges[67], nullptr);
    vertices[52].setConnectedEdge(&edges[68], &edges[69], nullptr);
    vertices[53].setConnectedEdge(&edges[70], &edges[71], nullptr);

    // Connect each edge to vertices and other edges
    edges[0].setConnectedEdges(&edges[1], &edges[6], nullptr, nullptr);
    edges[1].setConnectedEdges(&edges[0], &edges[2], &edges[7], nullptr);
    edges[2].setConnectedEdges(&edges[1], &edges[7], &edges[3], nullptr);
    edges[3].setConnectedEdges(&edges[2], &edges[8], &edges[4], nullptr);
    edges[4].setConnectedEdges(&edges[3], &edges[8], &edges[5], nullptr);
    edges[5].setConnectedEdges(&edges[4], &edges[9], nullptr, nullptr);

    edges[0].setVertices(&vertices[0], &vertices[3]);
    edges[1].setVertices(&vertices[0], &vertices[4]);
    edges[2].setVertices(&vertices[1], &vertices[4]);
    edges[3].setVertices(&vertices[1], &vertices[5]);
    edges[4].setVertices(&vertices[2], &vertices[5]);
    edges[5].setVertices(&vertices[2], &vertices[6]);


    edges[6].setConnectedEdges(&edges[0], &edges[10], &edges[11], nullptr);
    edges[7].setConnectedEdges(&edges[1], &edges[2], &edges[12], &edges[13]);
    edges[8].setConnectedEdges(&edges[3], &edges[4], &edges[14], &edges[15]);
    edges[9].setConnectedEdges(&edges[5], &edges[16], &edges[17], nullptr);

    edges[6].setVertices(&vertices[3], &vertices[7]);
    edges[7].setVertices(&vertices[4], &vertices[8]);
    edges[8].setVertices(&vertices[5], &vertices[9]);
    edges[9].setVertices(&vertices[6], &vertices[10]);

    edges[10].setConnectedEdges(&edges[6], &edges[11], &edges[18], nullptr);
    edges[11].setConnectedEdges(&edges[6], &edges[10], &edges[12], &edges[19]);
    edges[12].setConnectedEdges(&edges[7], &edges[11], &edges[13], &edges[19]);
    edges[13].setConnectedEdges(&edges[7], &edges[12], &edges[14], &edges[20]);
    edges[14].setConnectedEdges(&edges[8], &edges[13], &edges[15], &edges[20]);
    edges[15].setConnectedEdges(&edges[8], &edges[14], &edges[16], &edges[21]);
    edges[16].setConnectedEdges(&edges[9], &edges[15], &edges[17], &edges[21]);
    edges[17].setConnectedEdges(&edges[9], &edges[16], &edges[22], nullptr);

    edges[10].setVertices(&vertices[7], &vertices[11]);
    edges[11].setVertices(&vertices[7], &vertices[12]);
    edges[12].setVertices(&vertices[8], &vertices[12]);
    edges[13].setVertices(&vertices[8], &vertices[13]);
    edges[14].setVertices(&vertices[9], &vertices[13]);
    edges[15].setVertices(&vertices[9], &vertices[14]);
    edges[16].setVertices(&vertices[10], &vertices[14]);
    edges[17].setVertices(&vertices[10], &vertices[15]);


    edges[18].setConnectedEdges(&edges[10], &edges[23], &edges[24], nullptr);
    edges[19].setConnectedEdges(&edges[11], &edges[12], &edges[25], &edges[26]);
    edges[20].setConnectedEdges(&edges[13], &edges[14], &edges[27], &edges[28]);
    edges[21].setConnectedEdges(&edges[15], &edges[16], &edges[29], &edges[30]);
    edges[22].setConnectedEdges(&edges[17], &edges[31], &edges[32], nullptr);

    edges[18].setVertices(&vertices[11], &vertices[16]);
    edges[19].setVertices(&vertices[12], &vertices[17]);
    edges[20].setVertices(&vertices[13], &vertices[18]);
    edges[21].setVertices(&vertices[14], &vertices[19]);
    edges[22].setVertices(&vertices[15], &vertices[20]);


    edges[23].setConnectedEdges(&edges[18], &edges[24], &edges[33], nullptr);
    edges[24].setConnectedEdges(&edges[18], &edges[23], &edges[25], &edges[34]);
    edges[25].setConnectedEdges(&edges[19], &edges[24], &edges[26], &edges[34]);
    edges[26].setConnectedEdges(&edges[19], &edges[25], &edges[27], &edges[35]);
    edges[27].setConnectedEdges(&edges[20], &edges[26], &edges[28], &edges[35]);
    edges[28].setConnectedEdges(&edges[20], &edges[27], &edges[29], &edges[36]);
    edges[29].setConnectedEdges(&edges[21], &edges[28], &edges[30], &edges[36]);
    edges[30].setConnectedEdges(&edges[21], &edges[29], &edges[31], &edges[37]);
    edges[31].setConnectedEdges(&edges[22], &edges[30], &edges[32], &edges[37]);
    edges[32].setConnectedEdges(&edges[22], &edges[31], &edges[38], nullptr);

    edges[23].setVertices(&vertices[16], &vertices[21]);
    edges[24].setVertices(&vertices[16], &vertices[22]);
    edges[25].setVertices(&vertices[17], &vertices[22]);
    edges[26].setVertices(&vertices[17], &vertices[23]);
    edges[27].setVertices(&vertices[18], &vertices[23]);
    edges[28].setVertices(&vertices[18], &vertices[24]);
    edges[29].setVertices(&vertices[19], &vertices[24]);
    edges[30].setVertices(&vertices[19], &vertices[25]);
    edges[31].setVertices(&vertices[20], &vertices[25]);
    edges[32].setVertices(&vertices[20], &vertices[26]);

   
    edges[33].setConnectedEdges(&edges[23], &edges[39], nullptr, nullptr);
    edges[34].setConnectedEdges(&edges[24], &edges[25], &edges[40], &edges[41]);
    edges[35].setConnectedEdges(&edges[26], &edges[27], &edges[42], &edges[43]);
    edges[36].setConnectedEdges(&edges[28], &edges[29], &edges[44], &edges[45]);
    edges[37].setConnectedEdges(&edges[30], &edges[31], &edges[46], &edges[47]);
    edges[38].setConnectedEdges(&edges[32], &edges[48], nullptr, nullptr);

    edges[33].setVertices(&vertices[21], &vertices[27]);
    edges[34].setVertices(&vertices[22], &vertices[28]);
    edges[35].setVertices(&vertices[23], &vertices[29]);
    edges[36].setVertices(&vertices[24], &vertices[30]);
    edges[37].setVertices(&vertices[25], &vertices[31]);
    edges[38].setVertices(&vertices[26], &vertices[32]);

    
    edges[39].setConnectedEdges(&edges[33], &edges[40], &edges[49], nullptr);
    edges[40].setConnectedEdges(&edges[34], &edges[39], &edges[41], &edges[49]);
    edges[41].setConnectedEdges(&edges[34], &edges[40], &edges[42], &edges[50]);
    edges[42].setConnectedEdges(&edges[35], &edges[41], &edges[43], &edges[50]);
    edges[43].setConnectedEdges(&edges[35], &edges[42], &edges[44], &edges[51]);
    edges[44].setConnectedEdges(&edges[36], &edges[43], &edges[45], &edges[51]);
    edges[45].setConnectedEdges(&edges[36], &edges[44], &edges[46], &edges[52]);
    edges[46].setConnectedEdges(&edges[37], &edges[45], &edges[47], &edges[52]);
    edges[47].setConnectedEdges(&edges[37], &edges[46], &edges[48], &edges[53]);
    edges[48].setConnectedEdges(&edges[38], &edges[47], &edges[53], nullptr);

    edges[39].setVertices(&vertices[27], &vertices[33]);
    edges[40].setVertices(&vertices[28], &vertices[33]);
    edges[41].setVertices(&vertices[28], &vertices[34]);
    edges[42].setVertices(&vertices[29], &vertices[34]);
    edges[43].setVertices(&vertices[29], &vertices[35]);
    edges[44].setVertices(&vertices[30], &vertices[35]);
    edges[45].setVertices(&vertices[30], &vertices[36]);
    edges[46].setVertices(&vertices[31], &vertices[36]);
    edges[47].setVertices(&vertices[31], &vertices[37]);
    edges[48].setVertices(&vertices[32], &vertices[37]);

   
    edges[49].setConnectedEdges(&edges[39], &edges[50], &edges[54], nullptr);
    edges[50].setConnectedEdges(&edges[41], &edges[42], &edges[55], &edges[56]);
    edges[51].setConnectedEdges(&edges[43], &edges[44], &edges[57], &edges[58]);
    edges[52].setConnectedEdges(&edges[45], &edges[46], &edges[59], &edges[60]);
    edges[53].setConnectedEdges(&edges[47], &edges[48], &edges[61], nullptr);

    edges[49].setVertices(&vertices[33], &vertices[38]);
    edges[50].setVertices(&vertices[34], &vertices[39]);
    edges[51].setVertices(&vertices[35], &vertices[40]);
    edges[52].setVertices(&vertices[36], &vertices[41]);
    edges[53].setVertices(&vertices[37], &vertices[42]);

    
    edges[54].setConnectedEdges(&edges[49], &edges[55], &edges[62], nullptr);
    edges[55].setConnectedEdges(&edges[50], &edges[54], &edges[56], &edges[62]);
    edges[56].setConnectedEdges(&edges[50], &edges[55], &edges[57], &edges[63]);
    edges[57].setConnectedEdges(&edges[51], &edges[56], &edges[58], &edges[63]);
    edges[58].setConnectedEdges(&edges[51], &edges[57], &edges[59], &edges[64]);
    edges[59].setConnectedEdges(&edges[52], &edges[58], &edges[60], &edges[64]);
    edges[60].setConnectedEdges(&edges[52], &edges[59], &edges[61], &edges[65]);
    edges[61].setConnectedEdges(&edges[53], &edges[60], &edges[65], nullptr);

    edges[54].setVertices(&vertices[38], &vertices[43]);
    edges[55].setVertices(&vertices[39], &vertices[43]);
    edges[56].setVertices(&vertices[39], &vertices[44]);
    edges[57].setVertices(&vertices[40], &vertices[44]);
    edges[58].setVertices(&vertices[40], &vertices[45]);
    edges[59].setVertices(&vertices[41], &vertices[45]);
    edges[60].setVertices(&vertices[41], &vertices[46]);
    edges[61].setVertices(&vertices[42], &vertices[46]);

    
    edges[62].setConnectedEdges(&edges[54], &edges[55], &edges[66], nullptr);
    edges[63].setConnectedEdges(&edges[56], &edges[57], &edges[67], &edges[68]);
    edges[64].setConnectedEdges(&edges[58], &edges[59], &edges[69], &edges[70]);
    edges[65].setConnectedEdges(&edges[60], &edges[61], &edges[71], nullptr);

    edges[62].setVertices(&vertices[43], &vertices[47]);
    edges[63].setVertices(&vertices[44], &vertices[48]);
    edges[64].setVertices(&vertices[45], &vertices[49]);
    edges[65].setVertices(&vertices[46], &vertices[50]);


    edges[66].setConnectedEdges(&edges[62], &edges[67], nullptr, nullptr);
    edges[67].setConnectedEdges(&edges[63], &edges[66], &edges[68], nullptr);
    edges[68].setConnectedEdges(&edges[63], &edges[67], &edges[69], nullptr);
    edges[69].setConnectedEdges(&edges[64], &edges[68], &edges[70], nullptr);
    edges[70].setConnectedEdges(&edges[64], &edges[69], &edges[71], nullptr);
    edges[71].setConnectedEdges(&edges[65], &edges[70], nullptr, nullptr);

    edges[66].setVertices(&vertices[47], &vertices[51]);
    edges[67].setVertices(&vertices[48], &vertices[51]);
    edges[68].setVertices(&vertices[48], &vertices[52]);
    edges[69].setVertices(&vertices[49], &vertices[52]);
    edges[70].setVertices(&vertices[49], &vertices[53]);
    edges[71].setVertices(&vertices[50], &vertices[53]);

    // Initialize resources
    vertices[0].setResource({10, ResourceType::ORE}, {0, ResourceType::SEABORDER}, {0, ResourceType::SEABORDER});
    vertices[1].setResource({2, ResourceType::WOOL}, {0, ResourceType::SEABORDER}, {0, ResourceType::SEABORDER});
    vertices[2].setResource({9, ResourceType::LUMBER}, {0, ResourceType::SEABORDER}, {0, ResourceType::SEABORDER});

    vertices[3].setResource({10, ResourceType::ORE}, {0, ResourceType::SEABORDER}, {0, ResourceType::SEABORDER});
    vertices[4].setResource({10, ResourceType::ORE}, {2, ResourceType::WOOL}, {0, ResourceType::SEABORDER});
    vertices[5].setResource({2, ResourceType::WOOL}, {9, ResourceType::LUMBER}, {0, ResourceType::SEABORDER});
    vertices[6].setResource({9, ResourceType::LUMBER}, {0, ResourceType::SEABORDER}, {0, ResourceType::SEABORDER});
    
    vertices[7].setResource({10, ResourceType::ORE}, {12, ResourceType::GRAIN}, {0, ResourceType::SEABORDER});
    vertices[8].setResource({10, ResourceType::ORE}, {2, ResourceType::WOOL}, {6, ResourceType::BRICK});
    vertices[9].setResource({2, ResourceType::WOOL}, {9, ResourceType::LUMBER}, {4, ResourceType::WOOL});
    vertices[10].setResource({9, ResourceType::LUMBER}, {10, ResourceType::BRICK}, {0, ResourceType::SEABORDER});

    vertices[11].setResource({12, ResourceType::GRAIN}, {0, ResourceType::SEABORDER}, {0, ResourceType::SEABORDER});
    vertices[12].setResource({12, ResourceType::GRAIN}, {10, ResourceType::ORE}, {6, ResourceType::BRICK});
    vertices[13].setResource({2, ResourceType::WOOL}, {6, ResourceType::BRICK}, {4, ResourceType::WOOL});
    vertices[14].setResource({4, ResourceType::WOOL}, {9, ResourceType::LUMBER}, {10, ResourceType::BRICK});
    vertices[15].setResource({10, ResourceType::BRICK}, {0, ResourceType::SEABORDER}, {0, ResourceType::SEABORDER});

    vertices[16].setResource({12, ResourceType::GRAIN}, {9, ResourceType::GRAIN}, {0, ResourceType::SEABORDER});
    vertices[17].setResource({12, ResourceType::GRAIN}, {6, ResourceType::BRICK}, {11, ResourceType::LUMBER});
    vertices[18].setResource({6, ResourceType::BRICK}, {4, ResourceType::WOOL}, {0, ResourceType::DESERT});
    vertices[19].setResource({4, ResourceType::WOOL}, {10, ResourceType::BRICK}, {3, ResourceType::LUMBER});
    vertices[20].setResource({10, ResourceType::BRICK}, {8, ResourceType::ORE}, {0, ResourceType::SEABORDER});

    vertices[21].setResource({9, ResourceType::GRAIN}, {0, ResourceType::SEABORDER}, {0, ResourceType::SEABORDER});
    vertices[22].setResource({12, ResourceType::GRAIN}, {9, ResourceType::GRAIN}, {11, ResourceType::LUMBER});
    vertices[23].setResource({11, ResourceType::LUMBER}, {6, ResourceType::BRICK}, {0, ResourceType::DESERT});
    vertices[24].setResource({4, ResourceType::WOOL}, {3, ResourceType::LUMBER}, {0, ResourceType::DESERT});
    vertices[25].setResource({10, ResourceType::BRICK}, {3, ResourceType::LUMBER}, {8, ResourceType::ORE});
    vertices[26].setResource({8, ResourceType::ORE}, {0, ResourceType::SEABORDER}, {0, ResourceType::SEABORDER});

    vertices[27].setResource({9, ResourceType::GRAIN}, {0, ResourceType::SEABORDER}, {0, ResourceType::SEABORDER});
    vertices[28].setResource({9, ResourceType::GRAIN}, {11, ResourceType::LUMBER}, {8, ResourceType::LUMBER});
    vertices[29].setResource({3, ResourceType::ORE}, {11, ResourceType::LUMBER}, {0, ResourceType::DESERT});
    vertices[30].setResource({3, ResourceType::LUMBER}, {4, ResourceType::GRAIN}, {0, ResourceType::DESERT});
    vertices[31].setResource({3, ResourceType::LUMBER}, {8, ResourceType::ORE}, {5, ResourceType::WOOL});
    vertices[32].setResource({8, ResourceType::ORE}, {0, ResourceType::SEABORDER}, {0, ResourceType::SEABORDER});

    vertices[33].setResource({8, ResourceType::LUMBER}, {9, ResourceType::GRAIN}, {0, ResourceType::SEABORDER});
    vertices[34].setResource({8, ResourceType::LUMBER}, {11, ResourceType::LUMBER}, {3, ResourceType::ORE});
    vertices[35].setResource({3, ResourceType::ORE}, {4, ResourceType::GRAIN}, {0, ResourceType::DESERT});
    vertices[36].setResource({4, ResourceType::GRAIN}, {3, ResourceType::LUMBER}, {5, ResourceType::WOOL});
    vertices[37].setResource({5, ResourceType::WOOL}, {8, ResourceType::ORE}, {0, ResourceType::SEABORDER});

    vertices[38].setResource({8, ResourceType::LUMBER}, {0, ResourceType::SEABORDER}, {0, ResourceType::SEABORDER});
    vertices[39].setResource({8, ResourceType::LUMBER}, {3, ResourceType::ORE}, {5, ResourceType::BRICK});
    vertices[40].setResource({3, ResourceType::ORE}, {6, ResourceType::GRAIN}, {4, ResourceType::GRAIN});
    vertices[41].setResource({4, ResourceType::GRAIN}, {5, ResourceType::WOOL}, {11, ResourceType::WOOL});
    vertices[42].setResource({4, ResourceType::WOOL}, {0, ResourceType::SEABORDER}, {0, ResourceType::SEABORDER});

    vertices[43].setResource({8, ResourceType::LUMBER}, {5, ResourceType::BRICK}, {0, ResourceType::SEABORDER});
    vertices[44].setResource({5, ResourceType::BRICK}, {3, ResourceType::ORE}, {6, ResourceType::GRAIN});
    vertices[45].setResource({6, ResourceType::GRAIN}, {4, ResourceType::GRAIN}, {11, ResourceType::WOOL});
    vertices[46].setResource({5, ResourceType::WOOL}, {11, ResourceType::WOOL}, {0, ResourceType::SEABORDER});

    vertices[47].setResource({5, ResourceType::BRICK}, {0, ResourceType::SEABORDER}, {0, ResourceType::SEABORDER});
    vertices[48].setResource({5, ResourceType::BRICK}, {6, ResourceType::GRAIN}, {0, ResourceType::SEABORDER});
    vertices[49].setResource({6, ResourceType::GRAIN}, {11, ResourceType::WOOL}, {0, ResourceType::SEABORDER});
    vertices[50].setResource({11, ResourceType::WOOL}, {0, ResourceType::SEABORDER}, {0, ResourceType::SEABORDER});

    vertices[51].setResource({5, ResourceType::BRICK}, {0, ResourceType::SEABORDER}, {0, ResourceType::SEABORDER});
    vertices[52].setResource({6, ResourceType::GRAIN}, {0, ResourceType::SEABORDER}, {0, ResourceType::SEABORDER});
    vertices[53].setResource({11, ResourceType::WOOL}, {0, ResourceType::SEABORDER}, {0, ResourceType::SEABORDER});


}

std::vector<Vertex>& Board::getVertices() {
    return vertices;
}


Vertex& Board::getVertex(int index) {
     if(index < 0 || index >= numVertices) {
        throw std::out_of_range("Invalid vertex index");
    }
    if (vertices.at(index).getId() != index) {
        throw std::out_of_range("Invalid vertex index");
    }
     return vertices.at(index);
}

Edge& Board::getEdge(int index) {
    return edges[index];
}

int Board::getRandomNumber() {
    return 1;
}




