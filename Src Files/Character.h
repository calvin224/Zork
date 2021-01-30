#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
private:
	string description;
    vector < Item > itemsInCharacter;
    int hp;
public:
    void addItem(Item item);
public:
    Character(string description,int HP);
	string shortDescription();
	string longDescription();
    void setHealthPoint(int HP);
    int getHealthPoint();
    void death();
};

#endif /*CHARACTER_H_*/
