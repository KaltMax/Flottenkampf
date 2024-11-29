#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Ship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Hunter.h"
#include "ShipAttack.h"
#include "CriticalStrike.h"
#include "FindTarget.h"
#include "Bombardment.h"
#include "VisualsAndUtility.h"

#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Game
{
    public:
        Game();
        ~Game();
        void run();
        bool playAgain();

    private:
        int numberOfPlayers;
        int fleetSize;
        vector<Player> players;

        void chooseNumberOfPlayers();
        void chooseFleetSize();
        void assembleFleets();
        void chooseShip(Player& currentPlayer, int shipCount);
        void printPlayersFleets() const;
        void playerAction(int playerCount);
        void printPossibleTargets(int playerCount) const;
        Ship* chooseAttackingShip(int playerCount) const;
        int chooseTargetPlayer(int playerCount) const;
        Ship* chooseTargetShip(int currentPlayer, int targetPlayer) const;
        bool isGameOver();
        void playerWon() const;

};

#endif // GAME_H
