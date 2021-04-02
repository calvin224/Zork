#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <QPixmap>
#include <iostream>
using namespace std;

class Enemy
{
private:
protected:
    string name;
    //bit structures
    unsigned int hp : 5;
    unsigned int dmgout : 6;
    unsigned int accuracy;
    unsigned int image : 5;
public:
    Enemy(string name,unsigned int hp,unsigned int dmgout,unsigned int accuracy,int image );
    string getShortDescription();
    int gethp();
    void sethp(int damage);
    int getdmgout();
    int getaccuracy();
    int getimage();
};

#endif // ENEMY_H
