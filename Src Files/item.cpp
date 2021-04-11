#include "item.h"
Sword::Sword(){
   this-> description = "Sword";
    this->weapondmg = 1;
    this->iskeyitem = 0;
    this->itemid = 2;
    this->image = ":/Images/sword.png";
}
BronzeKey::BronzeKey(){
    this-> description = "Bronze Key";
    this->iskeyitem = 1;
    this->itemid = 3;
    this->image = ":/Images/bronzekey.png";
}

SilverKey::SilverKey(){
    this-> description = "Silver Key";
    this->iskeyitem = 2;
    this->itemid = 3;
    this->image = ":/Images/silverkey.png";
}

GoldKey::GoldKey(){
    this-> description = "Gold Key";
    this->iskeyitem = 3;
    this->itemid = 3;
    this->image = ":/Images/goldkey.png";
}

Potion::Potion(){
    this-> description = "Potion";
    this->iskeyitem = 0;
    this->itemid = 1;
    this->image = ":/Images/potion.png";
}

EnchanSword::EnchanSword(){
     this-> description = "Enchanted Sword";
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
