#include <iostream>
#include "mainwindow.h"
#include <QApplication>
#include "ZorkUL.h"
#include <string>
#include <functional>
#include <optional>

using namespace std;
Character *mainchar;
string wincon;
int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
//starter functions;
ZorkUL::ZorkUL() {
    createRooms();
}

void ZorkUL::createRooms()  {
    mainchar = new Character();
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i ,*m;
    a = new Room("castle");
   // Item* potion1 = (new Item("potion", 1, 11,0,0,1,":/Images/potion.png"));
    //Item* potion2 = potion1;
     //   a->addItem(potion1);
      //  int random = rand() % 2;
      //  if (random == 1) {
     //       a->addItem(potion2);
       // }
        a->addItems(1);
        a->addItems(0);
        a->addItems(2);
        a->addDoor(new Door(1, 1, "east"));
        a->addenemys(1,1);
        a->addNPC(new NPC("TestNPC", 5, 1, 1, 1, 0));
    b = new Room("Creepy Woods");
       // b->addItem(new Item("KEYITEM", 2, 2,0,1,0,":/Images/key.png"));
    c = new Room("c");
    d = new Room("d");
        d->addDoor(new Door(1, 4, "west"));
    e = new Room("e");
    f = new Room("f");
    g = new Room("g");
    h = new Room("h");
    i = new Room("i");
    m = new Room("end zone");


//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(m, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);

        currentRoom = a;
}

/**
 *  Main play routine.  Loops until end of play.
 */
QString ZorkUL::play(Command commandin) {
    QString test2;
    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.
    if(mainchar->hp >0){
    bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        Command command = commandin;
        // Pass dereferenced command and check for end of game.
      test2 = processCommand(command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
     finished = true;
    }}
    else(test2 = "You died!");
    return(test2);
 }



Enemy ZorkUL::getmoninarray(int i){
    return currentRoom->EnemyinRoom[i];
}

Item ZorkUL::getIteminList(int i){
    return currentRoom->itemsInRoom[i];
}

QString ZorkUL::printWelcome() {
    string str = "You start your journey!\n"  + currentRoom->longDescription() ;
    QString qstr = QString::fromStdString(str);
    return qstr;

}
int ZorkUL::getammountofem(){
   return currentRoom->getammoutofenemy();
}

int ZorkUL::getAmountofItems(){
   return currentRoom->numberOfItems();
}

