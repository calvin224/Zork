#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"
#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
public:
    void addItem(Item item);
    void addNPCItem(Item item);
    Character();
    virtual ~Character();
    string shortDescription();
    string longDescription();
    int findItemInInv(string itemname);
    void setHealthPoint(int &HP);
    int getHealthPoint();
    int getDamageOut();
    int getKeyID(int x);
    void potionDrank();
    int getItemID(int x);
    string getItemName (int x);
    int getItemDmg (int x);
    void equipWeapon(int initemid);
    void usedItem(string itemname);
    void death();
    string description;
    vector < Item > itemsInCharacter;
    int hp;
    string inventoryList();
    int getItemAmount();
    void setcharacterdmgout(int dmg);
    int dmgout;
};

#endif /*CHARACTER_H_*/
