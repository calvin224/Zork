#include "itemlist.h"

itemlist::itemlist()
{
    Sword sword;
    Potion potion;
    Key key;
    Items.push_back(sword);
    Items.push_back(potion);
    Items.push_back(key);
}

vector<Item>itemlist::getitems(){
    return Items;
}
