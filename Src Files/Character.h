#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
private:	
public:
    void addItem(Item item);
    Character(string description,int HP);
	string shortDescription();
	string longDescription();
    void setHealthPoint(int HP);
    int getHealthPoint();
    void death();
    string description;
    vector < Item > itemsInCharacter;
    int hp;
};

#endif /*CHARACTER_H_*/
