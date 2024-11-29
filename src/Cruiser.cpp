#include "Cruiser.h"

Cruiser::Cruiser() {
    shipType = "Cruiser";
    shipArmor = 250;
    shipSize = 8;
    shipDamage = 50;
    shipAttack = new Bombardment;
}

Cruiser::~Cruiser() {
}

void Cruiser::printShipDescription() const{
    cout << "Armor: 250 | Size: 8 | Damage: 50 | Special Attack: Bombardment" << endl;
}
