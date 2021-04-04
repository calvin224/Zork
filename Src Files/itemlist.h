#ifndef ITEMLIST_H
#define ITEMLIST_H
#include "item.h"
#include <vector>
#include <QPixmap>
using namespace std;
using std::vector;

class itemlist
{
protected:
    vector <Item> Items;
public:
    itemlist();
    vector <Item> getitems();
};

#endif // ITEMLIST_H
