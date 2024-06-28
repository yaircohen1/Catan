// coheny405@gmail.com
#include <iostream>
#include <vector>

#include "Catan.hpp"
#include "Player.hpp"

void simulatePlayTurn(Player& player, int roll) {
    std::cout << player.getPlayerName() << " rolled a " << roll << "." << std::endl;
    // If the roll is 7, players with more than 7 resources must discard half
    if (roll == 7) {
        std::cout << player.getPlayerName() << " rolled a 7! Players with more than 7 resources must discard half." << std::endl;
        const_cast<Catan&>(player.getCatanGame()).handleDiscard();
    } else {
        // Distribute resources based on the roll
        const_cast<Catan&>(player.getCatanGame()).giveResources(roll);
    }
}

int main() {
    // Create the game
    Catan catanGame;

    // Create players
    Player player1("Yair", catanGame);
    Player player2("Dvir", catanGame);
    Player player3("Eldor", catanGame);

    // Add players to the game
    catanGame.addPlayer(player1);
    catanGame.addPlayer(player2);
    catanGame.addPlayer(player3);

    // Start the game
    catanGame.startGameDemo(player1, 7, 6, 17, 26);
    catanGame.startGameDemo(player2, 9, 15, 8, 13);
    catanGame.startGameDemo(player3, 49, 64, 41, 59);

    // Game loop
    while (!catanGame.isGameEnded()) {
        for (Player* player : catanGame.getPlayers()) {
            std::cout << player->getPlayerName() << "'s turn." << std::endl;

            // Simulate a dice roll
            int roll = catanGame.rollDice();
            simulatePlayTurn(*player, roll);

            // Check if the game has ended
            if (catanGame.isGameEnded()) {
                break;
            }

            // Artificially increment Yair's victory points to ensure he wins
            if (player->getPlayerName() == "Yair") {
                player->addVictoryPoints(1);
                std::cout << player->getVictoryPoints() << std::endl;
            }

            // Check if the player has won
            if (player->getPlayerName() == "Yair" && player->checkWin()) {
                // Display victory points for each player
                std::cout << "Game over! Victory points:" << std::endl;
                for (const Player* player : catanGame.getPlayers()) {
                std::cout << player->getPlayerName() << ": " << player->getVictoryPoints() << " points" << std::endl;
                }
                
                catanGame.endGame();
                break;
            }
        }
    }

    

    return 0;
}


    
  

