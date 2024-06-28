// coheny405@gmail.com
#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>  // For srand and rand
#include <ctime>    // For time

#include "Board.hpp"
#include "Card.hpp"
#include "VictoryPointCard.hpp"
#include "MonopolyCard.hpp"
#include "YearOfPlentyCard.hpp"
#include "RoadBuildCard.hpp"
#include "KnightCard.hpp"
#include "Player.hpp"

constexpr int PLAYERS = 3;
constexpr int POINTS_TO_WIN = 10;

constexpr int VICTORY_POINT_CARDS = 4;
constexpr int KNIGHT_CARDS = 3;
constexpr int ROAD_BUILDING_CARDS = 2;
constexpr int MONOPOLY_CARDS = 2;
constexpr int YEAR_OF_PLENTY_CARDS = 2;
constexpr int TOTAL_CARDS = 13;

class Catan {
private:
    Board& board; // Reference to the singleton board
    std::vector<Player*> players;
    std::vector<Card*> cards;
    bool gameEnded = false;
    
public:
    // Constructor
    Catan();

    // Destructor
    ~Catan();

    // Function to add a player to the game
    void addPlayer(Player& player);
    
    // Function to get the players
    const std::vector<Player*>& getPlayers() const;

    // Function to get player by name
    Player& getPlayerByName(const std::string& playerName);

    // Private function to roll two six-sided dice and return their sum
    int rollDice() const; 

    // Function to determine the turn order
    void determineTurnOrder();

    // Function to start the game
    void startGame();

    // Function to start the game demo for testing
    void startGameDemo(Player& player, int settlement1Index, int road1Index, int settlement2Index, int road2Index);

    // Function to handle the discard logic when a 7 is rolled
    void handleDiscard();

    // Function that gives resources to player who owns a settlement or city adjacent to the hexagon with the same num to the rolling 
    void giveResources (int roll);

    // Function to draw a card from the deck
    Card* drawDevelopmentCard();
    
    // Function to get the board
    Board& getBoard();

    // Function to end the game
    void endGame();

    // Function to check if the game has ended
    bool isGameEnded() const;

    // Function to check if vertex is far enough from other settlements
    bool isVertexFarEnough(int vertexID) const;

};



