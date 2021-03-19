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
#include <string>
#include <functional>
#include <iostream>
#include <optional>
using namespace std;

class ZorkUL {
private:
    Parser parser;
    Room *currentRoom;
    void createRooms();
    QString processCommand(Command command);
    void printHelp();
    string goRoom(Command command);
    void createItems();
    void displayItems();




public:
    QString printWelcome();
    ZorkUL();
   QString play(Command command);
    string go(string direction);
    QString end();
    bool death = false;
    int win;
    int index;
};

#endif /*ZORKUL_H_*/
