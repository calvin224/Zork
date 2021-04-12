#include <iostream>
#include "mainwindow.h"
#include <QApplication>
#include "ZorkUL.h"
#include <string>
#include <functional>
#include <optional>
namespace start {

int Start(int argc, char* argv[]){
     QApplication a(argc, argv);
     MainWindow w;
     w.show();
     return a.exec();
}

}

Character *mainchar;
string wincon;
int main(int argc, char* argv[]) {
    using namespace start;
   return start::Start(argc,argv);
}

//starter functions;
ZorkUL::ZorkUL() {
    createRooms();
}

void ZorkUL::createRooms()  {
    mainchar = new Character();
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i ,*m;
    a = new Room("Main Hallway", ":/Images/mapRoomA.png", ":/Images/zorkuiRoomA.png");
        a->addNPC(new NPC("Old Man", 1, 0));
    b = new Room("Bronze Key Room", ":/Images/mapRoomB.png", ":/Images/zorkuiRoomB.png");
        b->addenemys(1,1);
        b->addItems(3);
    c = new Room("Potion Room", ":/Images/mapRoomC.png", ":/Images/zorkuiRoomC.png");
        c->addenemys(1,1);
        c->addItems(1);
        int random = (rand() % 2 + 1);
        if (random == 1){
        c->addItems(2);
    }
    d = new Room("South Hallway", ":/Images/mapRoomD.png", ":/Images/zorkuiRoomD.png");
        d->addDoor(new Door(1, 4, "west", "Blockage"));
        d->addenemys(1,1);
        d->addItems(7);
    e = new Room("Silver Key Room", ":/Images/mapRoomE.png", ":/Images/zorkuiRoomE.png");
        e->addItems(4);
        e->addenemys(1,1);
    f = new Room("North Hallway", ":/Images/mapRoomF.png", ":/Images/zorkuiRoomF.png");
        f->addDoor(new Door(1, 1, "north", "Door"));
        f->addDoor(new Door(1, 2, "north", "Door"));
        f->addDoor(new Door(1, 3, "north", "Door"));
    g = new Room("Sword Room", ":/Images/mapRoomG.png", ":/Images/zorkuiRoomG.png");
        g->addItems(0);
        g->addenemys(1,1);
    h = new Room("Gold Key Room", ":/Images/mapRoomH.png", ":/Images/zorkuiRoomH.png");
        h->addItems(5);
        h->addenemys(1,1);
    i = new Room("Hidden Shrine", ":/Images/mapRoomI.png", ":/Images/zorkuiRoomI.png");
        i->addItems(6);
    m = new Room("Boss Room", ":/Images/mapRoomM.png", ":/Images/zorkuiRoomM.png");


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

Item ZorkUL::getIteminInventory(int i){
    return mainchar->itemsInCharacter[i];
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

int ZorkUL::getAmountofInvItems(){
   return mainchar->getItemAmount();
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
        test = test +"\nInvalid input";

    }
    string commandWord = command.getCommandWord();

    if (commandWord.compare("go") == 0)
       test = test + goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
      test = take(command);
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
            test = test +"\nOverdefined input";
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
         test = test +"\nYou drink the potion." ;
             mainchar->potionDrank();
         test = test +"\nYour new health points are: " + to_string(mainchar->getHealthPoint()) ;
         test = test + "\n" + currentRoom->longDescription() ;
         break;
       case 2 :
         test = test +"\nYou equip the " + mainchar -> getItemName(mainchar -> findItemInInv(command.getSecondWord())) + "." ;
             mainchar->equipWeapon(mainchar -> getItemDmg(mainchar -> findItemInInv(command.getSecondWord())));
         test = test +"\nYour new attack points are: " + to_string(mainchar->getDamageOut()) ;
         test = test + "\n" + currentRoom->longDescription() ;
         break;
       case 3 :
         test = test +"\nYou use the key." ;
         if (currentRoom->getNumberofDoors() > 0){
             if ((currentRoom->useKey(mainchar -> getKeyID(mainchar -> findItemInInv(command.getSecondWord())))) >= 0) {
                 currentRoom->doorUnlock(currentRoom->useKey(mainchar -> getKeyID(mainchar -> findItemInInv(command.getSecondWord()))));
                 tempdirection = currentRoom->getDoorDirection(currentRoom->useKey(mainchar -> getKeyID(mainchar -> findItemInInv(command.getSecondWord()))));
                 if (currentRoom->doorTypeCheck(tempdirection) == "Door"){
                 test = test +"\nYou unlocked the door to the " + tempdirection ;
                 test = test + "\n" + currentRoom->longDescription() ;
                 break;
                 } else if (currentRoom->doorTypeCheck(tempdirection) == "Blockage"){
                 test = test +"\nYou unblocked the passage to the " + tempdirection ;
                 test = test + "\n" + currentRoom->longDescription() ;
                 mainchar->usedItem(command.getSecondWord());
                 break;
                 }
             }
             else {
                 test = test +"\nThis key cannot be used here!" ;
                 test = test + "\n" + currentRoom->longDescription() ;
                 break;
             }
         } else {
             test = test +"\nThis key cannot be used here!" ;
             test = test + "\n" + currentRoom->longDescription() ;
             break;
         }

         break;

        default :
         test = test +"\nInvalid item!" ;
            }
         } else  {
         test = test +"\nInvalid item!" ;
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
        test = test +"\nIncomplete input";
        }
        else if (command.hasSecondWord()) {

        test = test +"\nYou're trying to take " + command.getSecondWord() ;
        int location = currentRoom->addItemFromRoom(command.getSecondWord());
        if (location  < 0 ) {
            test = test +"\nItem is not in room" ;
            test = test + "\n" + currentRoom->longDescription() ;
        }
        else {
            Item newItem = currentRoom -> getItem(currentRoom -> addItemFromRoom(command.getSecondWord()));
            mainchar->addItem(newItem);
            test = test + "\nItem is in room" ;
            test = test + "\nIndex number " + to_string(location) ;
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
     test = test +"\nIncomplete input";
     }

     if (currentRoom->npcCheck(command.getSecondWord()) >= 0) {
         test = test +"You talk to " + command.getSecondWord() ;
         int npcID = currentRoom -> getNPCID(currentRoom -> npcCheck(command.getSecondWord()));
           switch(npcID) {
           case 1 :
               if (currentRoom->getNPCSpoken(currentRoom->npcCheck(command.getSecondWord())) == 0) {
             test = test +"\n\"Greetings adventurer, I don't know who you are or how you've arrived here, but we need your help! An evil monster lurks within this cave, and all who have tried to defeat him have failed. I wish I could give you something to aid you in this quest, but alas I am a poor hermit with not much to offer.\"" ;
             currentRoom->setNPCSpoken(currentRoom->npcCheck(command.getSecondWord()));
               } else if (currentRoom->getNPCSpoken(currentRoom->npcCheck(command.getSecondWord())) < 10) {
             test = test +"\n\"Why are you still talking to me? The monster still lives!\"" ;
             currentRoom->setNPCSpoken(currentRoom->npcCheck(command.getSecondWord()));
               } else if (currentRoom->getNPCSpoken(currentRoom->npcCheck(command.getSecondWord())) == 10) {
                   test = test +"\n\"Fine, maybe I do have something, but leave me be now, thief!\"" ;
                 mainchar->addNPCItem(Items.at(8));
                   test = test +"\nThe man hands you a small oil lamp, with seemingly nothing particularly special about it." ;
                     } else if (currentRoom->getNPCSpoken(currentRoom->npcCheck(command.getSecondWord())) > 10) {
                         test = test +"\n\"Why are you still talking to me? The monster still lives!\"" ;
                     }
             break;
           }
     } else {
         test = test +"\nThat person is not in the room!" ;
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
         test = test + "\nDamage taken from:" + temp.getShortDescription() + ":" + "\nMissed!" ; } }
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
            return "\nThere are no monsters in the room!";
        }
        case 1: {
            return "\nPlease enter a monster to attack!";
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
string ZorkUL::goRoom(Command command) {
    string str;
    if (!command.hasSecondWord()) {
        str = str +"\nIncomplete input";

    }

    if (currentRoom->doorCheck(command.getSecondWord()) >= 0 && (currentRoom->doorTypeCheck(command.getSecondWord()) == "Door")) {
        str = str + "This door is locked!\n" ;
        str = str + "\n" + currentRoom->longDescription() ;
    } else if (currentRoom->doorCheck(command.getSecondWord()) >= 0 && (currentRoom->doorTypeCheck(command.getSecondWord()) == "Blockage")) {
        str = str + "This way is blocked!\n" ;
        str = str + "\n" + currentRoom->longDescription() ;
    } else if (currentRoom->doorCheck(command.getSecondWord()) < 0) {

    if (currentRoom->getammoutofenemy() != 0){
        str = str +"Can't go, there are monsters in the way!\n" ;
        str = str  +currentRoom->longDescription() ;
    } else if  (currentRoom->getammoutofenemy() == 0){

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL) {
        str = str +"\nNo Room in that Direction!";
        str = str + "\n" + currentRoom->longDescription() ;
    }
    else {
        currentRoom = nextRoom;
        if(currentRoom->shortDescription().compare("Boss Room")==0){
            win = 1;
            str = str +"End" ;
        }
        else
        str = str +currentRoom->longDescription() ;
    }
      }

}
    string qstr = str;
    return qstr;
}


