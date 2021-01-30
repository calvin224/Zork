#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "enemy.h"
using namespace std;
using std::vector;

class Room {

private:
    Enemy *enemy;
	string description;
	map<string, Room*> exits;
	string exitString();
    vector <Item> itemsInRoom;
    vector <Item> Items;
    vector <Enemy> EnemyinRoom;



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
    void removeItemFromRoom(int location);
    void addenemy(string name, int hp);
    string displayenemy();
};

#endif
