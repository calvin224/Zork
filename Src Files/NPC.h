#ifndef NPC_H
#define NPC_H
#include "item.h"
#include <string>
using namespace std;
#include <vector>
using std::vector;

class NPC
{
    //protected
protected:
    string name;
    vector <Item> npcInventory;
    int id;
    int spokento;
public:
    NPC(string name,int id, int spokento);
    string getShortDescription();
    int getID();
    int spokenCheck();
    void setSpoken();
};

#endif /*NPC_H_*/
