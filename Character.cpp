#include "Character.h"

Character::Character() {
    this->description = "Main Character";
    this->hp = 10;
    this->dmgout = 2;
}
void Character::setHealthPoint(int HP){
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

int Character::getItemID(int x){
    return itemsInCharacter[x].getItemID();
}

void Character::setcharacterdmgout(int dmg){
     dmgout = dmg;
}
void Character::equipWeapon(int initemid) {
    int itemid = initemid;
    switch(itemid) {
    case 2:
    {
      dmgout = 4;
      break;
    }
    case 3:
    {
      dmgout = 5;
      break;
    }
    case 4:
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
        return false;
        }
    else if (itemsInCharacter.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = itemname.compare( itemsInCharacter[x].getShortDescription());
            if (tempFlag == 0) {
                itemsInCharacter.erase(itemsInCharacter.begin()+x);
                return x;
            }
            x++;
            }
        }
    return -1;
}
void Character::potionDrank () {
    this->hp = hp + 5;
}
string Character::longDescription()
{
  string ret = this->description;
  ret += "\n Item list:\n";
  for (vector<Item>::iterator i = itemsInCharacter.begin(); i < itemsInCharacter.end(); i++)
    ret += "\t"+ (*i).getShortDescription() + "\n";
  return ret;
}


