// coheny405@gmail.com

#include "Player.hpp"
#include "Catan.hpp"
#include "Settlement.hpp"
#include "City.hpp"

#include <limits>    // For std::numeric_limits


Player::Player(const std::string& playerName, Catan& catanGame)
: playerName(playerName), catanGame(catanGame), victoryPoints(0), turnsPlayed(0), biggestArmyCard(false){
    // Initialize resources map
    resources[ResourceType::LUMBER] = 0;
    resources[ResourceType::BRICK] = 0;
    resources[ResourceType::GRAIN] = 0;
    resources[ResourceType::WOOL] = 0;
    resources[ResourceType::ORE] = 0;
}

// Destructor to clean up allocated memory
Player::~Player() {
    for (Card* card : cards) {
        delete card;
    }
    cards.clear();
}

bool Player::operator==(const Player& other) const{
    return playerName == other.playerName;
}

bool Player::operator!=(const Player& other) const{
    return playerName != other.playerName;
}


void Player::addResource(ResourceType resource, int quantity) {
    resources[resource] += quantity;
}

void Player::removeResource(ResourceType resource, int quantity) {
    if (resources[resource] >= quantity) {
        resources[resource] -= quantity;
    } else {
        // Handle error: not enough resources
        std::cerr << "Not enough resources to remove" << std::endl;
    }
}

int Player::getResourceCount(ResourceType resource) const {
    return resources.at(resource);
}

int Player::getTotalResources() const {
    int total = 0;
    for (const auto& pair : resources) {
        total += pair.second;
    }
    return total;
}

// Function to display resources
void Player::displayResources() const {
    std::cout << "Resources for player " << playerName << ":" << std::endl;
    for (const auto& pair : resources) {
        std::cout << "- " << getResourceTypeName(pair.first) << ": " << pair.second << std::endl;
    }
}

// Function to get resources
std::map<ResourceType, int>& Player::getResources() {
    return resources;
}

// Function to add a card
void Player::addCard(Card* card) {
    cards.push_back(card);
}

// Function to remove a card
void Player::removeCard(Card* card) {
    auto it = std::find_if(cards.begin(), cards.end(),
                           [&card](const Card* c) { return *c == *card; });
    if (it != cards.end()) {
        delete *it;
        cards.erase(it);
    } else {
        // Handle error: card not found
        std::cerr << "Card not found" << std::endl;
    }
}

// Function to get count of specific card type
int Player::getCardCount(CardType type) const {
    int count = 0;
    for (const Card* card : cards) {
        if (card->getType() == type) {
            count++;
        }
    }
    return count;
}

// Function to get total count of all cards
int Player::getTotalCards() const {
    return cards.size();
}

// Function to get a specific card
Card* Player::getCard(CardType type) const {
    for (Card* card : cards) {
        if (card->getType() == type) {
            return card;
        }
    }
    return nullptr;
}

// Function to display cards
void Player::displayCards() const {
    std::cout << "Cards for player " << playerName << ":" << std::endl;
    if (cards.empty()) {
        std::cout << "No cards." << std::endl;
    }
    for (const Card* card : cards) {
        std::cout << "- " << card->getDescription() << std::endl;
    }
}

