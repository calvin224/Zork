/*#include "Character.h"

Character::Character(string description) {
	this->description = description;
}
void Character::addItem(Item &item) {
    itemsInCharacter.push_back(item);
}
void Character::addItem(Item *item) {
    itemsInCharacter.push_back(*item);
    delete item;
}
string Character::longDescription()
{
  string ret = this->description;
  ret += "\n Item list:\n";
  for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
    ret += "\t"+ (*i).getLongDescription() + "\n";
  return ret;
}
*/


