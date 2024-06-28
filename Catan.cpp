// coheny405@gmail.com
#include "Catan.hpp"

Catan::Catan(): board(Board::getInstance()) {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    // Initialize the board
    board.initializeBoard();

    // Initialize the development cards
     for (int i = 0; i < VICTORY_POINT_CARDS; ++i) { 
        cards.push_back(new VictoryPointCard());
    }

    for (int i = 0; i < 2; i++) {
        cards.push_back(new MonopolyCard());
        cards.push_back(new RoadBuildCard());
        cards.push_back(new YearOfPlentyCard());     
    }

    for (int i = 0; i < KNIGHT_CARDS; i++) {
        cards.push_back(new KnightCard());
    }

}

Catan::~Catan() {
    for (Card* card : cards) {
        delete card;
    }
    cards.clear();
}

// Function to add a player to the game (just 3 players)
void Catan::addPlayer(Player& player) {
    if (players.size() < PLAYERS) {
        players.push_back(&player);
    } else {
        throw std::invalid_argument("Maximum number of players reached");
    }
}

int Catan::rollDice() const {
    int die1 = rand() % 6 + 1; // Roll the first die (1-6)
    int die2 = rand() % 6 + 1; // Roll the second die (1-6)
    return die1 + die2;  // Return the sum of the two dice
}

// Function to get the players
const std::vector<Player*>& Catan::getPlayers() const {
    return players;
}

// Function to get player by name
Player& Catan::getPlayerByName(const std::string& playerName) {
    for (Player* player : players) {
        if (player->getPlayerName() == playerName) {
            return *player;
        }
    }
    throw std::invalid_argument("Player not found");
}

// Function to determine the turn order
void Catan::determineTurnOrder() {
    std::vector<std::pair<int, Player*>> playerRolls; // Vector to store the player rolls
    for (Player* player : players) {
        int roll = rollDice(); // Roll the dice
        playerRolls.push_back(std::make_pair(roll, player)); // Store the roll and player in the vector
        std::cout << player->getPlayerName() << " rolled a " << roll << std::endl;

    }

    // Sort the vector in descending order of the rolls
    std::sort(playerRolls.begin(), playerRolls.end(), [](const auto& a, const auto& b) {
        if (b.first == a.first) {
            return a.second->getPlayerName() < b.second->getPlayerName(); // Sort by name if rolls are equal
        }
        return b.first < a.first;
    });

   // Update the players vector to reflect the new turn order
    players.clear();
    for (const auto& pair : playerRolls) {
        players.push_back(pair.second);
    }
}

