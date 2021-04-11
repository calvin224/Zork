#include "Character.h"

Character::Character() {
    this->description = "Main Character";
    this->hp = 10;
    this->dmgout = 2;
}

Character::~Character() {
    cout << "Character destructor executed" ;
}

void Character::setHealthPoint(int &HP){
   this->hp = HP;
}
int Character::getHealthPoint(){
    return hp;
}
int Character::getDamageOut(){
    return dmgout;
}
void Character::addItem(Item item) {
    itemsInCharacter.push_back(item);
}

void Character::addNPCItem(Item inItem) {
    itemsInCharacter.push_back(inItem);
}
int Character::getItemID(int x){
    return itemsInCharacter[x].getItemID();
}

string Character::getItemName(int x){
    return itemsInCharacter[x].getShortDescription();
}

int Character::getItemDmg(int x){
    return itemsInCharacter[x].getWeaponCheck();
}

int Character::getKeyID(int x){
    return itemsInCharacter[x].getKeyID();
}

void Character::setcharacterdmgout(int dmg){
     dmgout = dmg;
}
void Character::equipWeapon(int weapondmg) {
    int dmg = weapondmg;
    switch(dmg) {
    case 1:
    {
      dmgout = 4;
      break;
    }
    case 2:
    {
      dmgout = 5;
      break;
    }
    case 3:
    {
      dmgout = 6;
      break;
    }
    }
}

int Character::findItemInInv(string itemname)
{
    int sizeItems = (itemsInCharacter.size());
    if (itemsInCharacter.size() < 1) {
        return -1;
        }
    else if (itemsInCharacter.size() > 0) {
        for (int n = 0; n <= sizeItems; n++) {
            // compare inString with short description
            int tempFlag = itemname.compare(itemsInCharacter[n].getShortDescription());
            if (tempFlag == 0) {
                return n;
                break;
            }
            }
        }
    return -1;
}

int Character::getItemAmount() {
    return itemsInCharacter.size();
}

void Character::potionDrank () {
    this->hp = hp + 5;
    if (hp > 10){
        hp = 10;
    }
    itemsInCharacter.erase(itemsInCharacter.begin()+findItemInInv("Potion"));
}
string Character::longDescription()
{
  string ret = this->description;
  ret += "\n Item list:\n";
  for (vector<Item>::iterator i = itemsInCharacter.begin(); i < itemsInCharacter.end(); i++)
    ret += "\t"+ (*i).getShortDescription() + "\n";
  return ret;
}


