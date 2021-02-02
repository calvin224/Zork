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
void Enemy::sethp(int dmg){
   hp = hp -dmg;
}
int Enemy::getdmgout(){
    return dmgout;
}
