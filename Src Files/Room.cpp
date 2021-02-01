#include "Room.h"
#include "Command.h"
#include <vector>

Room::Room(string description) {
	this->description = description;; 
    Item *one(new Item("1",2,2,0,0));
    Item *two(new Item("2",2,2,0,0));
    Item *three(new Item("3",2,2,0,0));
    Item *four(new Item("4",2,2,0,0));
    Item *five(new Item("5",2,2,0,0));
    Items.push_back(*one);
    Items.push_back(*two);
    Items.push_back(*three);
    Items.push_back(*four);
    Items.push_back(*five);
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

string Room::shortDescription() {
	return description;
}

string Room::longDescription() {
    return "room = " + description + ".\n" + displayItem() + ".\n" + displayenemy() + ".\n" + exitString();
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
void Room::addItems(int N0OfItems){
    int no = N0OfItems;
    for (int i = 0; i < no; i++) {
        int RandItem = (rand() % 5);
        Item *temp(new Item(Items.at(RandItem)));
        addItem(temp);
    }
}

string Room::displayItem() {
    string tempString = "items in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "no items in room";
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInRoom[x].getShortDescription() + "  " ;
            x++;
            }
        }
    return tempString;
    }

string Room::displayenemy() {
    string tempString = "monsters in room = ";
    int sizemonsters = (EnemyinRoom.size());
    if (EnemyinRoom.size() < 1) {
        tempString = "no monsters in room";
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
void Room::addenemy(string name, int hp){
   Enemy monster = Enemy(name,hp);
    EnemyinRoom.push_back(monster);
}
int Room::getenemyhp(){
    Enemy monster = EnemyinRoom[0];
    return monster.gethp();
}
void Room::enemytakedmg(){
    EnemyinRoom[0].sethp();
}

Item Room::getItem(int x){
    return itemsInRoom[x];
}

void Room::deadenemy(){
  EnemyinRoom.erase(EnemyinRoom.begin()+0);
}
