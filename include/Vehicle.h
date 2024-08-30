#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
public:
    enum class Type { Car, Bike, Helicopter };

private:
    Type _type;
    double _speed;
    double _durability;
    double _fuel;

public:
    Vehicle(Type type, double speed, double durability, double fuel);
    ~Vehicle();

    Type getType() const;
    double getSpeed() const;
    double getDurability() const;
    double getFuel() const;

    void setType(Type type);
    void setSpeed(double speed);
    void setDurability(double durability);
    void setFuel(double fuel);

    void drive(double distance);
    void takeDamage(double amount);
    void repair(double amount);
    void refuel(double amount);
};

#endif 
