#include "Game.h"

Game::Game() {
    numberOfPlayers = 0;
    fleetSize = 0;
}

Game::~Game() {
    //dtor
}

void Game::run() {
    bool gameOver = false;

    chooseNumberOfPlayers();
    chooseFleetSize();
    assembleFleets();
    printPlayersFleets();

    while (!gameOver) {
        for(int i = 0; i < players.size(); i++) {
            cout << "\nTurn Player " << i + 1 << ". Here is your Fleet:" << endl;
            players[i].printFleetInformation();
            playerAction(i);
            if(isGameOver()) {
                gameOver = true; // Set the flag to true to exit the loop
                break;
            }
        }
    }
    printPlayersFleets();
    playerWon();
}

void Game::chooseNumberOfPlayers() {
    int input = 0;

    while(true) {
        cout << "\nChoose the number of players (2-5):" << endl;
        cin >> input;

        if(cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "\nInvalid input! Please enter a number between 2 and 5." << endl;
        }
        else if(input >= 2 && input <= 5) {
            numberOfPlayers = input;
            for(int i = 0; i < input; i++){
                players.push_back(Player());
            }
            return;
        }
        else {
            cout << "\nInvalid input! Try again!" << endl;
        }
    }
}

void Game::chooseFleetSize() {
    int input = 0;

    while(true) {
        cout << "\nChoose the number of ships for each player (1-9):" << endl;
        cin >> input;

        if(cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "\nInvalid input! Please enter a number between 1 and 9." << endl;
        }
        else if(input >= 1 && input <= 9) {
            fleetSize = input;
            return;
        }
        else {
            cout << "\nInvalid input! Try again!" << endl;
        }
    }
}

void Game::assembleFleets() {
    for(int i = 0; i < players.size(); i++){
        cout << "\nPlayer " << i + 1 << " choose your ships:" << endl;
        for(int j = 0; j < fleetSize; j++) {
            chooseShip(players[i], j);
        }
    }
}

void Game::chooseShip(Player& currentPlayer, int shipCount){
    int input = 0;
    while(true) {
        cout << "\nChoose ship number " << shipCount + 1 << ": " << "Hunter(1), Destroyer(2), Cruiser(3)" << endl;

        cin >> input;

        if(cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "\nInvalid input! Please enter a number between 1 and 3." << endl;
        }
        else if(input >= 1 && input <= 3) {
            if(input == 1) {
               currentPlayer.insertShip(new Hunter);
            }
            if(input == 2){
                currentPlayer.insertShip(new Destroyer);
            }
            if(input == 3) {
                currentPlayer.insertShip(new Cruiser);
            }
            return;
        }
        else {
            cout << "\nInvalid input! Please enter a number between 1 and 3." << endl;
        }
    }
}

void Game::printPlayersFleets() const{
    cout << "\nOverview of the Fleets: " << endl;
    for(int i = 0; i < numberOfPlayers; i++) {
        cout << "\nPlayer " << i + 1 << ": " << endl;
        players[i].printFleetInformation();
    }
}

void Game::playerAction(int playerCount) {
    int targetPlayer;
    Ship* attackingShip = nullptr;
    Ship* targetShip = nullptr;

    printPossibleTargets(playerCount);
    attackingShip = chooseAttackingShip(playerCount);
    targetPlayer = chooseTargetPlayer(playerCount);
    targetShip = chooseTargetShip(playerCount, targetPlayer);

    attackingShip->getShipAttack()->performAttack(*attackingShip, *targetShip);
}

void Game::printPossibleTargets(int playerCount) const{
    cout << "\nPossible Targets: " << endl;

    for(int i = 0; i < numberOfPlayers; i++) {
        if(i != playerCount && players[i].isAlive()) {
            cout << "\nPlayer " << i + 1 << ": " << endl;
            players[i].printFleetInformation();
        }
    }
}

Ship* Game::chooseAttackingShip(int playerCount) const {
    int input = 0;

    while(true) {
        cout << "\nPlayer " << playerCount + 1 <<  " Choose the ship you want to attack with (1 - " << players[playerCount].getFleetSize() << "):" << endl;
        cin >> input;

        if(cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "\nInvalid input! Try again!" << endl;
        }
        else if(input >= 1 && input <= players[playerCount].getFleetSize()) {
            return players[playerCount].getShip(input - 1);
        }
        else {
            cout << "\nInvalid input! Try again!" << endl;
        }
    }
}

int Game::chooseTargetPlayer(int playerCount) const {
    int input = 0;

    while (true) {
        // Print the available players to attack
        cout << "\nPlayer " << playerCount + 1 << " Choose the player you want to attack (";
        bool first = true;
        for (int i = 0; i < numberOfPlayers; i++) {
            if (i != playerCount && players[i].isAlive()) {
                if (!first) {
                    cout << ", ";
                }
                cout << i + 1;
                first = false;
            }
        }
        cout << "):" << endl;

        cin >> input;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input! Try again!" << endl;
        } else {
            input = input - 1; // e.g., Player 1 is at index 0
            if (input >= 0 && input < numberOfPlayers && input != playerCount && players[input].isAlive()) {
                return input;
            } else {
                cout << "\nInvalid input! Try again!" << endl;
            }
        }
    }
}

Ship* Game::chooseTargetShip(int currentPlayer, int targetPlayer) const {
    int input = 0;

    while(true) {
        cout << "Player " << currentPlayer + 1 << " Choose the ship you want to attack (1 - " << players[targetPlayer].getFleetSize() << "):" << endl;
        cin >> input;

        if(cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input! Try again!" << endl;
        }
        else if(input >= 1 && input <= players[targetPlayer].getFleetSize()) {
            return players[targetPlayer].getShip(input - 1);
        }
        else {
            cout << "Invalid input! Try again!" << endl;
        }
    }
}

bool Game::isGameOver() {
    int alivePlayers = 0;

    for(int i = 0; i < players.size(); i++) {
        if (players[i].isAlive()) {
            alivePlayers++;
        }
    }
    return alivePlayers < 2; // The game is over if fewer than 2 players are alive
}

void Game::playerWon() const {
    for (int i = 0; i < players.size(); i++) {
        if (players[i].isAlive()) {
            cout << "\nPlayer " << i + 1 << " has won the game!" << endl;
            return;
        }
    }
    cout << "\nNo player has won the game. It seems all players have been defeated." << endl;
}

bool Game::playAgain() {
    string input;

    while (true) {
        cout << "\nDo you want to play again? (y/n)" << endl;
        getline(cin, input);

        if (!input.empty()) {
            char firstChar = input[0];
            if (firstChar == 'y' || firstChar == 'Y') {
                return true;
            }
            else if (firstChar == 'n' || firstChar == 'N') {
                return false;
            }
            else {
                cout << "\nInvalid input! Try again!" << endl;
            }
        } else {
            cout << "\nNo input detected! Try again!" << endl;
        }
    }
}
