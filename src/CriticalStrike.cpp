#include "CriticalStrike.h"

CriticalStrike::CriticalStrike() {
    attackType = "Critical Strike";
}

CriticalStrike::~CriticalStrike() {
    //dtor
}

void CriticalStrike::performAttack(Ship& atackingShip, Ship& targetShip) {
    int hitChance  = rollHitChance();
    int damage = 0;

    cout << "The Hunter attacks with a Hit-Chance of " << hitChance << ". " << endl;

    if(hitChance > targetShip.getShipSize()) {
        if(hitChance > 8) {
            damage = atackingShip.getShipDamage() * 2;
            targetShip.decreaseShipArmor(damage);

            cout << "Hit-Chance over 8! Critical Strike triggered! Hunter dealing double damage!" << endl;
        }
        else {
            damage = atackingShip.getShipDamage();
            targetShip.decreaseShipArmor(damage);
        }

        cout << "Enemy's " << targetShip.getShipType() << " successfully hit and dealt "
            << damage << " damage." << endl;
    }
    else {
        cout << "Hit-Chance too low. Attack missed!" << endl;
    }
}

void CriticalStrike::printAttackDescription() const{
    cout << "Critical Strike: If the Hit-Chance is 9 or 10, the Hunter deals double damage." << endl;
}
