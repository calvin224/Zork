#include "itemlist.h"

itemlist::itemlist()
{
    Sword sword;
    Potion potion1;
    Potion potion2 (potion1);
    Key key;
    EchanSword echantedsword;
    Items.push_back(sword);
    Items.push_back(potion1);
    Items.push_back(potion2);
    Items.push_back(key);
    Items.push_back(echantedsword);
}

vector<Item>itemlist::getitems(){
    return Items;
}
