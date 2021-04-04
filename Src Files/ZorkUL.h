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
#include <exception>
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
    string CombatCalc(Command command);
    string Talk(Command command);
    string use(Command command);
    string take(Command command);


public:
    QString printWelcome();
    ZorkUL();
    QString play(Command command);
    string go(string direction);
    int getammountofem();
    int getAmountofItems();
    bool death = false;
    int win;
    int index;
    Item getIteminList(int i);
    Enemy getmoninarray(int i);

};
class MyException : public exception{
    public:
        const char * what() const throw()
        {
            return "fatal";
        }
};

#endif /*ZORKUL_H_*/
