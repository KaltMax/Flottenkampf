#ifndef CRITICALSTRIKE_H
#define CRITICALSTRIKE_H

#include <ShipAttack.h>


class CriticalStrike : public ShipAttack {
    public:
        CriticalStrike();
        virtual ~CriticalStrike();
        void performAttack(Ship& attackingShip, Ship& targetShip) override;
        void printAttackDescription() const override;

    protected:

    private:
};

#endif // CRITICALSTRIKE_H
