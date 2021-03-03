#include "monsterlist.h"
using namespace std;
MonsterList::MonsterList()
{
    Enemy *Goblin(new Enemy("Goblin",4,2,100));
    Enemy *skeletonSwordsman(new Enemy("Skeleton SwordsMan", 4,1,95));
    level1mon.push_back(*Goblin);
    level1mon.push_back(*skeletonSwordsman);
    Enemy *GoblinLeader(new Enemy("Goblin Leader",6,2,100));
    level2mon.push_back(*GoblinLeader);

}

std::vector<Enemy> MonsterList::getlevel1mon(){
    return level1mon;
}

std::vector<Enemy> MonsterList::getlevel2mon(){
    return level2mon;
}
