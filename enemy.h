#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <QPixmap>
#include <iostream>
using namespace std;

//abstract class with virtual functions
class Enemy
{
protected:
    //bit structures
    unsigned int hp = 10;
    unsigned int dmgout : 6;
    unsigned int accuracy;
    unsigned int image : 5;
public:
   string name;
   virtual string getShortDescription();
   virtual int gethp();
   virtual void sethp(int damage);
   virtual int getdmgout();
   virtual  int getaccuracy();
   virtual int getimage();
};
//polymorphism + inheritance
class Goblin: public Enemy{
public:
    Goblin();
    friend Enemy;
};

class superArcher {
public:
    string newname = "superArcher";
    int newdmgout = 4;
};
//multi inheritance

class Archer: public Enemy, public superArcher{
public:
    Archer();
    friend superArcher;
};


#endif // ENEMY_H
