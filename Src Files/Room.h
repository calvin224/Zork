#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "enemy.h"
#include "Door.h"
#include "monsterlist.h"
#include "itemlist.h"

using namespace std;
using std::vector;

class Room {

private:
    Enemy *enemy;
    Door *door;
    string description;
	map<string, Room*> exits;
	string exitString();
    vector <Item> itemsInRoom;
    vector <Item> Items;
    vector <Enemy> EnemyinRoom;
    vector <Enemy> level1mons;
    vector <Door> roomDoors;
public:
    int numberOfItems();
	Room(string description);
	void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
	string longDescription();
	Room* nextRoom(string direction);
    void addItem(Item *inItem);
    void addItems(int N0OfItems);
    string displayItem();
    int isItemInRoom(string inString);
    int addItemFromRoom(string inString);
    void removeItemFromRoom(int location);
    void addenemys(int inlevel,int inammount);
    void addenemy(Enemy inmonster);
    string displayenemy();
    void deadenemy(int index);
    int getenemyhp(int index);
    void enemytakedmg(int damagein , int index);
    void addDoor(Door *inDoor);
    int useKey(int keyid);
    void doorUnlock(int door);
    string getDoorDirection(int door);
    int doorCheck(string inDirection);
    void addweapon();
    int getammoutofenemy();
    Item getItem(int);
    int getdmgout(int index);

};

#endif
