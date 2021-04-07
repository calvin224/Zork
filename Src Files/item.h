#ifndef ITEM_H_
#define ITEM_H_
#include <QPixmap>
#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
protected:
	string description;
	string longDescription;
    int weapondmg;
    int iskeyitem;
    int itemid;
    string image;

public:
	string getShortDescription();
    string getLongDescription();
	int getWeight();
    int getItemID();
    int getKeyID();
	int getWeaponCheck();
    void setWeaponCheck(int inweaponCheck);
    int IskeyItem();
    string getimage();
};
class Sword: public Item{
public:
    Sword();
    friend Item;
};
class Potion: public Item{
public:
    Potion();
    friend Item;
};
class Key: public Item{
public:
    Key();
    friend Item;
};
class EchanSword : public Item{
public:
    EchanSword();
    friend Item;
};

#endif /*ITEM_H_*/
