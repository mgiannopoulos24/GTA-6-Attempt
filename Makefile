CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
SRC = src/main.cpp src/Player.cpp src/Weapon.cpp src/Vehicle.cpp src/NPC.cpp src/Game.cpp src/Pathfinder.cpp src/Map.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = gta_clone

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
