#include "item.h"
Item::Item (string inDescription, int inWeightGrams, float inValue, int inweaponCheck, int inkeyitem, int initemid, string inimage) {
    description = inDescription;
    setWeight(inWeightGrams);
    value = inValue;
    setWeaponCheck(inweaponCheck);
    iskeyitem = inkeyitem;
    itemid = initemid;
    image = inimage;
}
 //pass by reference
Item::Item(const Item &item1) {
    description = item1.description;
    weightGrams = item1.weightGrams;
    value = item1.value;
    weaponCheck = item1.weaponCheck;
    iskeyitem = item1.iskeyitem;
    itemid = item1.itemid;
};

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

string Item::getimage(){
        return image;
}

Sword::Sword(){
    this->description = "Sword";
    this->weightGrams = 20;
    this->value = 20;
    this->weaponCheck = 1 ;
    this->iskeyitem = 1;
    this->itemid = 1;
    this->image = ":/Images/sword.png";
}
