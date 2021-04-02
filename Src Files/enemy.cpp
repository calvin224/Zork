#include "enemy.h"

Enemy::Enemy(string name,unsigned int hp , unsigned int dmgout, unsigned int accuracy , int image){
    this->name = name;
    this->hp = hp;
    this->dmgout = dmgout;
    this->accuracy = accuracy;
    this->image = image;

}
string Enemy::getShortDescription(){
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
int Enemy::getimage(){
        return image;
}