// Function to start the game
void Catan::startGame() {
    determineTurnOrder(); // Determine the turn order
    
    for (Player* player : players) {
        std::cout << player->getPlayerName() << ", please place two settlements and two roads." << std::endl;  

        int settlement1Index;
        int road1Index;
        int settlement2Index;
        int road2Index;

        // Build the first settlement
        while (true) {
            settlement1Index = player->getInput(1);
            if (board.getVertex(settlement1Index).getPiece() == nullptr && (player == players.front() || isVertexFarEnough(settlement1Index))) {
                Settlement* settlement1 = new Settlement(player);
                board.getVertex(settlement1Index).bindPiece(settlement1);
                settlement1->bindVertex(&board.getVertex(settlement1Index));
                break;
            } else {
                std::cout << "Invalid settlement placement. Please try again." << std::endl;
            }
        }

        // Build the first road to connect the first settlement
        while (true) {
            road1Index = player->getInput(2);
            if (board.getEdge(road1Index).getRoadPiece() == nullptr && board.getEdge(road1Index).isConnectedToVertex(&(board.getVertex(settlement1Index)))) {
                RoadPiece* roadPiece1 = new RoadPiece(player);
                board.getEdge(road1Index).bindRoadPiece(roadPiece1);
                roadPiece1->bindEdge(&board.getEdge(road1Index));
                break;
            } else {
                std::cout << "Invalid road placement. Please try again." << std::endl;
            }
        }

        // Build the second settlement
        while (true) {
            settlement2Index = player->getInput(1);
            if (board.getVertex(settlement2Index).getPiece() == nullptr && isVertexFarEnough(settlement2Index)) {
                Settlement* settlement2 = new Settlement(player);
                board.getVertex(settlement2Index).bindPiece(settlement2);
                settlement2->bindVertex(&board.getVertex(settlement2Index));
                break;
            } else {
                std::cout << "Invalid settlement placement. Settlements must be at least two edges away from each other." << std::endl;
            }
        }

        // Build the second road to connect the second settlement
        while (true) {
            road2Index = player->getInput(2);
            if (board.getEdge(road2Index).getRoadPiece() == nullptr && board.getEdge(road2Index).isConnectedToVertex(&(board.getVertex(settlement2Index)))) {
                RoadPiece* roadPiece2 = new RoadPiece(player);
                board.getEdge(road2Index).bindRoadPiece(roadPiece2);
                roadPiece2->bindEdge(&board.getEdge(road2Index));
                break;
            } else {
                std::cout << "Invalid road placement. Please try again." << std::endl;
            }
        }

        // Add victory points for the settlements
        player->addVictoryPoints(2);

        // Give initial resources based on settlement positions
        for (const auto& resource : board.getVertex(settlement1Index).getResources()) {
            player->addResource(resource.second, 1);
        }
        for (const auto& resource : board.getVertex(settlement2Index).getResources()) {
            player->addResource(resource.second, 1);
        }

        std::cout << player->getPlayerName() << " has placed two settlements and two roads." << std::endl;
    }
}

// Function to start the game demo for testing for each player
void Catan::startGameDemo(Player& player, int settlement1Index, int road1Index, int settlement2Index, int road2Index) {
    // Build the first settlement
    while (true) {
        if (board.getVertex(settlement1Index).getPiece() == nullptr && isVertexFarEnough(settlement1Index)) {
            Settlement* settlement1 = new Settlement(&player);
            board.getVertex(settlement1Index).bindPiece(settlement1);
            settlement1->bindVertex(&board.getVertex(settlement1Index));
            break;
        } else {
            std::cout << "Invalid settlement placement. Please try again." << std::endl;
        }
    }

    // Build the first road to connect the first settlement
    while (true) {
        if (board.getEdge(road1Index).getRoadPiece() == nullptr && board.getEdge(road1Index).isConnectedToVertex(&(board.getVertex(settlement1Index)))) {
            RoadPiece* roadPiece1 = new RoadPiece(&player);
            board.getEdge(road1Index).bindRoadPiece(roadPiece1);
            roadPiece1->bindEdge(&board.getEdge(road1Index));
            break;
        } else {
            std::cout << "Invalid road placement. Please try again." << std::endl;
        }
    }

    // Build the second settlement
    while (true) {
        if (board.getVertex(settlement2Index).getPiece() == nullptr && isVertexFarEnough(settlement2Index)) {
            Settlement* settlement2 = new Settlement(&player);
            board.getVertex(settlement2Index).bindPiece(settlement2);
            settlement2->bindVertex(&board.getVertex(settlement2Index));
            break;
        } else {
            std::cout << "Invalid settlement placement. Settlements must be at least two edges away from each other." << std::endl;
        }
    }

    // Build the second road to connect the second settlement
    while (true) {
        if (board.getEdge(road2Index).getRoadPiece() == nullptr && board.getEdge(road2Index).isConnectedToVertex(&(board.getVertex(settlement2Index)))) {
            RoadPiece* roadPiece2 = new RoadPiece(&player);
            board.getEdge(road2Index).bindRoadPiece(roadPiece2);
            roadPiece2->bindEdge(&board.getEdge(road2Index));
            break;
        } else {
            std::cout << "Invalid road placement. Please try again." << std::endl;
        }
    }

    // Add victory points for the settlements
    player.addVictoryPoints(2);

    // Give initial resources based on settlement positions
    for (const auto& resource : board.getVertex(settlement1Index).getResources()) {
        player.addResource(resource.second, 1);
    }
    for (const auto& resource : board.getVertex(settlement2Index).getResources()) {
        player.addResource(resource.second, 1);
    }

    std::cout << player.getPlayerName() << " has placed two settlements and two roads." << std::endl;
}


