#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
private:
	string description;
	string longDescription;
	int weightGrams;
	float value;
    int weaponCheck;
    int iskeyitem;
    int itemid;

public:
    Item (string inDescription, int inWeightGrams, float inValue, int inweaponCheck, int inkeyitem, int initemid);
    Item(const Item &item1);
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
    string Attack(Item item);
};

#endif /*ITEM_H_*/
