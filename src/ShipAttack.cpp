#include "ShipAttack.h"

ShipAttack::ShipAttack() {
    attackType = "";
}

ShipAttack::~ShipAttack() {
    //dtor
}

string ShipAttack::getAttackType() const{
    return attackType;
}


int ShipAttack::rollHitChance() {
    return rand() % 10 + 1;
}
