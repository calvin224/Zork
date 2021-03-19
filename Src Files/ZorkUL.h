#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "enemy.h"
#include "NPC.h"
#include "Door.h"
#include "Character.h"
#include <iostream>
#include <string>
#include "mainwindow.h"
#include <QApplication>
using namespace std;

class ZorkUL {
private:
    Parser parser;
    Room *currentRoom;
    void createRooms();
    bool processCommand(Command command);
    void printHelp();
    void goRoom(Command command);
    void createItems();
    void displayItems();




public:
    QString printWelcome();
    ZorkUL();
    QString play();
    string go(string direction);
    void end();
    bool death = false;
    int win;
    int index;
};

#endif /*ZORKUL_H_*/
