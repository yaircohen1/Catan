// coheny405@gmail.com

#include "Catan.hpp"
#include "Player.hpp"
#include "ResourceType.hpp"
#include "doctest.h"
#include <sstream>

TEST_CASE("Test Catan game mechanics") {
    SUBCASE("place next to road not owned by the player") {
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

        // give player2 a resource to make him able to place a settlement
        player2.addResource(ResourceType::WOOL, 10);
        player2.addResource(ResourceType::BRICK, 10);
        player2.addResource(ResourceType::LUMBER, 10);
        player2.addResource(ResourceType::GRAIN, 10);
        player2.addResource(ResourceType::ORE, 10);

        player1.addResource(ResourceType::WOOL, 10);
        player1.addResource(ResourceType::BRICK, 10);
        player1.addResource(ResourceType::LUMBER, 10);
        player1.addResource(ResourceType::GRAIN, 10);
        player1.addResource(ResourceType::ORE, 10);

        CHECK(player2.buildSettlement(23, false));
        CHECK(player2.buildRoad(27, false));
        CHECK(player2.buildRoad(20, false));
        CHECK(player2.buildSettlement(13, true));
        CHECK(player2.buildRoad(14, false));
        CHECK(!player1.buildRoad(26, false));
        CHECK(!player1.buildSettlement(9, true));
    }
        
    SUBCASE("try to place in taken vertex") {
        
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

        // give player2 a resource to make him able to place a settlement
        player2.addResource(ResourceType::WOOL, 1);
        player2.addResource(ResourceType::BRICK, 1);
        player2.addResource(ResourceType::LUMBER, 1);
        player2.addResource(ResourceType::GRAIN, 1);

        player1.addResource(ResourceType::WOOL, 1);
        player1.addResource(ResourceType::BRICK, 1);
        player1.addResource(ResourceType::LUMBER, 1);
        player1.addResource(ResourceType::GRAIN, 1);

        player1.buildSettlement(8, false);
        CHECK(!player2.buildSettlement(8, true));

        // check that the vertex is still owned by player1
        CHECK(catanGame.getBoard().getVertex(8).getPiece()->getOwner() == &player1);
        // check that player2 still have the resources
        CHECK(player2.getResourceCount(ResourceType::LUMBER) == 1);
        CHECK(player2.getResourceCount(ResourceType::BRICK) == 1);
        CHECK(player2.getResourceCount(ResourceType::WOOL) == 1);
        CHECK(player2.getResourceCount(ResourceType::GRAIN) == 1);
    }

    SUBCASE("try to place near settlement") {
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

        player1.buildSettlement(8, false);
        CHECK(!player2.buildSettlement(4, true));
        // check that the vertex is still owned by player1
        CHECK(catanGame.getBoard().getVertex(8).getPiece()->getOwner() == &player1);
    }
    
    SUBCASE("place without any resources") {
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

        CHECK(!player1.buildSettlement(8,true));
    }
    
        SUBCASE("check if the resources are taken from the player when placing a road") {
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

            player1.addResource(ResourceType::LUMBER, 1);
            player1.addResource(ResourceType::BRICK, 1);

            player1.buildSettlement(8, false);
            player1.buildRoad(7, true);
            CHECK((player1.getResourceCount(ResourceType::LUMBER) == 0 && player1.getResourceCount(ResourceType::BRICK) == 0));
        }

        SUBCASE("try to place in taken edge") {
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

            player1.buildSettlement(8, false);
            player1.buildRoad(7, false);
            CHECK(!player2.buildRoad(7, false));

            // check that the edge is still owned by player1
            CHECK(catanGame.getBoard().getEdge(7).getRoadPiece()->getOwner() == &player1);
        }

        SUBCASE("place a road near another road") {
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

            player1.buildSettlement(8, false);
            player1.buildRoad(7, false);
            player1.buildRoad(2, false);
            player1.buildRoad(3, false);
            player1.buildRoad(4, false);
            CHECK((catanGame.getBoard().getEdge(2).getRoadPiece()->getOwner() == &player1 && 
                catanGame.getBoard().getEdge(3).getRoadPiece()->getOwner() == &player1 && 
                catanGame.getBoard().getEdge(4).getRoadPiece()->getOwner() == &player1));
        }

        SUBCASE("try to place a road without any resources") {
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

            CHECK(!player1.buildRoad(7, true));
        }

        SUBCASE("try to place a road not near road or settlement") {
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

            player1.addResource(ResourceType::LUMBER, 1);
            player1.addResource(ResourceType::BRICK, 1);
            
            CHECK(!player1.buildRoad(7,true));
        }
    }

    TEST_CASE("place city") {
        SUBCASE("simple place city") {
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

            // give player1 a resource to make him able to place a city
            player1.addResource(ResourceType::GRAIN, 2);
            player1.addResource(ResourceType::ORE, 3);

            player1.buildSettlement(41, false);
            player1.buildCity(41);

            CHECK(catanGame.getBoard().getVertex(41).getPiece()->getOwner() == &player1);
            CHECK(catanGame.getBoard().getVertex(41).getPiece()->getType() == AreaPieceType::CITY);
            CHECK(player1.getVictoryPoints() == 2);

            // check that the resources are taken from the player
            CHECK((player1.getResourceCount(ResourceType::GRAIN) == 0 && player1.getResourceCount(ResourceType::ORE) == 0));
        }

        SUBCASE("try to place city without any resources") {
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

            player1.buildSettlement(8, false);
            CHECK(!player1.buildCity(8));
        }

        SUBCASE("try to place city in a settlement that is not owned by the player") {
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

            player1.addResource(ResourceType::GRAIN, 2);
            player1.addResource(ResourceType::ORE, 3);
            
            player2.addResource(ResourceType::GRAIN, 2);
            player2.addResource(ResourceType::ORE, 3);


            player1.buildSettlement(8, false);

            // give player2 a resource to make him able to place a city
            player2.addResource(ResourceType::GRAIN, 2);
            player2.addResource(ResourceType::ORE, 3);

            // the vertex is owned by player1
            CHECK(!player2.buildCity(8));
            // the vertex owner is null
            CHECK(!player1.buildCity(6));

            // check that the vertex is still owned by player1 and it is not a city
            CHECK((catanGame.getBoard().getVertex(8).getPiece()->getOwner() == &player1 && 
                catanGame.getBoard().getVertex(8).getPiece()->getType() == AreaPieceType::SETTLEMENT));
        }
    }

    TEST_CASE("give resources on roll") {
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

        // give player1 a resource to make him able to place a city
        player1.addResource(ResourceType::GRAIN, 2);
        player1.addResource(ResourceType::ORE, 3);

        player1.buildSettlement(44,false);
        player1.buildCity(44);
        player1.buildSettlement(45,false);

        player2.buildSettlement(8,false);

        // roll 10
        catanGame.giveResources(10);

        // check that the resources are given to the players
        CHECK((player1.getResourceCount(ResourceType::GRAIN) == 0 && player1.getResourceCount(ResourceType::ORE) == 0 && player1.getResourceCount(ResourceType::BRICK) == 0 && player1.getResourceCount(ResourceType::WOOL) == 0 && player1.getResourceCount(ResourceType::LUMBER) == 0));
        CHECK((player2.getResourceCount(ResourceType::GRAIN) == 0 && player2.getResourceCount(ResourceType::ORE) == 1 && player2.getResourceCount(ResourceType::BRICK) == 0 && player2.getResourceCount(ResourceType::WOOL) == 0 && player1.getResourceCount(ResourceType::LUMBER) == 0));

        // roll 6
        catanGame.giveResources(6);

        // check that the resources are given to the players
        CHECK((player1.getResourceCount(ResourceType::GRAIN) == 3 && player1.getResourceCount(ResourceType::ORE) == 0 && player1.getResourceCount(ResourceType::BRICK) == 0 && player1.getResourceCount(ResourceType::WOOL) == 0 && player1.getResourceCount(ResourceType::LUMBER) == 0));
        CHECK((player2.getResourceCount(ResourceType::GRAIN) == 0 && player2.getResourceCount(ResourceType::ORE) == 1 && player2.getResourceCount(ResourceType::BRICK) == 1 && player2.getResourceCount(ResourceType::WOOL) == 0 && player1.getResourceCount(ResourceType::LUMBER) == 0));
    }

    TEST_CASE("buy development card") {
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

        // give player1 a resource to make him able to buy a card
        player1.addResource(ResourceType::GRAIN, 1);
        player1.addResource(ResourceType::ORE, 1);
        player1.addResource(ResourceType::WOOL, 1);

        player1.buildSettlement(44,false);
        player1.buildSettlement(45,false);

        player2.buildSettlement(8,false);

        int amountOfCards = player1.getTotalCards();
        
        // buy development card
        player1.buyDevelopmentCard();

        // check that the card is in the player's hand
        CHECK(player1.getTotalCards() == amountOfCards+1);
    }

    TEST_CASE("trade tests") {
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

        SUBCASE("simple trade - Yair will trade 1 LUMBER & 1 Victory Point Card for 1 ORE & 1 Knight Card") {
            // Create development cards
            Card* k_card = new KnightCard();
            Card* vp_card = new VictoryPointCard();

            player1.addResource(ResourceType::LUMBER, 1);
            player1.addResource(ResourceType::BRICK, 1);

            player1.addCard(vp_card);
            player1.addVictoryPoints(1);

            player2.addResource(ResourceType::ORE, 1);
            player2.addCard(k_card);

            // player1
            CHECK(player1.getResourceCount(ResourceType::LUMBER) == 1);
            CHECK(player1.getResourceCount(ResourceType::BRICK) == 1);
            CHECK(player1.getCards().size() == 1);
            CHECK(player1.getCards()[0] == vp_card);
            CHECK(player1.getVictoryPoints() == 1);

            // player2
            CHECK(player2.getResourceCount(ResourceType::ORE) == 1);
            CHECK(player2.getCards().size() == 1);
            CHECK(player2.getCards()[0] == k_card);

            // redirect cin to input buffer
            std::istringstream input("y");
            std::streambuf* prevcinbuf = std::cin.rdbuf(input.rdbuf());

            player1.makeTrade(ResourceType::LUMBER, 1, ResourceType::ORE, 1, player2);

            // redirect cin back to standard input
            std::cin.rdbuf(prevcinbuf);

            // player1
            CHECK(player1.getResourceCount(ResourceType::LUMBER) == 0);
            CHECK(player1.getResourceCount(ResourceType::BRICK) == 1);
            CHECK(player1.getResourceCount(ResourceType::ORE) == 1);
            CHECK(player1.getCards().size() == 1);
            

            // player2
            CHECK(player2.getResourceCount(ResourceType::ORE) == 0);
            CHECK(player2.getResourceCount(ResourceType::LUMBER) == 1);
            CHECK(player2.getCards().size() == 1);
          
        }

        SUBCASE("no one will accept the trade") {
            player1.addResource(ResourceType::LUMBER, 1);

            // redirect cin to input buffer
            std::istringstream input("n n\n");
            std::streambuf* prevcinbuf = std::cin.rdbuf(input.rdbuf());

            player1.makeTrade(ResourceType::LUMBER, 1, ResourceType::ORE, 1, player2);

            // redirect cin back to standard input
            std::cin.rdbuf(prevcinbuf);

            // check that the trade is not done
            CHECK(player1.getResourceCount(ResourceType::LUMBER) == 1);
        }

        SUBCASE("player dont have enough resources to make offer") {
            Card* k_card = new KnightCard();  // the card will be free in the end of the test
            player1.addResource(ResourceType::LUMBER, 1);

            CHECK(!player1.makeTrade(ResourceType::LUMBER, 2, ResourceType::ORE, 1, player2));
            delete k_card;
        }
    }




    












