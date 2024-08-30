#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Vehicle.h"
#include "NPC.h"
#include "Map.h"

class Game {
private:
    Player* _player;
    Vehicle* _vehicle;
    NPC* _npc;
    Map* _map;  // Add a map to the game

public:
    Game();
    ~Game();

    void start();
    void update();
    void end();
};

#endif
