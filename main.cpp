#include <iostream>
#include <random>
#include <ctime>

#include "VisualsAndUtility.h"
#include "Game.h"

using namespace std;

int main() {
    srand(time(nullptr));
    bool run = true;
    Game game;

    VisualsAndUtility::printTitle();

    while(run){
        game.run();
        run = game.playAgain();
    }

    cout << "Goodbye and thanks for playing!" << endl;

    return 0;
}
