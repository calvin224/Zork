#include "enemy.h"

Enemy::Enemy(string name,int hp , int dmgout ){
    this->name = name;
    this->hp = hp;
    this->dmgout = dmgout;
}
string Enemy::getShortDescription() {
    return name;
}

int Enemy::gethp(){
    return hp;
}
void Enemy::sethp(){
   hp = hp -1;
}
int Enemy::getdmgout(){
    return dmgout;
}
