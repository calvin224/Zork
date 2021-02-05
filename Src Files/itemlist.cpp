#include "itemlist.h"

itemlist::itemlist()
{
    Item *one(new Item("1",2,2,0,0,0));
    Item *two(new Item("2",2,2,0,0,0));
    Item *three(new Item("3",2,2,0,0,0));
    Item *four(new Item("4",2,2,0,0,0));
    Item *five(new Item("5",2,2,0,0,0));
    items.push_back(*one);
    items.push_back(*two);
    items.push_back(*three);
    items.push_back(*four);
    items.push_back(*five);
}

vector<Item>itemlist::getitems(){
    return items;
}
