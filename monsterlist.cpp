#include "monsterlist.h"
using namespace std;
MonsterList::MonsterList()
{
    Goblin goblin;
    Archer archer;
    level1mon.push_back(goblin);
    level1mon.push_back(archer);

}

std::vector<Enemy> MonsterList::getlevel1mon(){
    return level1mon;
}

std::vector<Enemy> MonsterList::getlevel2mon(){
    return level2mon;
}
