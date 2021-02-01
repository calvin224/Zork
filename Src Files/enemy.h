#ifndef ENEMY_H
#define ENEMY_H
#include <string>
using namespace std;

class Enemy
{
private:
    string name;
    int hp;
public:
    Enemy(string name,int hp);
    string getShortDescription();
    int gethp();
    void sethp();
};

#endif // ENEMY_H
