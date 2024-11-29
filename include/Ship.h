#ifndef SHIP_H
#define SHIP_H

#include "ShipAttack.h"

#include <iostream>
#include <string>

using namespace std;

class ShipAttack;

class Ship {
    public:
        Ship();
        virtual ~Ship();
        int getShipArmor() const;
        int getShipSize() const;
        int getShipDamage() const;
        string getShipType() const;
        void decreaseShipArmor(int value);
        void printShipStats() const;
        virtual void printShipDescription() const = 0;
        ShipAttack* getShipAttack() const;

    protected:
        string shipType;
        int shipArmor;
        int shipSize;
        int shipDamage;
        ShipAttack* shipAttack;

    private:
};

#endif // SHIP_H
