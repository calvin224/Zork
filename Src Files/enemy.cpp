#include "enemy.h"

Enemy::Enemy(string name,int hp ){
    this->name = name;
    this->hp = hp;
}
string Enemy::getShortDescription() {
    return name;
}

