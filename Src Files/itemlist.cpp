#include "itemlist.h"

itemlist::itemlist()
{
    Sword sword;
    Potion potion1;
    Potion potion2 (potion1);
    BronzeKey bronzekey;
    SilverKey silverkey;
    GoldKey goldkey;
    EnchanSword enchantedsword;
    TNT tnt;
    Lamp lamp;
    Items.push_back(sword);
    Items.push_back(potion1);
    Items.push_back(potion2);
    Items.push_back(bronzekey);
    Items.push_back(silverkey);
    Items.push_back(goldkey);
    Items.push_back(enchantedsword);
    Items.push_back(tnt);
    Items.push_back(lamp);
}

vector<Item>itemlist::getitems(){
    return Items;
}
