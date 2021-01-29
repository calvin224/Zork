#include "item.h"

Item::Item (string inDescription, int inWeightGrams, float inValue, int inweaponCheck, int inkeyitem) {
	description = inDescription;
	setWeight(inWeightGrams);
	value = inValue;
    setWeaponCheck(inweaponCheck);
    iskeyitem = inkeyitem;
}

Item::Item(string inDescription) {
	description = inDescription;
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
