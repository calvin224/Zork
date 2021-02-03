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
public:
    MonsterList();
    vector <Enemy> getlevel1mon();
};

#endif // MONSTERLIST_H
