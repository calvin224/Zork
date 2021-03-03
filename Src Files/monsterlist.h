#ifndef MONSTERLIST_H
#define MONSTERLIST_H
#include "enemy.h"
#include <vector>
using namespace std;
using std::vector;


class MonsterList
{
protected:
    vector <Enemy> level1mon;
    vector <Enemy> level2mon;
public:
    MonsterList();
    vector <Enemy> getlevel1mon();
    vector <Enemy> getlevel2mon();
};

#endif // MONSTERLIST_H
