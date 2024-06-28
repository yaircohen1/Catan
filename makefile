# // coheny405@gmail.com
CC = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

SRCS = main.cpp Catan.cpp Player.cpp Board.cpp KnightCard.cpp MonopolyCard.cpp RoadBuildCard.cpp YearOfPlentyCard.cpp VictoryPointCard.cpp RoadPiece.cpp Settlement.cpp City.cpp Vertex.cpp Edge.cpp ResourceType.cpp
HEADERS = Catan.hpp Player.hpp Board.hpp Card.hpp KnightCard.hpp MonopolyCard.hpp RoadBuildCard.hpp YearOfPlentyCard.hpp VictoryPointCard.hpp AreaPiece.hpp RoadPiece.hpp Settlement.hpp City.hpp Vertex.hpp Edge.hpp ResourceType.hpp

DEMO_SRCS = demo.cpp Catan.cpp Player.cpp Board.cpp KnightCard.cpp MonopolyCard.cpp RoadBuildCard.cpp YearOfPlentyCard.cpp VictoryPointCard.cpp RoadPiece.cpp Settlement.cpp City.cpp Vertex.cpp Edge.cpp ResourceType.cpp
DEMO_OBJS = $(DEMO_SRCS:.cpp=.o)

TEST_SRCS = Test.cpp TestCounter.cpp Catan.cpp Player.cpp Board.cpp KnightCard.cpp MonopolyCard.cpp RoadBuildCard.cpp YearOfPlentyCard.cpp VictoryPointCard.cpp RoadPiece.cpp Settlement.cpp City.cpp Vertex.cpp Edge.cpp ResourceType.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

OBJS = $(SRCS:.cpp=.o)

TARGET = catan
DEMO_TARGET = catan_demo
TEST_TARGET = catan_test

all: $(TARGET) $(DEMO_TARGET) $(TEST_TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(DEMO_TARGET): $(DEMO_OBJS)
	$(CXX) $(CXXFLAGS) -o $(DEMO_TARGET) $(DEMO_OBJS)

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(DEMO_TARGET) $(TEST_TARGET) $(OBJS) $(DEMO_OBJS) $(TEST_OBJS)

.PHONY: all clean






