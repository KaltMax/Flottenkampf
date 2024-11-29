#ifndef BOMBARDMENT_H
#define BOMBARDMENT_H

#include "ShipAttack.h"

class Bombardment : public ShipAttack {
    public:
        Bombardment();
        virtual ~Bombardment();
        void performAttack(Ship& attackingShip, Ship& targetShip) override;
        void printAttackDescription() const override;
};

#endif // BOMBARDMENT_H
