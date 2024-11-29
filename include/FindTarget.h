#ifndef FINDTARGET_H
#define FINDTARGET_H

#include <ShipAttack.h>

using namespace std;

class FindTarget : public ShipAttack
{
    public:
        FindTarget();
        virtual ~FindTarget();
        void performAttack(Ship& attackingShip, Ship& targetShip) override;
        void printAttackDescription() const override;

    protected:

    private:
};

#endif // FINDTARGET_H
