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
	int weightGrams;
	float value;
    int weaponCheck;
    int iskeyitem;
    int itemid;
    string image;

public:
	string getShortDescription();
    string getLongDescription();
	int getWeight();
    int getItemID();
    int getKeyID();
	void setWeight(int weightGrams);
	float getValue();
	void setValue(float value);
	int getWeaponCheck();
    void setWeaponCheck(int inweaponCheck);
    int IskeyItem();
    string getimage();
    string Attack(Item item);
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

#endif /*ITEM_H_*/