/*
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
 QString ZorkUL::processCommand(Command command){
    string test;
    if(win > 0){
       if(win == 1){
           test = test +"You saved the kingdom while keeping your sanity and life!" ;
       }
    }
    if (command.isUnknown()) {
        test = test +"invalid input";

    }
    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        printHelp();

    else if (commandWord.compare("map") == 0)
        {
        test = test +"[h] --- [f] --- [g]" ;
        test = test +"         |         " ;
        test = test +"         |         " ;
        test = test +"[c] --- [a] --- [b]" ;
        test = test +"         |         " ;
        test = test +"         |         " ;
        test = test +"[i] --- [d] --- [e]" ;
        }

    else if (commandWord.compare("go") == 0)
       test = test + goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
      test = take(command);
    }
    else if (commandWord.compare("put") == 0)
    {
       test = test +"you put a item down" ;
    }

    else if (commandWord.compare("use") == 0)
    {
      test = use(command);
    }

    else if (commandWord.compare("inventory") == 0)
        {
            test = test +mainchar->longDescription() ;
        }

    else if (commandWord.compare("talk") == 0)
    {
       test = Talk(command);
    }
    else if (commandWord.compare("attack") == 0){
       test = CombatCalc(command);
        }
        else if(commandWord.compare("start")==0){
            printWelcome();
        }

    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            test = test +"overdefined input";
    }

     QString qstr = QString::fromStdString(test);
     return qstr;
}

 string ZorkUL::use(Command command){
     string test;
     if (mainchar->findItemInInv(command.getSecondWord()) != -1) {
     string tempdirection;
     int itemid = mainchar -> getItemID(mainchar -> findItemInInv(command.getSecondWord()));
       switch(itemid) {
       case 1 :
         test = test +"You drink the potion." ;
             mainchar->potionDrank();
         test = test +"Your new health points are: " + to_string(mainchar->getHealthPoint()) ;
         break;
       case 2 :
         test = test +"You equip the " + mainchar -> getItemName(mainchar -> findItemInInv(command.getSecondWord())) + "." ;
             mainchar->equipWeapon(mainchar -> getItemDmg(mainchar -> findItemInInv(command.getSecondWord())));
         test = test +"Your new attack points are: " + to_string(mainchar->getDamageOut()) ;
         break;
       case 3 :
         test = test +"You use the key." ;
         if (currentRoom->getNumberofDoors() > 0){
             if ((currentRoom->useKey(mainchar -> getKeyID(mainchar -> findItemInInv(command.getSecondWord())))) >= 0) {
                 currentRoom->doorUnlock(currentRoom->useKey(mainchar -> getKeyID(mainchar -> findItemInInv(command.getSecondWord()))));
                 tempdirection = currentRoom->getDoorDirection(currentRoom->useKey(mainchar -> getKeyID(mainchar -> findItemInInv(command.getSecondWord()))));
                 test = test +"You unlocked the door to the " + tempdirection ;
                 break;
             } else {
                 test = test +"This key cannot be used here!" ;
                 break;
             }
         } else {
             test = test +"This key cannot be used here!" ;
             break;
         }

         break;
        case 4 :
         test = test +"test" ;
         break;
        case 5 :
         test = test +"test" ;
         break;
        default :
         test = test +"Invalid item!" ;
            }
         } else  {
         test = test +"Invalid item!" ;
     }
      return test;
     }

 string ZorkUL::take(Command command){
     string test;
     if (currentRoom->getammoutofenemy() != 0){

         test = test +"\nCan't take, there are monsters in the way!\n" ;
         test = test +currentRoom->longDescription() ;

     } else if  (currentRoom->getammoutofenemy() == 0){

        if (!command.hasSecondWord()) {
        test = test +"incomplete input";
        }
        else if (command.hasSecondWord()) {

        test = test +"you're trying to take " + command.getSecondWord() ;
        int location = currentRoom->addItemFromRoom(command.getSecondWord());
        if (location  < 0 ) {
            test = test +"item is not in room" ;
        }
        else {
            Item newItem = currentRoom -> getItem(currentRoom -> addItemFromRoom(command.getSecondWord()));
            mainchar->addItem(newItem);
            test = test + "item is in room" ;
            test = test + "index number " + to_string(location) ;
            currentRoom->deleteItem(command.getSecondWord());
            test = test +currentRoom->longDescription() ;
          }
         }
     }
     return test;
 }



string ZorkUL::Talk(Command command){
    string test;
    itemlist itemli = *new itemlist();
    vector<Item> Items = itemli.getitems();
    if (!command.hasSecondWord()) {
    test = test +"incomplete input";
    }

    if (currentRoom->npcCheck(command.getSecondWord()) >= 0) {
        test = test +"You talk to " + command.getSecondWord() ;
        int npcID = currentRoom -> getNPCID(currentRoom -> npcCheck(command.getSecondWord()));
          switch(npcID) {
          case 1 :
              if (currentRoom->getNPCSpoken(currentRoom->npcCheck(command.getSecondWord())) == 0) {
            test = test +"\"Test phrase\"" ;
                mainchar->addItem(Items.at(2));
            test = test +"The man gives you a testkey" ;
            currentRoom->setNPCSpoken(currentRoom->npcCheck(command.getSecondWord()));
              } else if (currentRoom->getNPCSpoken(currentRoom->npcCheck(command.getSecondWord())) < 10) {
            test = test +"\"Go away\"" ;
            currentRoom->setNPCSpoken(currentRoom->npcCheck(command.getSecondWord()));
              } else if (currentRoom->getNPCSpoken(currentRoom->npcCheck(command.getSecondWord())) == 10) {
                  test = test +"\"Fine, take this. But leave me alone now!\"" ;
                mainchar->addNPCItem(Items.at(4));
                  test = test +"The man gives you a sword, engraved with runes" ;
                    } else if (currentRoom->getNPCSpoken(currentRoom->npcCheck(command.getSecondWord())) > 10) {
                        test = test +"\"Go away\"" ;
                    }
            break;
          case 2 :
            test = test +"test" ;
            break;
          }
    } else {
        test = test +"That person is not in the room!" ;
    }
    return test;
}


string ZorkUL::CombatCalc(Command command){
    string test;
    try {

     if (currentRoom->getammoutofenemy() == 0){
           throw 0;
     }
    else if (!command.hasSecondWord() ||  std::stoi(command.getSecondWord()) > currentRoom->getammoutofenemy() || std::stoi(command.getSecondWord()) < 1) {
        throw 1;
      }
    else if (currentRoom->getammoutofenemy() != 0) {
         index = std::stoi(command.getSecondWord());
         currentRoom->enemytakedmg(mainchar->getDamageOut(), index);
       if ((currentRoom->getenemyhp(index)) > 0){
         index = std::stoi(command.getSecondWord());
         Enemy mon = currentRoom->getmoninroom(index-1);
         int x = (rand() % 100);
         test = test +mon.getShortDescription() + " not dead!";
         test = test+ "\nMonster hp = " + to_string(currentRoom->getenemyhp(index));
         test = test + "\nDamage given: " + to_string(mainchar->dmgout);
         //Combat caculation
         for(int i = 0;i < currentRoom->getammoutofenemy();i++){
             Enemy temp = currentRoom->getmoninroom(i);
         if(x < temp.getaccuracy()){
         test = test + "\nDamage taken from:" + temp.getShortDescription() + ":" + to_string(temp.getdmgout()) ;
         int hp = mainchar->hp - temp.getdmgout();
         // call by reference passing address of hp into the func (func(&
         mainchar->setHealthPoint(hp);}
         else {
         test = test + "\nDamage taken from:" + temp.getShortDescription() + ":" + "Missed!" ; } }
         test = test + "\nYour hp = " + to_string(mainchar->hp) ;
         if(mainchar->hp <= 0 ){
             return "You died!";
             mainchar->~Character();
         }
         }
      else if  ( currentRoom->getenemyhp(index) <= 0) {
      index = std::stoi(command.getSecondWord());
      currentRoom->deadenemy(index);
      test = test +"\nMonster dead!" ;
      test = test +"\nYour hp = "+ to_string(mainchar->hp) ;
      if (currentRoom->getammoutofenemy() == 0) {
          test = test +currentRoom->longDescription() ;
      }
       } }
     return test;
    }  catch (int errorid) {
        switch(errorid){
        case 0:{
            return "There are no monsters in the room!";
        }
        case 1: {
            return "Please enter a monster to attack!";
        }
        case 99:{
        }
            MyException z;
            exception& e = z;
            return e.what();//fatal error
        }

    throw 99;
} }
/** COMMANDS **/
void ZorkUL::printHelp() {
}

string ZorkUL::goRoom(Command command) {
    string str;
    if (!command.hasSecondWord()) {
        str = str +"incomplete input";

    }

    if (currentRoom->doorCheck(command.getSecondWord()) >= 0) {
        str = str + "This door is locked!\n" ;
    } else if (currentRoom->doorCheck(command.getSecondWord()) < 0) {

    if (currentRoom->getammoutofenemy() != 0){
        str = str +"Can't go, there are monsters in the way!\n" ;
        str = str  +currentRoom->longDescription() ;
    } else if  (currentRoom->getammoutofenemy() == 0){

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        str = str +"underdefined input";
    else {
        currentRoom = nextRoom;
        if(currentRoom->shortDescription().compare("end zone")==0){
            win = 1;
            str = str +"You saved the kingdom while keeping your sanity and life!" ;
        }
        else
        str = str +currentRoom->longDescription() ;
    }
      }

}
    string qstr = str;
    return qstr;
}


