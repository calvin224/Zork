#include "monsterlist.h"
using namespace std;
MonsterList::MonsterList()
{
    Enemy *Goblin(new Enemy("Goblin",4,2,100,0));
    level1mon.push_back(*Goblin);
    Enemy *skeletonSwordsman(new Enemy("Skeleton SwordsMan", 4,1,95,1));
    level1mon.push_back(*skeletonSwordsman);
    Enemy *GoblinLeader(new Enemy("Goblin Leader",6,2,100,0));
    level2mon.push_back(*GoblinLeader);

}

std::vector<Enemy> MonsterList::getlevel1mon(){
    return level1mon;
}

std::vector<Enemy> MonsterList::getlevel2mon(){
    return level2mon;
}
