#ifndef HUNTER_H
#define HUNTER_H

#include <Ship.h>
#include <CriticalStrike.h>


class Hunter : public Ship
{
    public:
        Hunter();
        virtual ~Hunter();
        void printShipDescription() const override;

    protected:

    private:
};

#endif // HUNTER_H
