#include "Room.h"
#include "Command.h"
#include <vector>
#include <ctime>
using namespace std;

Room::Room(string description ) {
    srand((unsigned) time(0));
	this->description = description;; 
    MonsterList *list = new MonsterList();
    level1mons = list->getlevel1mon();
    level2mons = list->getlevel2mon();
    itemli = new itemlist();
    Items = itemli->getitems();
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
	if (north != NULL)
		exits["north"] = north;
	if (east != NULL)
		exits["east"] = east;
	if (south != NULL)
		exits["south"] = south;
	if (west != NULL)
		exits["west"] = west;
}

int Room::getwin(){
    return win;
}

string Room::shortDescription() {
	return description;
}

string Room::longDescription() {
    return "room = " + description + ".\n" + displayItem() + ".\n" + displayenemy() + ".\n" + displayNPC() + ".\n" + exitString();
}

string Room::exitString() {
    string returnString = "\nexits =";
    for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
		// Loop through map
        returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
    return returnString;
}

Room* Room::nextRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
	if (next == exits.end())
		return NULL; // if exits.end() was returned, there's no room in that direction.
	return next->second; // If there is a room, remove the "second" (Room*)
                // part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item *inItem) {
    //cout <<endl;
    //cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(*inItem);
}
void Room::addItems(int itemindex){
        Item *temp(new Item(Items.at(itemindex)));
        addItem(temp);
    }

string Room::displayItem() {
    string tempString = "In the room you see ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "There are no items in the room.";
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            if (x == sizeItems-1 && sizeItems > 1){
            tempString = tempString + "and " + "a " + itemsInRoom[x].getShortDescription() ;
            } else{
            tempString = tempString + + "a " + itemsInRoom[x].getShortDescription() + ", " ;
            x++;
            }
        }
    }
    return tempString;
    }

string Room::displayenemy() {
    string tempString = "Monsters in room = ";
    int sizemonsters = (EnemyinRoom.size());
    if (EnemyinRoom.size() < 1) {
        tempString = "There are no monsters in the room.";
        }
    else if (EnemyinRoom.size() > 0) {
       int x = (0);
        for (int n = sizemonsters; n > 0; n--) {
            tempString = tempString + EnemyinRoom[x].getShortDescription() + "  " ;
            x++;
            }
        }
    return tempString;
    }
int Room::numberOfItems() {
    return itemsInRoom.size();
}
int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }
            x++;
            }
        }
    return -1;
}

void Room::deleteItem(string inString)
{
    int sizeItems = (itemsInRoom.size());
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare(itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
            }
            x++;
            }
}

int Room::addItemFromRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return -1;
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {
                return x;
            }
            x++;
            }
        }
    return -1;
}
Enemy Room::getmoninroom(int index){
    Enemy mon = EnemyinRoom[index];
    return mon;
}
void Room::addenemys(int inlevel,int inammount){
    if(inlevel == 1){ for ( int i = 0; i < inammount; i ++){
            int x = (rand() % level1mons.size());
            Enemy monster =level1mons.at(x);
            addenemy(monster);
        } }
    if(inlevel == 2){ for ( int i = 0; i < inammount; i ++){
           int x = (rand() % level2mons.size());
           Enemy monster =level2mons.at(x);
           addenemy(monster);
       } }
   }
void Room::addenemy(Enemy inmonster){
      Enemy monster = inmonster;
       EnemyinRoom.push_back(monster);
   }
int Room::getdmgout(int index){
    int dmg = EnemyinRoom[index -1].getdmgout();
    return dmg;
}

int Room::getenemyhp(int index){
    Enemy monster = EnemyinRoom[index-1];
    return monster.gethp();
}
void Room::enemytakedmg(int damagein , int index){
 if (EnemyinRoom[index-1].gethp() != 0 && getammoutofenemy() != 0 ){
    EnemyinRoom[index-1].sethp(damagein);}
 }

void Room::deadenemy(int index){
  EnemyinRoom.erase(EnemyinRoom.begin()+index-1);
}
int Room::getammoutofenemy(){
    return EnemyinRoom.size();
}

void Room::addDoor(Door *inDoor) {
    roomDoors.push_back(*inDoor);
}

int Room::useKey (int keyid){
    int numDoors = (roomDoors.size());
    for (int x = 0; x <= numDoors; x++){
        if (keyid == roomDoors[x].getId()){
            return x;
            break;
        }
    }
   return -1;
}

void Room::doorUnlock(int door){
    roomDoors[door].setUnlocked();
}

int Room::doorCheck(string inDirection){
    int numDoors = (roomDoors.size());
    if (roomDoors.size() < 1) {
        return -1;
        }
    else if (roomDoors.size() > 0) {
       int x = (0);
        for (int n = numDoors; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inDirection.compare(roomDoors[x].getDirection());
            if (tempFlag == 0 && roomDoors[x].lockedCheck() == 1) {
                    return x;
            }
            x++;
            }
        }
    return -1;
}

void Room::addNPC(NPC *inNPC) {
    npcList.push_back(*inNPC);
}

string Room::displayNPC() {
    string tempString = "People in room = ";
    int numNPC = (npcList.size());
    if (npcList.size() < 1) {
        tempString = "There is nobody in the room.";
        }
    else if (npcList.size() > 0) {
       int x = (0);
        for (int n = numNPC; n > 0; n--) {
            tempString = tempString + npcList[x].getShortDescription() + "  " ;
            x++;
            }
        }
    return tempString;
    }

int Room::npcCheck(string npcName){
    int numNPC = (npcList.size());
    if (npcList.size() < 1) {
        return -1;
        }
    else if (npcList.size() > 0) {
       int x = (0);
        for (int n = numNPC; n > 0; n--) {
            // compare inString with short description
            int tempFlag = npcName.compare(npcList[x].getShortDescription());
            if (tempFlag == 0 && roomDoors[x].lockedCheck() == 1) {
                    return x;
            }
            x++;
            }
        }
    return -1;
}

int Room::getNPCID(int x){
    return npcList[x].getID();
}

int Room::getNPCSpoken(int x){
    return npcList[x].spokenCheck();
}

void Room::setNPCSpoken(int x){
    npcList[x].setSpoken();
}

string Room::getDoorDirection(int door){
    return roomDoors[door].getDirection();
}

int Room::getNumberofDoors(){
    return roomDoors.size();
}

Item Room::getItem(int x){
    return itemsInRoom[x];
}
