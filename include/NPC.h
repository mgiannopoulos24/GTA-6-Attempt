#ifndef NPC_H
#define NPC_H

#include <string>
#include <vector>
#include "Map.h"

class NPC {
public:
    enum class State { Idle, Wandering, Attacking, Fleeing, SearchingHealthPack, CallingBackup }; 

private:
    std::string _name;
    double _health;
    State _currentState;
    std::vector<std::pair<int, int>> _path; 
    int _pathIndex; 
    bool _backupCalled; 

public:
    NPC(const std::string& name, double health);
    ~NPC();

    const std::string& getName() const;
    double getHealth() const;
    State getCurrentState() const; 

    void setName(const std::string& name);
    void setHealth(double health);

    void update(const Map& map, std::pair<int, int> playerPosition); 
    void setState(State newState); 
    void handleState(const Map& map, std::pair<int, int> playerPosition);

    void interact();
    void takeDamage(double amount);
    void addDialogue(const std::string& dialogue);
    void speak();

    void findPathToTarget(const Map& map, std::pair<int, int> targetPosition);
    void moveToNextPosition();
    void searchForHealthPack(const Map& map); 
    void callForBackup(); 
};

#endif // NPC_H
