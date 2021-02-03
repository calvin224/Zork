#ifndef ITEMLIST_H
#define ITEMLIST_H
#include "item.h"
#include <vector>
using namespace std;
using std::vector;

class itemlist
{
protected:
    vector <Item> items;
public:
    itemlist();
    vector <Item> getitems();
};

#endif // ITEMLIST_H