int Player::getVictoryPoints() const{
    return victoryPoints;
}

 void Player::addVictoryPoints(int points) {
    victoryPoints+=points;
 }

 const std::string& Player::getPlayerName() const{
    return playerName;
 }

    const Catan& Player::getCatanGame() const{
        return catanGame;
    }

  std::vector<Card*>& Player::getCards(){
    return cards;
}

 void Player::playTurn() {
    std::cout << "Player " << playerName << "'s turn." << std::endl;
     while (true) {
        std::cout << "Choose an action:" << std::endl;
        std::cout << "1. Roll dice" << std::endl;
        std::cout << "2. Use development card" << std::endl;
        std::cout << "3. View resources and cards" << std::endl;

        int choice;
        std::cin >> choice;
        // Check if the input is valid
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input." << std::endl;
            continue; // Restart the loop
        }
        if (choice == 1) {
            int roll = catanGame.rollDice();
            std::cout << playerName << " rolled a " << roll << "." << std::endl;
            // If the roll is 7, players with more than 7 resources must discard half
            if (roll == 7) {
                std::cout << playerName << " rolled a 7! Players with more than 7 resources must discard half." << std::endl;
                catanGame.handleDiscard();
            } else {
                // Distribute resources based on the roll
                std::cout << "Giving resources for roll: " << roll << std::endl;
                catanGame.giveResources(roll);
            }  
            break; // Exit the loop after rolling the dice
        } else if (choice == 2) {
           int result = useDevelopmentCard();
              if (result == 1) {
                turnsPlayed++; // Increment the number of turns played
                return; // If a development card is used, end the turn
              } else {
                continue; // If a development card is not used, continue the turn
              }   
        } else if (choice == 3) {
            displayResources();
            displayCards();
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    while (true) {
        std::cout << "Choose an action:" << std::endl;
        std::cout << "1. Trade" << std::endl;
        if (turnsPlayed > 0) {
            std::cout << "2. Build Road" << std::endl;
            std::cout << "3. Build settlement" << std::endl;
            std::cout << "4. Build city" << std::endl;
        }
        std::cout << "5. Buy development card" << std::endl;
        std::cout << "6. End turn" << std::endl;
        std::cout << "7. View resources and cards" << std::endl;

        int choice;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input." << std::endl;
            continue; // Restart the loop
        }

        if (choice == 1) {
        // Trade with another player
        std::cout << "Choose a player to trade with:" << std::endl;
        std::string playerName;
        std::cin >> playerName;
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input." << std::endl;
            continue; // Restart the loop
        }
        bool playerFound = false;
        for (Player* player : catanGame.getPlayers()) {
            if (player->getPlayerName() == playerName) {
                playerFound = true;
                break;
            }
        }
        if (!playerFound) {
            std::cout << "Player not found." << std::endl;
            continue;
        }
        Player& otherPlayer = catanGame.getPlayerByName(playerName);
        
        std::cout << "Choose a resource to trade:" << std::endl;
        ResourceType offer = getResourceInput();
        if (offer == ResourceType::SEABORDER) {
            continue;
        }
        std::cout << "Choose a quantity to trade:" << std::endl;
        int quantity;
        std::cin >> quantity;
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input." << std::endl;
            continue; // Restart the loop
        }
        std::cout << "Choose a resource to trade for:" << std::endl;
        ResourceType request = getResourceInput();
        if (request == ResourceType::SEABORDER) {
            continue;
        }
        std::cout << "Choose a quantity to trade for:" << std::endl;
        int quantity2;
        std::cin >> quantity2;
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input." << std::endl;
            continue; // Restart the loop
        }
        if (quantity < 0 || quantity2 < 0) {
            std::cout << "Invalid quantity. Please try again." << std::endl;
            continue;
        }

        makeTrade(offer, quantity, request, quantity2, otherPlayer);

        } else if (choice == 2 && turnsPlayed > 0) {
            int edgeID = getInput(2);
            buildRoad(edgeID, true);
        } else if (choice == 3 && turnsPlayed > 0) {
            int vertexID = getInput(1);
            buildSettlement(vertexID, true);
        } else if (choice == 4 && turnsPlayed > 0) {
            int vertexID = getInput(1);
            buildCity(vertexID);     
        } else if (choice == 5) {
            buyDevelopmentCard();
        } else if (choice == 6) {
            std::cout << "Ending turn." << std::endl;
            turnsPlayed++; // Increment the number of turns played
            if(checkWin()) {
                std::cout << playerName << " has won the game!" << std::endl;
                catanGame.endGame();
                break;
            }
            break; // End the turn
        } else if (choice == 7) {
            displayResources();
            displayCards();
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

int Player::useDevelopmentCard() {
    std::cout << "Choose a development card to use:" << std::endl;
    std::cout << "1. Monopoly" << std::endl;
    std::cout << "2. Road Building" << std::endl;
    std::cout << "3. Year of Plenty" << std::endl;

    int choice;
    std::cin >> choice;
    if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input." << std::endl;
            return 0; // Restart the loop
        }

    Card* card = nullptr;
    if (choice == 1) {
        std::cout << playerName << " uses a Monopoly card." << std::endl;
        card = this->getCard(CardType::MONOPOLY);
        if (card) {
            MonopolyCard* monopolyCard = dynamic_cast<MonopolyCard*>(card);
            if (monopolyCard) {
                monopolyCard->use(*this);
                return 1;
            }
        }
        std::cout << "You don't have a Monopoly card." << std::endl;
        return 0;      
    } else if (choice == 2) {
        std::cout << playerName << " uses a Road Building card." << std::endl;
        card = this->getCard(CardType::ROAD_BUILDING);
        if (card) {
            RoadBuildCard* roadBuildCard = dynamic_cast<RoadBuildCard*>(card);
            if (roadBuildCard) {
                roadBuildCard->use(*this);
                return 1;
            }
        }
        std::cout << "You don't have a Road Building card." << std::endl;
        return 0;
    } else if (choice == 3) {
        std::cout << playerName << " uses a Year of Plenty card." << std::endl;
        card = this->getCard(CardType::YEAR_OF_PLENTY);
        if (card) {
            YearOfPlentyCard* yearOfPlentyCard = dynamic_cast<YearOfPlentyCard*>(card);
            if (yearOfPlentyCard) {
                yearOfPlentyCard->use(*this);
                return 1;
            }
        }
        std::cout << "You don't have a Year of Plenty card." << std::endl;
        return 0;
    } else {
        std::cout << "Invalid choice. Please try again." << std::endl;
        return 0;
    }
}

