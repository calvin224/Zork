#include "monsterlist.h"
using namespace std;
MonsterList::MonsterList()
{
    Goblin* gob = new Goblin();
    Enemy* actuallygoblin = gob;
    //dynamic_cast
    Goblin* goblin = dynamic_cast<Goblin*>(actuallygoblin);
    //pointer
    level1mon.push_back(*goblin);
    C++ Object
     //Construction Sequence
    Archer archer;
    level1mon.push_back(archer);
}
std::vector<Enemy> MonsterList::getlevel1mon(){
    return level1mon;
}

std::vector<Enemy> MonsterList::getlevel2mon(){
    return level2mon;
}
