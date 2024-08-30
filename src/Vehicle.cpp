#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(Type type, double speed, double durability, double fuel)
    : _type(type), _speed(speed), _durability(durability), _fuel(fuel) {}

Vehicle::~Vehicle() {}

Vehicle::Type Vehicle::getType() const {
    return _type;
}

double Vehicle::getSpeed() const {
    return _speed;
}

double Vehicle::getDurability() const {
    return _durability;
}

double Vehicle::getFuel() const {
    return _fuel;
}

void Vehicle::setType(Type type) {
    _type = type;
}

void Vehicle::setSpeed(double speed) {
    _speed = speed;
}

void Vehicle::setDurability(double durability) {
    _durability = durability;
}

void Vehicle::setFuel(double fuel) {
    _fuel = fuel;
}

void Vehicle::drive(double distance) {
    if (_fuel <= 0) {
        std::cout << "Vehicle is out of fuel!" << std::endl;
        return;
    }
    double fuelConsumed = distance / 10.0;  // Assume fuel consumption rate
    _fuel -= fuelConsumed;
    if (_fuel < 0) _fuel = 0;
    std::cout << "Driving " << distance << " units. Fuel now: " << _fuel << std::endl;
}

void Vehicle::takeDamage(double amount) {
    _durability -= amount;
    if (_durability <= 0) {
        _durability = 0;
        std::cout << "Vehicle is destroyed!" << std::endl;
    } else {
        std::cout << "Vehicle takes " << amount << " damage. Durability now: " << _durability << std::endl;
    }
}

void Vehicle::repair(double amount) {
    _durability += amount;
    if (_durability > 100) {
        _durability = 100;  // Cap durability at 100
    }
    std::cout << "Vehicle repaired by " << amount << ". Durability now: " << _durability << std::endl;
}

void Vehicle::refuel(double amount) {
    _fuel += amount;
    if (_fuel > 100) {
        _fuel = 100;  // Cap fuel at 100
    }
    std::cout << "Vehicle refueled by " << amount << ". Fuel now: " << _fuel << std::endl;
}
