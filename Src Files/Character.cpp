#include "Character.h"

Character::Character() {
    this->description = "Main Character";
    this->hp = 10;
}
void Character::setHealthPoint(int HP){
   this->hp = HP;
}
int Character::getHealthPoint(){
    return hp;
}

void Character::addItem(Item item) {
    itemsInCharacter.push_back(item);
}

string Character::inventoryList()
{
    string inv = "Item List:";
    for (int i=0; i > (int)itemsInCharacter.size(); i++){
        inv = inv + " " + itemsInCharacter[i].getShortDescription();
    }
    return inv;
}

string Character::longDescription()
{
  string ret = this->description;
  ret += "\n Item list:\n";
  for (vector<Item>::iterator i = itemsInCharacter.begin(); i < itemsInCharacter.end(); i++)
    ret += "\t"+ (*i).getShortDescription() + "\n";
  return ret;
}


