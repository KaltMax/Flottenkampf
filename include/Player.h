#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Player {
    public:
        Player();
        ~Player();
        void setPlayerName(string name);
        string getPlayerName() const;
        vector<Ship*> getFleet() const;
        Ship* getShip(int index) const;
        int getFleetSize() const;
        void printFleetInformation() const;
        bool isAlive() const;
        void insertShip(Ship* newShip);

    private:
    string playerName;
    vector<Ship*> fleet;
};

#endif // PLAYER_H
