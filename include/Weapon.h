#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
public:
    enum class Type { Gun, Melee, Misc };

private:
    Type _type;
    double _dmg;
    int _ammo;
    int _maxAmmo;
    double _range;

public:
    Weapon(Type type, double dmg, int maxAmmo, double range);
    ~Weapon();

    Type getType() const;
    double getDamage() const;
    int getAmmo() const;
    double getRange() const;

    void setType(Type type);
    void setDamage(double dmg);
    void setAmmo(int ammo);
    void setRange(double range);

    void reload();
    bool canAttack() const;
};

#endif 
