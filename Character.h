#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
private:	
public:
    void addItem(Item item);
    Character();
	string shortDescription();
	string longDescription();
    int findItemInInv(string itemname);
    void setHealthPoint(int HP);
    int getHealthPoint();
    int getDamageOut();
    void potionDrank();
    int getItemID(int x);
    void equipWeapon(int initemid);
    void death();
    string description;
    vector < Item > itemsInCharacter;
    int hp;
    string inventoryList();
    void setcharacterdmgout(int dmg);
    int dmgout;
};

#endif /*CHARACTER_H_*/
