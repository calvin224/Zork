#include "monsterlist.h"
using namespace std;
MonsterList::MonsterList()
{
    Goblin* gob = new Goblin();
    Enemy* actuallygoblin = gob;
    Goblin* goblin = dynamic_cast<Goblin*>(actuallygoblin);
    level1mon.push_back(*goblin);


}

std::vector<Enemy> MonsterList::getlevel1mon(){
    return level1mon;
}

std::vector<Enemy> MonsterList::getlevel2mon(){
    return level2mon;
}