// Function to handle the discard logic when a 7 is rolled
void Catan::handleDiscard() {
    for (Player* player : players) {
        if (player->getTotalResources() > 7) {
            int resourcesToDiscard = player->getTotalResources() / 2;
            std::cout << player->getPlayerName() << " has to discard " << resourcesToDiscard << " resources." << std::endl;
            
            // Get a reference to the player's resources map
            std::map<ResourceType, int>& resources = player->getResources();

            // Create a vector of pairs (resource type, quantity) and sort by quantity
            std::vector<std::pair<ResourceType, int>> sortedResources(resources.begin(), resources.end());
            std::sort(sortedResources.begin(), sortedResources.end(), [](const auto& a, const auto& b) {
                return b.second < a.second; // Sort in descending order of quantity
            });

            // Discard resources one by one starting from the most frequent
            while (resourcesToDiscard > 0) {
                for (auto& resourcePair : sortedResources) {
                    if (resourcesToDiscard == 0) break;
                    if (resourcePair.second > 0) {
                        resourcePair.second--;
                        resources[resourcePair.first]--;
                        resourcesToDiscard--;
                    }
                }
            }
        }
    }
}


void Catan::giveResources (int roll) {
    // Iterate through all vertices
    for (int i = 0; i < 54; i++) {
        Vertex& vertex = board.getVertex(i);
        const std::vector<std::pair<int, ResourceType>>& resources = vertex.getResources();
        
        for (const auto& resource : resources) {
            // check if the vertex has the resource for the roll
            if (resource.first == roll) {
                AreaPiece* piece = vertex.getPiece();
                if (piece == nullptr) {
                    continue;
                }

                Player* owner = piece->getOwner();
                if (owner == nullptr) {
                    continue;
                }

                if (piece->getType() == AreaPieceType::CITY) { // Check if the vertex contains a city
                        std::cout << owner->getPlayerName() << " gets 2 " << getResourceTypeName(resource.second) << " from city on vertex " << i << "\n";
                        owner->addResource(resource.second, 2);
                    } else {
                        std::cout << owner->getPlayerName() << " gets 1 " << getResourceTypeName(resource.second) << " from settlement on vertex " << i << "\n";
                        owner->addResource(resource.second, 1);
                }
            }
                  
        }
    }
}

// Function to draw a card from the deck
Card* Catan::drawDevelopmentCard() {
    int cardIndex = rand() % cards.size(); // Randomly select a card from the deck
    Card* card = cards[cardIndex]; // Get the card pointer
    cards.erase(cards.begin() + cardIndex); // Remove the card from the deck
    return card; // Return the card pointer
}

// Function to get the board
Board& Catan::getBoard() {
    return board;
}

// Function to end the game
void Catan::endGame() {
    std::cout << "The game has ended!" << std::endl;
    gameEnded = true;
}

// Function to check if the game has ended
bool Catan::isGameEnded() const {
    return gameEnded;
}

bool Catan::isVertexFarEnough(int vertexID) const {
    const Vertex& vertex = board.getVertex(vertexID);
    for (Edge* edge : vertex.getConnectedEdges()) {
        if (edge == nullptr) continue;
        for (Vertex* adjVertex : edge->getVertices()) {
            if (adjVertex->getId() == vertexID) continue;
            if (adjVertex->getPiece() != nullptr) return false;
        }
    }
    return true;
}




