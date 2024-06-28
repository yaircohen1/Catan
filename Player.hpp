// coheny405@gmail.com
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>


#include "Card.hpp"
#include "Vertex.hpp"

enum class ResourceType; // Forward declaration
enum class CardType; // Forward declaration
class Catan; // Forward declaration
class Card; // Forward declaration

class Player {
friend class Catan;

private:
    const std::string playerName;
    Catan& catanGame;  // Reference to the game
    int victoryPoints;
    int turnsPlayed;
    bool biggestArmyCard;
    std::vector<Card*> cards; // Vector to store development cards
    std::map<ResourceType, int> resources; // Map to store resource type and quantity

public:
    // Constructor
    Player(const std::string& playerName, Catan& catanGame);

    // Destructor
    ~Player();

    //operators
    bool operator==(const Player& other) const;
    bool operator!=(const Player& other) const;


    // Functions to manage resources
    void addResource(ResourceType resource, int quantity); // Function to add resources
    void removeResource(ResourceType resource, int quantity); // Function to remove resources
    int getResourceCount(ResourceType resource) const; // Function to get count of specific resource
    int getTotalResources() const; // Function to get total resources
    void displayResources() const; // Function to display resources
   
    // Functions to manage development cards
    void addCard(Card* card); // Function to add development card
    void removeCard(Card* card); // Function to remove development card
    int getCardCount(CardType type) const; // Function to get count of specific development card
    int getTotalCards() const; // Function to get total development cards
    Card* getCard(CardType type) const; // Function to get specific development card
    std::vector<Card*>& getCards(); // Function to get development cards vector
    void displayCards() const; // Function to display development cards
    
    // Function to get player name
    const std::string& getPlayerName() const; 

    // Function to get player catan game
    const Catan& getCatanGame() const;

    // Function to get input int from player (for testing purposes)
    int getInput(int choice) const;

    // Function to get input resource from player (for testing purposes)
    ResourceType getResourceInput() const;

    // Function to get resources
    std::map<ResourceType, int>& getResources();

    // Function to get play turn
    void playTurn();

    // Function to get victory points
    int getVictoryPoints() const;
    
    // Function to add victory points
    void addVictoryPoints(int points);

    // Function to use development card
    int useDevelopmentCard();

    // Function to build road
    bool buildRoad(int edgeID, bool calledByPlayer);

    // Function to build settlement
    bool buildSettlement(int vertexID, bool calledByPlayer);

    // Function to build city
    bool buildCity(int vertexID);

    // Function to buy development card
    void buyDevelopmentCard();

    // Function to make trade
    bool makeTrade(ResourceType offer, int quantity, ResourceType request, int quantity2, Player& player);

    // Function to other player to response to the trade
    bool respondToTrade(Player& thisPlayer, ResourceType offer, int quantity, ResourceType request, int quantity2);

    // Function #2 to offer a trade to another player for testing purposes
    void offerTrade(ResourceType offer, int quantity, ResourceType request, int quantity2, Player& otherPlayer);

    // Function #2 to other player to response to the trade for testing purposes
    bool respondTrade(std::string response, Player& thisPlayer, ResourceType offer, int quantity, ResourceType request, int quantity2);

    // Function to check if player has won
    bool checkWin() const;

};
