#include "NPC.h"

NPC::NPC(string name, int hp, int dmgout, bool essential, int id, int spokento){
    this->name = name;
    this->hp = hp;
    this->dmgout = dmgout;
    this->essential = essential;
    this->id = id;
    this->spokento = spokento;
}

string NPC::getShortDescription(){
    return name;
}
int NPC::gethp(){
    return hp;
}
int NPC::getID(){
    return id;
}
void NPC::sethp(int damage){
   hp = hp - damage;
}
int NPC::getdmgout(){
    return dmgout;
}
bool NPC::essentialCheck(){
    return essential;
}
int NPC::spokenCheck(){
    return spokento;
}
void NPC::setSpoken(){
   spokento = spokento + 1;
}
