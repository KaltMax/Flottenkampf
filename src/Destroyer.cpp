#include "Destroyer.h"

Destroyer::Destroyer() {
    shipType = "Destroyer";
    shipArmor = 150;
    shipSize = 6;
    shipDamage = 60;
    shipAttack = new FindTarget;
}

Destroyer::~Destroyer() {
}

void Destroyer::printShipDescription() const {
    cout << "Armor: 150 | Size: 6 | Damage: 60 | Special Attack: Find Target" << endl;
}
