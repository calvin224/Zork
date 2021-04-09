#include "enemy.h"
struct dmg{
     int x=0;
     dmg() : x(0){};
     dmg(int _x):x(_x){}
dmg operator +  (const dmg& other){
    return dmg(this->x * other.x);
}
};

Goblin::Goblin(){
    this->name= "Goblin";
    this->hp = 4;
    this->dmgout = 2;
    this->accuracy = 96;
    this->image = ":/Images/shrek.jpg";
    int x = 96;
    if(x > 95){
    this->name="SuperGoblin";
    //operator overloading
        dmg temp = dmg(3);
        dmg temp2 = dmg(dmgout);
        dmg newdmg = temp + temp2;
        this->dmgout = newdmg.x;
        this->accuracy = 75;
  }
}


Archer::Archer(){
    this->name = "Archer";
    this->hp = 4;
    this->dmgout = 2;
    this->accuracy = 96;
    this->image = ":/Images/Donkey.png";
    int x = (rand() % 100);
    if(x > 95){
        this->name = superArcher().newname;
        this->dmgout = superArcher().newdmgout;
        this->image = superArcher().newimage;
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
string Enemy::getimage(){
        return this->image;
}
