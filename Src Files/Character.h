#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;

class Item ;

class Character {
private:
    vector < Item > itemsInCharacter;
public:
    string description;
    int hp;
    Character(){
        description = "blah blah";
        hp = 5;
    }
    void addItem(Item item);
public:
	string shortDescription();
	string longDescription();
    void setHealthPoint(int HP);
    int getHealthPoint();
    void death();
};

#endif /*CHARACTER_H_*/
