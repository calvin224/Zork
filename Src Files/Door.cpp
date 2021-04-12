#include "Door.h"
Door::Door(bool inLocked, int inkeyid, string inDirection, string inType) {
    isLocked = inLocked;
    keyid = inkeyid;
    direction = inDirection;
    type = inType;
}
int Door::getId(){
    return this->keyid;
}
string Door::getDirection(){
    return this->direction;
}
string Door::getType(){
    return this->type;
}
int Door::lockedCheck(){
    return this->isLocked;
}
void Door::setUnlocked(){
    this->isLocked = 0;
}
