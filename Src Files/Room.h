#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "enemy.h"
#include "Door.h"
#include "NPC.h"
#include "monsterlist.h"
#include "itemlist.h"

using namespace std;
using std::vector;
class Room {
    //friend example
friend class Enemy;
friend class Character;
private:
    int win;
    Enemy *enemy;
    Door *door;
    string description;
    string roomimage;
    string mapimage;
    map<string, Room*> exits;
    string exitString();
    vector <Item> Items;
    vector <Enemy> level1mons;
    vector <Enemy> level2mons;
    vector <Enemy> boss;
    vector <NPC> npcList;
public:
    vector <Enemy> EnemyinRoom;
    vector <Item> itemsInRoom;
    vector <Door> roomDoors;
    int numberOfItems();
    Room(string description, string mapimage, string roomimage);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    string shortDescription();
    string longDescription();
    string getRoomImage();
    string getMapImage();
    Room* nextRoom(string direction);
    void addItem(Item *inItem);
    void addItems(int N0OfItems);
    string displayItem();
    int isItemInRoom(string inString);
    void deleteItem (string inString);
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
    int getNumberofDoors();
    int doorCheck(string inDirection);
    string doorTypeCheck(string inDirection);
    void addNPC(NPC *inNPC);
    string displayNPC();
    int npcCheck(string npcName);
    int getNPCID(int x);
    int getNPCSpoken(int x);
    void setNPCSpoken(int x);
    void addweapon();
    int getammoutofenemy();
    Item getItem(int);
    int getdmgout(int index);
    int getwin();
    Enemy getmoninroom(int ind);

};

#endif