int Player::getInput(int choice) const {
    // return ID number for the vertex
    if (choice == 1) {
        while (true) {
            std::cout << "Choose a vertex's ID number for Area piece (Settlement or City)." << std::endl;
            int vertexID;
            std::cin >> vertexID;
             // Check if the input is valid
            if (std::cin.fail()) {
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                std::cout << "Invalid input." << std::endl;
                continue; // Restart the loop
            }
            if(vertexID > 53 || vertexID < 0) {
                std::cout << "Invalid vertex ID. Please try again." << std::endl;
            } else {
            return vertexID;      
            }
        }
    }
    // return ID number for the edge
    else if (choice == 2) {
        while (true) {
            std::cout << "Choose an edge's ID number for the road." << std::endl;
            int edgeID;
            std::cin >> edgeID;
            if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input." << std::endl;
            continue; // Restart the loop
            }
            if(edgeID > 71 || edgeID < 0) {
                std::cout << "Invalid edge ID. Please try again." << std::endl;
            } else {
            return edgeID;
            }
        }
    } return 0;
}

ResourceType Player::getResourceInput() const {
    
    std::cout << "Choose a resource:" << std::endl;
    std::cout << "1. Lumber" << std::endl;
    std::cout << "2. Brick" << std::endl;
    std::cout << "3. Grain" << std::endl;
    std::cout << "4. Wool" << std::endl;
    std::cout << "5. Ore" << std::endl;

    int resourceChoice;
    std::cin >> resourceChoice;
    if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input." << std::endl;
            return ResourceType::SEABORDER; // Restart the loop
    }

    switch (resourceChoice) {
        case 1:
            return ResourceType::LUMBER;
        case 2:
            return ResourceType::BRICK;
        case 3:
            return ResourceType::GRAIN;
        case 4:
            return ResourceType::WOOL;
        case 5:
            return ResourceType::ORE;
        default:
            std::cout << "Invalid choice for resource. Please try again." << std::endl;
            return ResourceType::SEABORDER;
        }
    }


bool Player::buildRoad(int edgeID, bool calledByPlayer) {
  
    if (calledByPlayer && (this->getResourceCount(ResourceType::LUMBER) < 1 || this->getResourceCount(ResourceType::BRICK) < 1)) {
        std::cout << "You don't have enough resources to build a road." << std::endl;
        return false;
    }
    RoadPiece* roadPiece = new RoadPiece(this);

    if ((catanGame.getBoard().getEdge(edgeID).bindRoadPiece(roadPiece) == 1) &&
        (roadPiece->bindEdge(&(catanGame.getBoard().getEdge(edgeID))) == 1)) {
            
            // Check if the road can be connected to a settlement, city, or another road of the player
            bool connectedRoad = false;
            bool connectedSettlementCity = false;

            for (Edge* edge : catanGame.getBoard().getEdge(edgeID).getConnectedEdges()) {
                if (edge != nullptr && edge->getRoadPiece() != nullptr && edge->getRoadPiece()->getOwner() == this) {
                    connectedRoad = true;
                    break;
                }
            }
            std::cout << "The edge " << edgeID <<" is Connected to Road: " << connectedRoad << std::endl;
            
            for (Vertex* vertex : catanGame.getBoard().getEdge(edgeID).getVertices()) {
                if (vertex->getPiece() != nullptr && vertex->getPiece()->getOwner() == this) {
                    connectedSettlementCity = true;
                    break;
                }
            }
            std::cout << "The edge " << edgeID << " is Connected to SC: " << connectedSettlementCity << std::endl;
            if (!connectedRoad && !connectedSettlementCity) {
                std::cout << "Road must be connected to a settlement, city, or road of the player." << std::endl;
                delete roadPiece;
                return false;
            }

            std::cout << playerName << " built a road on edge " << edgeID << std::endl;
            if (calledByPlayer) {
                this->removeResource(ResourceType::LUMBER, 1);
                this->removeResource(ResourceType::BRICK, 1);
            }
            return true;
    } else {
        delete roadPiece;
        std::cout << "Cannot build road on edge " << edgeID << std::endl;
        return false;
    }   
}

