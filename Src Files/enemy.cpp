#include "enemy.h"
//union
union enemyvals {
    int a;
    int b;
    int c;
};

union enemyvals x;

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
    this->accuracy = 90;
    this->image = ":/Images/goblin.png";
    int x = (rand() % 100);
    int y = (rand() % 24 + 75);
    int z = (rand() % 24 + 75);
    if(x > 95){
            this->name="SuperGoblin";
            //operator overloading
                dmg temp = dmg(3);
                dmg temp2 = dmg(dmgout);
                dmg newdmg = temp + temp2;
                this->dmgout = newdmg.x;
                mypair <int> myobject (z,y);
                this->accuracy=myobject.getmax();
                this->image = ":/Images/superGoblin.png";
          }
}
Archer::Archer(){
    this->name = "Archer";
    this->hp = 4;
    this->dmgout = 2;
    this->accuracy = 96;
    this->image = ":/Images/skeleton.png";
    int x = (rand() % 100);
    int y = (rand() % 24 + 75);
    int z = (rand() % 24 + 75);
    if(x > 95){
        this->name = superArcher().newname;
        this->dmgout = superArcher().newdmgout;
        this->image = superArcher().newimage;
        this->accuracy = Min<int>(y, z);
    }
}
Golem::Golem(){
    this->name= "Golem";
    this->hp = 12;
    this->dmgout = 4;
    this->accuracy = 90;
    this->image = ":/Images/golemBoss";
}
FlameBoss::FlameBoss(){
    this->name= "Flame Boss";
    this->hp = 8;
    this->dmgout = 5;
    this->accuracy = 95;
    this->image = ":/Images/flameboss";
}
Phantom::Phantom(){
    this->name= "Phantom";
    this->hp = 6;
    this->dmgout = 2;
    this->accuracy = 95;
    this->image = ":/Images/phantom";
}
ZombieKnight::ZombieKnight(){
    this->name= "Zombie Knight";
    this->hp = 4;
    this->dmgout = 3;
    this->accuracy = 95;
    this->image = ":/Images/zombieknight";
}
string Enemy::getShortDescription(){
    return this->name;
}
int Enemy::gethp(){
    x.a = this->hp;
    return x.a;
}
void Enemy::sethp(int damage){
   this->hp = this->hp - damage;
}
int Enemy::getdmgout(){
    x.b = this->dmgout;
    return x.b;
}
int Enemy::getaccuracy(){
    x.c = this->dmgout;
    return x.c;
}
string Enemy::getimage(){
        return this->image;
}
