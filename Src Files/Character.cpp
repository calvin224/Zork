#include "Character.h"

Character::Character(string description, int HP) {
	this->description = description;
    this->hp = HP;
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


