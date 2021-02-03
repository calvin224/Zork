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
public:
    Enemy(string name,int hp,int dmgout);
    string getShortDescription();
    int gethp();
    void sethp(int damage);
    int getdmgout();
};

#endif // ENEMY_H
