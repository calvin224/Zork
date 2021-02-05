#include <iostream>

using namespace std;
#include "ZorkUL.h"
Character *mainchar;
string wincon;

int main() {
    ZorkUL temp;
    temp.play();
    return 0;

}
//starter functions;
ZorkUL::ZorkUL() {
    createRooms();
}

void ZorkUL::createRooms()  {
    mainchar = new Character();
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i ,*m;
    a = new Room("castle");
        a->addItem(new Item("potion", 1, 11,0,0,1));
        a->addItem(new Item("sword", 5, 15,2,0,2));
        a->addenemys(1,2);
        a->addDoor(new Door(1, 1, "east"));
        a->addItem(new Item("key", 2, 2,0,1,3));
    b = new Room("Creepy Woods");
        b->addItems(4);
        b->addItem(new Item("KEYITEM", 2, 2,0,1,0));
        b->addenemys(1,1);
    c = new Room("c");
    d = new Room("d");
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
void ZorkUL::play() {
    printWelcome();
    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

   bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
        delete command; }
}

void ZorkUL::end(){
    cout <<"you died please restart" << endl;
    death = true;
}


void ZorkUL::printWelcome() {
    cout << "start"<< endl;
    cout << "info for help"<< endl;
    cout << endl;
    cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command){
    if(win > 0){
       if(win == 1){
           cout << "You saved the kingdom while keeping your sanity and life!" << endl;
           return false;
       }
    }
    if (death){
        end();
        return false;
    }
    if (command.isUnknown()) {
        cout << "invalid input"<< endl;
        return false;
    }
    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        printHelp();

    else if (commandWord.compare("map") == 0)
        {
        cout << "[h] --- [f] --- [g]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[c] --- [a] --- [b]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[i] --- [d] --- [e]" << endl;
        }

    else if (commandWord.compare("go") == 0)
        goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
        if (currentRoom->getammoutofenemy() != 0){

            cout << "Can't take, there are monsters in the way!" << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;

        } else if  (currentRoom->getammoutofenemy() == 0){

           if (!command.hasSecondWord()) {
           cout << "incomplete input"<< endl;
           }
           else if (command.hasSecondWord()) {

           cout << "you're trying to take " + command.getSecondWord() << endl;
           Item newItem = currentRoom -> getItem(currentRoom -> addItemFromRoom(command.getSecondWord()));
           mainchar->addItem(newItem);
           int location = currentRoom->isItemInRoom(command.getSecondWord());
           if (location  < 0 )
               cout << "item is not in room" << endl;
           else
               cout << "item is in room" << endl;
             cout << "index number " << + location << endl;
               cout << endl;
               cout << currentRoom->longDescription() << endl;
             }
            }
       }

    else if (commandWord.compare("put") == 0)
    {
       cout << "you put a item down" << endl;
    }

else if (commandWord.compare("use") == 0)
    {
        string tempdirection;
        int itemid = mainchar -> getItemID(mainchar -> findItemInInv(command.getSecondWord()));
          switch(itemid) {
          case 1 :
            cout << "You drink the potion." << endl;
                mainchar->potionDrank();
            cout << "Your new health points are: " << mainchar->getHealthPoint() << endl;
            break;
          case 2 :
            cout << "You equip the " << mainchar -> getItemName(mainchar -> findItemInInv(command.getSecondWord())) << "." << endl;
                mainchar->equipWeapon(mainchar -> getItemDmg(mainchar -> findItemInInv(command.getSecondWord())));
            cout << "Your new attack points are: " << mainchar->getDamageOut() << endl;
            break;
          case 3 :
            cout << "You use the key." << endl;
                if ((currentRoom->useKey(mainchar -> getKeyID(mainchar -> findItemInInv(command.getSecondWord())))) >= 0) {
                    currentRoom->doorUnlock(currentRoom->useKey(mainchar -> getKeyID(mainchar -> findItemInInv(command.getSecondWord()))));
                    tempdirection = currentRoom->getDoorDirection(currentRoom->useKey(mainchar -> getKeyID(mainchar -> findItemInInv(command.getSecondWord()))));
                    cout << "You unlocked the door to the " << tempdirection << endl;
                    break;
                } else {
                    cout << "This key cannot be used here!" << endl;
                    break;
                }
            break;
          case 4 :
            cout << "test" << endl;
            break;
           case 5 :
            cout << "test" << endl;
            break;
           default :
            cout << "Invalid item!" << endl;
               }

        }

    else if (commandWord.compare("inventory") == 0)
        {
            cout << mainchar->longDescription() << endl;
        }

    else if (commandWord.compare("attack") == 0)
        if (currentRoom->getammoutofenemy() == 0){
            cout << "No monsters!" << endl;
        }
       else if (!command.hasSecondWord()) {
             cout << "Please enter a monster to attack!" << endl;
         }
       else if (currentRoom->getammoutofenemy() != 0) {
            index = std::stoi(command.getSecondWord());
             currentRoom->enemytakedmg(mainchar->getDamageOut(), index);
          if ((currentRoom->getenemyhp(index)) > 0){
            index = std::stoi(command.getSecondWord());
            cout << "Monster not dead!" << endl;
            cout << "Monster hp = "<< + currentRoom->getenemyhp(index) << endl;
            cout << "Damage given: "<< + mainchar->dmgout << endl;
            cout << "Damage taken: "<< + currentRoom->getdmgout(index) << endl;
            mainchar->setHealthPoint(mainchar->hp - currentRoom->getdmgout(index));
            cout << "Your hp = "<< + mainchar->hp << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
            if(mainchar->hp <= 0 ){
               end();
            }
        }
        else if  ( currentRoom->getenemyhp(index) <= 0) {
         index = std::stoi(command.getSecondWord());
         currentRoom->deadenemy(index);
         cout << "Monster dead!" << endl;
         cout << "Your hp = "<< + mainchar->hp << endl;
         cout << endl;
         cout << currentRoom->longDescription() << endl; } }  

    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            return true;
    }
    return false;
}




/** COMMANDS **/
void ZorkUL::printHelp() {
    cout << "valid inputs are; " << endl;
    parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

    if (currentRoom->doorCheck(command.getSecondWord()) >= 0) {
        cout << currentRoom->doorCheck(command.getSecondWord()) << endl;
        cout << "This door is locked!" << endl;
    } else if (currentRoom->doorCheck(command.getSecondWord()) < 0) {

    if (currentRoom->getammoutofenemy() != 0){

        cout << "Can't go, there are monsters in the way!" << endl;
        cout << endl;
        cout << currentRoom->longDescription() << endl;

    } else if  (currentRoom->getammoutofenemy() == 0){

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input"<< endl;
    else {
        currentRoom = nextRoom;
        if(currentRoom->shortDescription().compare("end zone")==0){
            win = 1;
            cout << "You saved the kingdom while keeping your sanity and life!" << endl;
        }
        else
        cout << currentRoom->longDescription() << endl;
    }
      }
}
}
