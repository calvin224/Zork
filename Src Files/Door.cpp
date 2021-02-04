#include "Door.h"
Door::Door(bool inLocked, int inkeyid, string inDirection) {
    isLocked = inLocked;
    keyid = inkeyid;
    direction = inDirection;
}

int Door::getId(){
    return this->keyid;
}

string Door::getDirection(){
    return this->direction;
}

int Door::lockedCheck(){
    return this->isLocked;
}

void Door::setUnlocked(){
    this->isLocked = 0;
}
