#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Weapon.h"

class Player {
private:
    double _health;
    std::string _name;
    std::vector<Weapon*> _inventory;  
    int _currentWeaponIndex; 

public:
    Player(const std::string& name, double health);
    ~Player();

    double getHealth() const;
    const std::string& getName() const;
    Weapon* getEquippedWeapon() const;

    void setHealth(double health);
    void setName(const std::string& name);

    void addWeapon(Weapon* weapon);
    void switchWeapon(int index);
    void attack();
    void takeDamage(double amount);
    void heal(double amount); 
    void move(double dx, double dy); 
};

#endif 
