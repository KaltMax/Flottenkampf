#include "Hunter.h"

Hunter::Hunter() {
    shipType = "Hunter";
    shipArmor = 75;
    shipSize = 4;
    shipDamage = 30;
    shipAttack = new CriticalStrike;
}

Hunter::~Hunter() {
}

void Hunter::printShipDescription() const{
    cout << "Armor: 75 | Size: 4 | Damage: 30 | Special Attack: Critical Strike" << endl;
}
