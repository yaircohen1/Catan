// coheny405@gmail.com
#include <iostream>
#include <vector>

#include "Catan.hpp"
#include "Player.hpp"



int main() {

    // Get the names of the players
    std::string player1Name;
    std::string player2Name;
    std::string player3Name;
    std::cout << "Enter the name of player 1: ";
    std::cin >> player1Name;
    std::cout << "Enter the name of player 2: ";
    std::cin >> player2Name;
    std::cout << "Enter the name of player 3: ";
    std::cin >> player3Name;

    // Create the game
    Catan catanGame;

    // Create players
    Player player1(player1Name, catanGame);
    Player player2(player2Name, catanGame);
    Player player3(player3Name, catanGame);

    // Add players to the game
    catanGame.addPlayer(player1);
    catanGame.addPlayer(player2);
    catanGame.addPlayer(player3);

    // Start the game
    catanGame.startGame();

    // Game loop
    while (true) {
        for (Player* player : catanGame.getPlayers()) {
            std::cout << player->getPlayerName() << "'s turn." << std::endl;

            player->playTurn();
            if (catanGame.isGameEnded()) {
                break;
            }
        }
         if (catanGame.isGameEnded()) {
            break;
         }
    }
    return 0;
}

