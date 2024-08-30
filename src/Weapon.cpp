#include "Weapon.h"
#include <iostream>

Weapon::Weapon(Type type, double dmg, int maxAmmo, double range)
    : _type(type), _dmg(dmg), _ammo(maxAmmo), _maxAmmo(maxAmmo), _range(range) {}

Weapon::~Weapon() {}

Weapon::Type Weapon::getType() const {
    return _type;
}

double Weapon::getDamage() const {
    return _dmg;
}

int Weapon::getAmmo() const {
    return _ammo;
}

double Weapon::getRange() const {
    return _range;
}

void Weapon::setType(Type type) {
    _type = type;
}

void Weapon::setDamage(double dmg) {
    _dmg = dmg;
}

void Weapon::setAmmo(int ammo) {
    _ammo = ammo;
}

void Weapon::setRange(double range) {
    _range = range;
}

void Weapon::reload() {
    _ammo = _maxAmmo;
    std::cout << "Weapon reloaded. Ammo now: " << _ammo << std::endl;
}

bool Weapon::canAttack() const {
    return _ammo > 0;
}
