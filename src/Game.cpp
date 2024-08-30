#include "Game.h"
#include <iostream>

Game::Game() {
    _player = new Player("Player1", 100);
    _vehicle = new Vehicle(Vehicle::Type::Car, 100, 100, 50);
    _npc = new NPC("NPC1", 100);
    _map = new Map(10, 10);  
}

Game::~Game() {
    delete _player;
    delete _vehicle;
    delete _npc;
    delete _map;
}

void Game::start() {
    std::cout << "Game started!" << std::endl;

    _map->setCellType(3, 3, Map::CellType::Obstacle);
    _map->setCellType(3, 4, Map::CellType::Obstacle);
    _map->setCellType(3, 5, Map::CellType::Obstacle);

    _map->setCellType(2, 2, Map::CellType::HealthPack);
    _map->setCellType(7, 7, Map::CellType::HealthPack);
}

void Game::update() {
    std::cout << "Game updating..." << std::endl;
    _player->attack();
    _npc->interact();
    _vehicle->drive(50);

    std::pair<int, int> playerPosition = {5, 5}; 
    _npc->update(*_map, playerPosition);  
}

void Game::end() {
    std::cout << "Game ended!" << std::endl;
}
