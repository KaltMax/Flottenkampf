#ifndef DESTROYER_H
#define DESTROYER_H

#include <Ship.h>
#include <FindTarget.h>

class Destroyer : public Ship
{
    public:
        Destroyer();
        virtual ~Destroyer();
        void printShipDescription() const override;

    protected:

    private:
};

#endif // DESTROYER_H
