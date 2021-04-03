#include "enemy.h"
Goblin::Goblin(){
    this->name = "Goblin";
    this->hp = 4;
    this->dmgout = 2;
    this->accuracy = 96;
    this->image = 0;
}

Archer::Archer(){
    this->name = "Archer";
    this->hp = 4;
    this->dmgout = 2;
    this->accuracy = 96;
    this->image = 1;
    int x = (rand() % 100);
    if(x > 0){
        this->name = superArcher().newname;
        this->dmgout = superArcher().newdmgout;
    }
}

string Enemy::getShortDescription(){
    return this->name;
}

int Enemy::gethp(){
    return this->hp;
}
void Enemy::sethp(int damage){
   this->hp = this->hp - damage;
}
int Enemy::getdmgout(){
    return this->dmgout;
}

int Enemy::getaccuracy(){
    return this->accuracy;
}
int Enemy::getimage(){
        return this->image;
}
