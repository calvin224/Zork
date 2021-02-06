#ifndef NPC_H
#define NPC_H
#include "item.h"
#include <string>
using namespace std;
#include <vector>
using std::vector;

class NPC
{
private:
protected:
    string name;
    int hp;
    int dmgout;
    vector <Item> npcInventory;
    bool essential;
    int id;
    int spokento;
public:
    NPC(string name,int hp,int dmgout,bool essential, int id, int spokento);
    string getShortDescription();
    int gethp();
    int getID();
    void sethp(int damage);
    int getdmgout();
    bool essentialCheck();
    int spokenCheck();
    void setSpoken();
};

#endif /*NPC_H_*/