void Player::buyDevelopmentCard() {
    if (this->getResourceCount(ResourceType::ORE) < 1 || this->getResourceCount(ResourceType::WOOL) < 1 || this->getResourceCount(ResourceType::GRAIN) < 1) {
        std::cout << "You don't have enough resources to buy a development card." << std::endl;
        return;
    }
    std::cout << playerName << " is buying a development card." << std::endl;
    // Draw a card from the deck of cards left in the game
    Card* card = catanGame.drawDevelopmentCard();
    if (card) {
        this->addCard(card);
        this->removeResource(ResourceType::ORE, 1);
        this->removeResource(ResourceType::WOOL, 1);
        this->removeResource(ResourceType::GRAIN, 1);
        std::cout << playerName << " got: " << card->getCardType() << " card." << std::endl;
        if (card->getType() == CardType::VICTORY_POINT) {
            victoryPoints++;
        }
        if (card->getType() == CardType::KNIGHTS) {
            if (this->getCardCount(CardType::KNIGHTS) == 3) {
                biggestArmyCard = true;
                victoryPoints += 2;
            }
        }
    } else {
        std::cout << "No development cards left in the deck." << std::endl;
        delete card;
    }
}

bool Player::makeTrade(ResourceType offer, int quantity, ResourceType request, int quantity2, Player& otherPlayer) {
    if (&otherPlayer == this) {
            std::cout << "Cannot trade with yourself." << std::endl;
            return false;
        }
    if (getResourceCount(offer) >= quantity) {  
        // offer function to make the trade wirh the other player
        std::cout << playerName << " offers " << quantity << " " << getResourceTypeName(offer) << " for " << quantity2 << " " << getResourceTypeName(request) << " to " << otherPlayer.getPlayerName() << "." << std::endl;
        if(otherPlayer.respondToTrade(*this, offer, quantity, request, quantity2) == true) {
            std::cout << "Trade accepted." << std::endl;
            return true;
        } else {
            std::cout << "Trade declined." << std::endl;
            return false;   
        }
    } else {
        std::cout << "You don't have enough resources to make the trade." << std::endl;
        return false;
    }    
}

// Function #2 to offer a trade to another player for testing purposes
void Player::offerTrade(ResourceType offer, int quantity, ResourceType request, int quantity2, Player& otherPlayer) {
    if (&otherPlayer == this) {
        std::cout << "Cannot trade with yourself." << std::endl;
        return;
    }
    if (getResourceCount(offer) >= quantity) {
         // offer function to make the trade wirh the other player
        std::cout << playerName << " offers " << quantity << " " << getResourceTypeName(offer) << " for " << quantity2 << " " << getResourceTypeName(request) << " to " << otherPlayer.getPlayerName() << "." << std::endl;
        return;
    } else {
        std::cout << "You don't have enough resources to make the trade." << std::endl;
        return;
    }
}

// Function to other player to response to the trade
bool Player::respondToTrade(Player& thisPlayer, ResourceType offer, int quantity, ResourceType request, int quantity2) {
    if (getResourceCount(request) >= quantity2) {
        std::cout << playerName << ", " << thisPlayer.getPlayerName() << " offers you " << quantity << " " << getResourceTypeName(offer) << " for " << quantity2 << " " << getResourceTypeName(request) << "." << std::endl;
        std::cout << "Accept the trade? (y/n)" << std::endl;
        char response;
        std::cin >> response;
        if (response == 'y' || response == 'Y') {
            removeResource(request, quantity2);
            addResource(offer, quantity);
            thisPlayer.removeResource(offer, quantity);
            thisPlayer.addResource(request, quantity2);
            return true;
        } else {
            return false;
        }
    } else {
        std::cout << "Not enough for "<< playerName << " resources to make the trade." << std::endl;
        return false;
    }
}

