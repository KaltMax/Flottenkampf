#include "Player.h"

Player::Player() {
    playerName = "";
}

Player::~Player() {
    for(int i = 0; i < fleet.size(); i++) {
        delete fleet[i];
    }
}

void Player::setPlayerName(string name) {
    playerName = name;
}

string Player::getPlayerName() const {
    return playerName;
}

vector<Ship*> Player::getFleet() const {
    return fleet;
}

Ship* Player::getShip(int index) const {
    if(index >= 0 && index < fleet.size()) {
        return fleet[index];
    }
    else {
        return nullptr; // Return null if the index is out of range
    }
}

int Player::getFleetSize() const {
    return fleet.size();
}

void Player::printFleetInformation() const {
    int shipCount = 1;
    for(int i = 0; i < fleet.size(); i++) {
        cout << shipCount << ".) ";
        fleet[i]->printShipStats();
        shipCount++;
    }
}

bool Player::isAlive() const {
    int totalArmor = 0;
    for (int i = 0; i < fleet.size(); i++) {
        totalArmor += fleet[i]->getShipArmor();
    }
    return totalArmor > 0;
}

void Player::insertShip(Ship* newShip) {
    fleet.push_back(newShip);
}
