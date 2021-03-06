//Advanced pre-processor - Zorkul.h   directives
//header files (inclusion guards)
#ifndef ZORKUL_H_
#define ZORKUL_H_
#define ERROR "Fatal"
//Basic pre-processor directives
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
    //private
private:
    Parser parser;
    void createRooms();
    QString processCommand(Command command);
    string goRoom(Command command);
    void createItems();
    void displayItems();
    Room *currentRoom;
    void work(QPixmap p);
    string CombatCalc(Command command);
    string Talk(Command command);
    string use(Command command);
    string take(Command command);
    //public
public:
    QString printWelcome();
    ZorkUL();
    QString play(Command command);
    string go(string direction);
    int getammountofem();
    int getAmountofItems();
    int getAmountofInvItems();
    bool death = false;
    int win;
    int index;
    Item getIteminList(int i);
    Item getIteminInventory(int i);
    Enemy getmoninarray(int i);

};
//Programmer defined exceptions
class MyException : public exception{
    public:
        const char * what() const throw()
        {
            return ERROR;
        }
};
#endif /*ZORKUL_H_*/
