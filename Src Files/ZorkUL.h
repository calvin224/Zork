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
    friend class MainWindow;
private:
    Parser parser;
    void createRooms();
    QString processCommand(Command command);
    void printHelp();
    string goRoom(Command command);
    void createItems();
    void displayItems();
    Room *currentRoom;
    void work(QPixmap p);



public:
    QString printWelcome();
    ZorkUL();
   QString play(Command command);
    string go(string direction);
    int getammountofem();
    bool death = false;
    int win;
    int index;
   Enemy getmoninarray(int i);

};

#endif /*ZORKUL_H_*/
