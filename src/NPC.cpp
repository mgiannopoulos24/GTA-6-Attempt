#include "NPC.h"
#include "Pathfinder.h"
#include <iostream>
#include <cstdlib>  

NPC::NPC(const std::string& name, double health)
    : _name(name), _health(health), _currentState(State::Idle), _pathIndex(0), _backupCalled(false) {}

NPC::~NPC() {}

const std::string& NPC::getName() const {
    return _name;
}

double NPC::getHealth() const {
    return _health;
}

NPC::State NPC::getCurrentState() const {
    return _currentState;
}

void NPC::setName(const std::string& name) {
    _name = name;
}

void NPC::setHealth(double health) {
    _health = health;
}

void NPC::setState(State newState) {
    _currentState = newState;
}

void NPC::update(const Map& map, std::pair<int, int> playerPosition) {
    handleState(map, playerPosition);
}

void NPC::handleState(const Map& map, std::pair<int, int> playerPosition) {
    switch (_currentState) {
        case State::Idle:
            std::cout << _name << " is idling." << std::endl;
            if (rand() % 10 < 3) { // 30% chance
                setState(State::Wandering);
            }
            break;

        case State::Wandering:
            std::cout << _name << " is wandering around." << std::endl;
            if (rand() % 10 < 2) { // 20% chance
                setState(State::Idle);
            } else {
                findPathToTarget(map, playerPosition);
            }
            break;

        case State::Attacking:
            std::cout << _name << " is attacking!" << std::endl;
            // Attack logic
            if (_health < 20) {  
                setState(State::SearchingHealthPack);
            }
            break;

        case State::Fleeing:
            std::cout << _name << " is fleeing!" << std::endl;
            findPathToTarget(map, {0, 0}); 
            break;

        case State::SearchingHealthPack:
            std::cout << _name << " is searching for a health pack." << std::endl;
            searchForHealthPack(map);
            break;

        case State::CallingBackup:
            if (!_backupCalled) {
                std::cout << _name << " is calling for backup!" << std::endl;
                callForBackup();
                _backupCalled = true;  
            }
            break;
    }

    moveToNextPosition();
}

void NPC::findPathToTarget(const Map& map, std::pair<int, int> targetPosition) {
    _path = Pathfinder::findPath(map, {_pathIndex, _pathIndex}, targetPosition);
    _pathIndex = 0;
}

void NPC::moveToNextPosition() {
    if (!_path.empty() && _pathIndex < _path.size()) {
        auto [nextX, nextY] = _path[_pathIndex];
        std::cout << _name << " moves to position (" << nextX << ", " << nextY << ")." << std::endl;
        _pathIndex++;
    }
}

void NPC::searchForHealthPack(const Map& map) {
    // Example: search map for nearest health pack
    std::pair<int, int> healthPackPosition = {2, 2}; 
    findPathToTarget(map, healthPackPosition);
}

void NPC::callForBackup() {
    std::cout << _name << " has called for backup. New NPCs are arriving!" << std::endl;
    // Example logic for spawning new NPCs
}

void NPC::interact() {
    std::cout << "Interacting with NPC: " << _name << std::endl;
}

void NPC::takeDamage(double amount) {
    _health -= amount;
    if (_health <= 0) {
        _health = 0;
        std::cout << _name << " has died." << std::endl;
    } else {
        std::cout << _name << " takes " << amount << " damage. Health now: " << _health << std::endl;
        if (_health < 20) {
            if (!_backupCalled) {
                setState(State::CallingBackup);
            } else {
                setState(State::Fleeing);
            }
        }
    }
}

void NPC::addDialogue(const std::string& dialogue) {
    _dialogues.push_back(dialogue);
}

void NPC::speak() {
    if (!_dialogues.empty()) {
        int randomIndex = rand() % _dialogues.size();
        std::cout << _name << " says: " << _dialogues[randomIndex] << std::endl;
    } else {
        std::cout << _name << " has nothing to say." << std::endl;
    }
}
