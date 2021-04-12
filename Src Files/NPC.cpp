#include "NPC.h"
//int list
NPC::NPC(string name, int id, int spokento) : name(name),id(id),spokento(spokento){

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
