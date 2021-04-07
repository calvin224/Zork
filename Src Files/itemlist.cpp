#include "itemlist.h"

itemlist::itemlist()
{
    Sword sword;
    Potion potion;
    Key key;
    EchanSword echantedsword;
    Items.push_back(sword);
    Items.push_back(potion);
    Items.push_back(key);
    Items.push_back(echantedsword);
}

vector<Item>itemlist::getitems(){
    return Items;
}
