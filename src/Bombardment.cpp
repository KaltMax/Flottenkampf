#include "Bombardment.h"


Bombardment::Bombardment() {
    attackType = "Bombardment";
}

Bombardment::~Bombardment() {
}

void Bombardment::performAttack(Ship& attackingShip, Ship& targetShip) {
    int hitChance = rollHitChance();

    cout << "The cruiser attacks with a Hit-Chance of: " << hitChance << ". " << endl;

    if(hitChance > targetShip.getShipSize()) {
        targetShip.decreaseShipArmor(attackingShip.getShipDamage());

        cout << "Enemy's " << targetShip.getShipType() << " successfully hit and dealt "
                  << attackingShip.getShipDamage() << " damage." << endl;

        cout << "Cruiser's special skill triggered." << endl;
        performAttack(attackingShip, targetShip);
    }
    else {
    cout << "Hit-Chance too low. Attack missed!" << endl;
    }
}


void Bombardment::printAttackDescription() const{
    cout << "Bombardment: Allows the cruiser to perform additional attacks if the initial attack is successful." << endl;
}
