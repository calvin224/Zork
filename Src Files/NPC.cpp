#include "NPC.h"

NPC::NPC(string name,int id, int spokento){
    this->name = name;
    this->id = id;
    this->spokento = spokento;
}

string NPC::getShortDescription(){
    return name;
}
int NPC::getID(){
    return id;
}
int NPC::spokenCheck(){
    return spokento;
}
void NPC::setSpoken(){
   spokento = spokento + 1;
}
