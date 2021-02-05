#ifndef ENEMY_H
#define ENEMY_H
#include <string>
using namespace std;

class Enemy
{
private:
protected:
    string name;
    int hp;
    int dmgout;
    int accuracy;
public:
    Enemy(string name,int hp,int dmgout,int accuracy);
    string getShortDescription();
    int gethp();
    void sethp(int damage);
    int getdmgout();
    int getaccuracy();
};

#endif // ENEMY_H
