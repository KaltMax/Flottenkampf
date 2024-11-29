#include "FindTarget.h"

FindTarget::FindTarget() {
    attackType = "Find Target";
}

FindTarget::~FindTarget() {
}

void FindTarget::performAttack(Ship& attackingShip, Ship& targetShip) {
    int hitChance  = rollHitChance() + 2; // Die Hit-Chance wird um 2 erhöht

    cout << "The Destroyer attacks with a Hit-Chance of " << hitChance << ". " << endl;

    if(hitChance > targetShip.getShipSize()) {
        targetShip.decreaseShipArmor(attackingShip.getShipDamage());

        cout << "Enemy's " << targetShip.getShipType() << " successfully hit and dealt "
            << attackingShip.getShipDamage() << " damage." << endl;
    }
    else {
        cout << "Hit-Chance too low. Attack missed!" << endl;
    }
}

void FindTarget::printAttackDescription() const{
    cout << "Find Target: Allows the Destroyer to raise the Hit-Chance by 2." << endl;
}
