#ifndef CRUISER_H
#define CRUISER_H

#include <Ship.h>
#include <Bombardment.h>


class Cruiser : public Ship
{
    public:
        Cruiser();
        virtual ~Cruiser();
        void printShipDescription() const override;

    protected:

    private:
};

#endif // CRUISER_H
