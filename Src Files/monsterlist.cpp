#include "monsterlist.h"
using namespace std;
MonsterList::MonsterList()
{
    Enemy *Goblin(new Enemy("Goblin",4,2,100));
    Enemy *skeletonSwordsman(new Enemy("Skeleton SwordsMan", 4,1,95));
    level1mon.push_back(*Goblin);
    level1mon.push_back(*skeletonSwordsman);

}

std::vector<Enemy> MonsterList::getlevel1mon(){
    return level1mon;
}
