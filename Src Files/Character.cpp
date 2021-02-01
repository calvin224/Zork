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

string Character::longDescription()
{
  string ret = this->description;
  ret += "\n Item list:\n";
  for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
    ret += "\t"+ (*i).getLongDescription() + "\n";
  return ret;
}


