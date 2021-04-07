#include "item.h"
Sword::Sword(){
   this-> description = "Sword";
    this->weapondmg = 1;
    this->iskeyitem = 0;
    this->itemid = 2;
    this->image = ":/Images/sword.png";
}
Key::Key(){
    this-> description = "Key";
    this->iskeyitem = 1;
    this->itemid = 3;
    this->image = ":/Images/key.png";
}
Potion::Potion(){
    this-> description = "Potion";
    this->iskeyitem = 0;
    this->itemid = 1;
    this->image = ":/Images/potion.png";
}

EchanSword::EchanSword(){
     this-> description = "Echanted Sword";
     this->weapondmg = 3;
     this->iskeyitem = 0;
     this->itemid = 0;
     this->image = "";
}

int Item::getWeaponCheck(){
    return weapondmg;
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
