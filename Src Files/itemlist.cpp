#include "itemlist.h"

itemlist::itemlist()
{
    Sword sword;
    Items.push_back(sword);
}

vector<Item>itemlist::getitems(){
    return Items;
}
