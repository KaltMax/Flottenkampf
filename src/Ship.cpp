#include "Ship.h"

Ship::Ship() {
    shipType = "";
    shipArmor = 0;
    shipDamage = 0;
    shipSize = 0;
    shipAttack = nullptr;
}

Ship::~Ship() {
    delete shipAttack;
}

int Ship::getShipArmor() const {
    return shipArmor;
}

int Ship::getShipSize() const {
    return shipSize;
}

int Ship::getShipDamage() const {
    return shipDamage;
}

string Ship::getShipType() const {
    return shipType;
}

void Ship::decreaseShipArmor(int value) {
    if(value < 0) {
        return;
    }

    shipArmor -= value;
    if(shipArmor < 0) {
        shipArmor = 0;
    }
}

void Ship::printShipStats() const {
    cout << "Ship Type: " << shipType << " || Armor: " << shipArmor << " || Size: " << shipSize << " || Damage: " << shipDamage << endl;
}

ShipAttack* Ship::getShipAttack() const {
    return shipAttack;
}
