#include "item.h"
Sword::Sword(){
   this-> description = "inDescription";
   this-> setWeight(1);
    this->value =1;
    this->setWeaponCheck(1);
    this->iskeyitem = 0;
    this->itemid = 0;
    this->image = "temp";
}
Key::Key(){
   this-> description = "inDescription";
   this-> setWeight(1);
    this->value =1;
    this->setWeaponCheck(1);
    this->iskeyitem = 0;
    this->itemid = 0;
    this->image = "temp";
}
Potion::Potion(){
   this-> description = "inDescription";
   this-> setWeight(1);
    this->value =1;
    this->setWeaponCheck(1);
    this->iskeyitem = 0;
    this->itemid = 0;
    this->image = "temp";
}

void Item::setWeight(int inWeightGrams)
{
    if (inWeightGrams > 9999 || inWeightGrams < 0)
        cout << "weight invalid, must be 0<weight<9999" ;
     else
        weightGrams = inWeightGrams;
 }
void Item::setValue(float inValue)
{
    if (inValue > 9999 || inValue < 0)
       cout << "value invalid, must be 0<value<9999" ;
    else
	   value = inValue;
}
void Item::setWeaponCheck(int inweaponCheck){
    weaponCheck = inweaponCheck;
}
int Item::getWeaponCheck(){
    return weaponCheck;
}
int Item::getWeight(){
    return weightGrams;
}
int Item::getItemID(){
    return itemid;
}
int Item::getKeyID(){
    return iskeyitem;
}
string Item::getShortDescription()
{
	return description;
}
string Item::getLongDescription()
{
	return " item(s), " + description + ".\n";
}
// 0 = not key item plan is 1-etc indicate a certain key item and when  used on something checks if the required int for key item = int it wants (if iskeyitem = 2 open door etc);
int Item::IskeyItem(){
    return iskeyitem;
}

string Item::getimage()
{
        return image;
}
