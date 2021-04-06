#include "item.h"
Sword::Sword(){
   this-> description = "Sword";
   this-> setWeight(1);
    this->value =1;
    this->setWeaponCheck(2);
    this->iskeyitem = 0;
    this->itemid = 0;
    this->image = ":/Images/sword.png";
}
Key::Key(){
   this-> description = "Key";
   this-> setWeight(1);
    this->value =1;
    this->setWeaponCheck(0);
    this->iskeyitem = 0;
    this->itemid = 0;
    this->image = ":/Images/key.png";
}
Potion::Potion(){
   this-> description = "Potion";
   this-> setWeight(1);
    this->value =1;
    this->setWeaponCheck(0);
    this->iskeyitem = 0;
    this->itemid = 0;
    this->image = ":/Images/potion.png";
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
