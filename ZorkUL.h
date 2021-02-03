#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "enemy.h"
#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
    Parser parser;
    Room *currentRoom;
    void createRooms();
    void printWelcome();
    bool processCommand(Command command);
    void printHelp();
    void goRoom(Command command);
    void createItems();
    void displayItems();




public:
    ZorkUL();
    void play();
    string go(string direction);
    void end();
    bool death = false;
    bool win = false;
    int index;
};

#endif /*ZORKUL_H_*/