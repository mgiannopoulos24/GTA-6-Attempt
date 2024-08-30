#include "Player.h"
#include <iostream>

Player::Player(const std::string& name, double health)
    : _name(name), _health(health), _currentWeaponIndex(-1) {}

Player::~Player() {
    for (auto weapon : _inventory) {
        delete weapon;
    }
}

double Player::getHealth() const {
    return _health;
}

const std::string& Player::getName() const {
    return _name;
}

Weapon* Player::getEquippedWeapon() const {
    if (_currentWeaponIndex >= 0 && _currentWeaponIndex < _inventory.size()) {
        return _inventory[_currentWeaponIndex];
    }
    return nullptr;
}

void Player::setHealth(double health) {
    _health = health;
}

void Player::setName(const std::string& name) {
    _name = name;
}

void Player::addWeapon(Weapon* weapon) {
    _inventory.push_back(weapon);
    if (_currentWeaponIndex == -1) {
        _currentWeaponIndex = 0;  // Automatically equip the first added weapon
    }
}

void Player::switchWeapon(int index) {
    if (index >= 0 && index < _inventory.size()) {
        _currentWeaponIndex = index;
        std::cout << _name << " switched to weapon at index " << index << "." << std::endl;
    } else {
        std::cout << "Invalid weapon index!" << std::endl;
    }
}

void Player::attack() {
    if (Weapon* weapon = getEquippedWeapon()) {
        std::cout << _name << " attacks with " 
                  << (weapon->getType() == Weapon::Type::Gun ? "Gun" : "Other weapon") 
                  << " dealing " << weapon->getDamage() << " damage." << std::endl;
    } else {
        std::cout << _name << " has no weapon equipped." << std::endl;
    }
}

void Player::takeDamage(double amount) {
    _health -= amount;
    if (_health <= 0) {
        _health = 0;
        std::cout << _name << " has died." << std::endl;
    } else {
        std::cout << _name << " takes " << amount << " damage. Health now: " << _health << std::endl;
    }
}

void Player::heal(double amount) {
    _health += amount;
    if (_health > 100) {
        _health = 100;  // Cap health at 100
    }
    std::cout << _name << " heals for " << amount << " health. Health now: " << _health << std::endl;
}

void Player::move(double dx, double dy) {
    std::cout << _name << " moves to position (" << dx << ", " << dy << ")." << std::endl;
}
