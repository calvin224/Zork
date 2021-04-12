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
    //copy + call by reference
    Potion(const Potion &potion1){
        this-> description = potion1.description;
        this->iskeyitem = potion1.iskeyitem;
        this->itemid = potion1.itemid;
        this->image = potion1.image;
    }
    friend Item;
};
class BronzeKey: public Item{
public:
    BronzeKey();
    // friend example
    friend Item;
};

class SilverKey: public Item{
public:
    SilverKey();
    friend Item;
};

class GoldKey: public Item{
public:
    GoldKey();
    friend Item;
};

class TNT: public Item{
public:
    TNT();
    friend Item;
};

class Lamp: public Item{
public:
    Lamp();
    friend Item;
};

class EnchanSword : public Item{
public:
    EnchanSword();
    friend Item;
};

#endif /*ITEM_H_*/
