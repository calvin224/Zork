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
    //C++ Object Construction Sequence
    Archer archer;
    level1mon.push_back(archer);
    ZombieKnight zombieknight;
    Phantom phantom;
    level2mon.push_back(zombieknight);
    level2mon.push_back(phantom);
    Golem golem;
    FlameBoss flameboss;
    boss.push_back(golem);
    boss.push_back(flameboss);


}
vector<Enemy> MonsterList::getlevel1mon(){
    return level1mon;
}
vector<Enemy> MonsterList::getlevel2mon(){
    return level2mon;
}
vector<Enemy> MonsterList::getboss(){
    return boss;
}

