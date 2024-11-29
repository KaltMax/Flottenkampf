#ifndef SHIPATTACK_H
#define SHIPATTACK_H

#include <iostream>
#include <string>
#include "Ship.h"

using namespace std;

class Ship;

class ShipAttack {
    public:
        ShipAttack();
        virtual ~ShipAttack();
        virtual void performAttack(Ship& attackingShip, Ship& targetShip) = 0;
        virtual void printAttackDescription() const = 0;
        string getAttackType() const;

    protected:
        int rollHitChance();
        string attackType;

    private:
};

#endif // SHIPATTACK_H
