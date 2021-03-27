#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <QPixmap>
using namespace std;

class Enemy
{
private:
protected:
    string name;
    int hp;
    int dmgout;
    int accuracy;
    int image;
public:
    Enemy(string name,int hp,int dmgout,int accuracy,int image );
    string getShortDescription();
    int gethp();
    void sethp(int damage);
    int getdmgout();
    int getaccuracy();
    int getimage();
};

#endif // ENEMY_H
