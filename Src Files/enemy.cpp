#include "enemy.h"

Enemy::Enemy(string name,int hp , int dmgout, int accuracy ){
    this->name = name;
    this->hp = hp;
    this->dmgout = dmgout;
    this->accuracy = accuracy;
}
string Enemy::getShortDescription() {
    return name;
}

int Enemy::gethp(){
    return hp;
}
void Enemy::sethp(int damage){
   hp = hp - damage;
}
int Enemy::getdmgout(){
    return dmgout;
}

int Enemy::getaccuracy(){
    return accuracy;
}
