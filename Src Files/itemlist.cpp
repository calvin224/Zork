#include "itemlist.h"

itemlist::itemlist()
{
    Item *one(new Item("key", 2, 2,0,1,3,":/Images/key.png"));
    Item *two(new Item("sword", 5, 15,2,0,2,":/Images/sword.png"));
    Item *three(new Item("3",2,2,0,0,0,"aa"));
    Item *four(new Item("4",2,2,0,0,0,"aa"));
    Item *five(new Item("5",2,2,0,0,0,"aa"));
    Items.push_back(*one);
    Items.push_back(*two);
    Items.push_back(*three);
    Items.push_back(*four);
    Items.push_back(*five);
}

vector<Item>itemlist::getitems(){
    return Items;
}