// Function #2 to offer a trade to another player for testing purposes
bool Player::respondTrade(std::string response, Player& thisPlayer, ResourceType offer, int quantity, ResourceType request, int quantity2) {
    std::cout << playerName << ", " << thisPlayer.getPlayerName() << " offers you " << quantity << " " << getResourceTypeName(offer) << " for " << quantity2 << " " << getResourceTypeName(request) << "." << std::endl;
    if (response == "y" || response == "Y") {
        if (getResourceCount(request) >= quantity2) {
            removeResource(request, quantity);
            addResource(offer, quantity2);
            thisPlayer.removeResource(offer, quantity2);
            thisPlayer.addResource(request, quantity);
            std::cout << "Trade accepted." << std::endl;
            return true;
        } else {
            std::cout << "Not enough for "<< playerName << "resources to make the trade." << std::endl;
            return false;
        }
    } else {
        std::cout << "Trade declined." << std::endl;
        return false;
    }
}

bool Player::buildSettlement(int vertexID, bool calledByPlayer) {
   
    // Check if the player has enough resources
    if (calledByPlayer && (this->getResourceCount(ResourceType::LUMBER) < 1 || this->getResourceCount(ResourceType::BRICK) < 1 || this->getResourceCount(ResourceType::GRAIN) < 1 || this->getResourceCount(ResourceType::WOOL) < 1)) {
        std::cout << "You don't have enough resources to build a settlement on vertex: " << vertexID <<"."<<std::endl;
        return false;
    }

    // Check if the vertex is at least two edges away from another settlement or city
    if (!catanGame.isVertexFarEnough(vertexID)) {
        std::cout << "Invalid settlement placement for vertex: "<< vertexID<< " Settlements must be at least two edges away from each other." << std::endl;
        return false;
    }

    // Create a new settlement
    Settlement* settlement = new Settlement(this);

    // Bind the settlement to the vertex if possible
    if ((catanGame.getBoard().getVertex(vertexID).bindPiece(settlement) == 1) &&
        (settlement->bindVertex(&(catanGame.getBoard().getVertex(vertexID))) == 1)) {

        // Check if the vertex is connected to a road owned by the player
        if (calledByPlayer) {
            bool connectedRoad = false;
            for (Edge* edge : catanGame.getBoard().getVertex(vertexID).getConnectedEdges()) {
                if (edge->getRoadPiece() != nullptr && edge->getRoadPiece()->getOwner() == this) {
                    connectedRoad = true;
                    break;
                }
            }

            if (!connectedRoad) {
                std::cout << "Settlement must be connected to a road of the player. build S on vertex: " << vertexID << " failed."<<std::endl;
                delete settlement;
                return false;
            }
        }
        // Successful construction
        std::cout << playerName << " built a settlement on vertex " << vertexID << std::endl;
        if (calledByPlayer) {   
            this->removeResource(ResourceType::LUMBER, 1);
            this->removeResource(ResourceType::BRICK, 1);
            this->removeResource(ResourceType::GRAIN, 1);
            this->removeResource(ResourceType::WOOL, 1);
        }
        victoryPoints++;
        return true;
    } else {
        delete settlement;
        std::cout << "Cannot build settlement on vertex " << vertexID << std::endl;
        return false;
    }  
}

// Function to build a city
bool Player::buildCity(int vertexID) {
    // Check if the player has enough resources
    if (this->getResourceCount(ResourceType::ORE) < 3 || this->getResourceCount(ResourceType::GRAIN) < 2) {
        std::cout << "You don't have enough resources to build a city." << std::endl;
        return false;
    }

    Vertex& vertex = catanGame.getBoard().getVertex(vertexID);
    // Check if there is a settlement on the vertex
    AreaPiece* piece = vertex.getPiece();
    if (piece == nullptr || piece->getOwner() != this || piece->getType() != AreaPieceType::SETTLEMENT) {
        std::cout << "No settlement on vertex " << vertexID << std::endl;
        return false;
    }

    // Convert the settlement to a city
    City* city = new City(this, &vertex);
   
    // Bind the city to the vertex
    if (city->bindVertex(&vertex) == 1) {
        vertex.SetPiece(city);
        delete piece;  // Delete the old settlement piece
        std::cout << "city owner " << city->getOwner()->getPlayerName() << std::endl;
        std::cout << playerName << " built a city on vertex " << vertexID << std::endl;
        this->removeResource(ResourceType::ORE, 3);
        this->removeResource(ResourceType::GRAIN, 2);
        victoryPoints += 1; // Assuming settlement was already counted as 1, and city is worth 2 total
        return true;
        
    } else {
        std::cout << "Cannot build city on vertex " << vertexID << std::endl;
        delete city;
        return false;
    }
}

// Function to check if player has won
bool Player::checkWin() const {
    return victoryPoints >= 10;
}

