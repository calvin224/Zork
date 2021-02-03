#include <iostream>

using namespace std;
#include "ZorkUL.h"
Character *mainchar;

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
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i;
    a = new Room("castle");
        a->addItem(new Item("potion", 1, 11,0,0,1));
        a->addItem(new Item("sword", 5, 15,3,0,2));
        a->addenemys(1,2);
    b = new Room("b");
        b->addItems(4);
        b->addItem(new Item("KEYITEM", 2, 2,0,1));
        b->addenemys(1,1);
    c = new Room("c");
    d = new Room("d");
    e = new Room("e");
    f = new Room("f");
    g = new Room("g");
    h = new Room("h");
    i = new Room("i");

//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
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

bool ZorkUL::processCommand(Command command) {
    if (win){
        cout << "You win the kingdom has been saved!" << endl;
    }
  else if (!death){
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
        int itemid = mainchar -> getItemID(mainchar -> findItemInInv(command.getSecondWord()));

           switch(itemid) {
              case 1 :
                 cout << "You drink the potion." << endl;
                    mainchar->potionDrank();
                 cout << "Your new health points are: " << mainchar->getHealthPoint() << endl;
                 break;
              case 2 :
                 cout << "You equip the flimsy sword." << endl;
                    mainchar->equipWeapon(itemid);
                 cout << "Your new attack points are: " << mainchar->getDamageOut() << endl;
                 break;
              case 3 :
                 cout << "test" << endl;
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
else {
      end();
  }
}


/** COMMANDS **/
void ZorkUL::printHelp() {
    cout << "valid inputs are; " << endl;
    parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
    if (currentRoom->getammoutofenemy() != 0){

        cout << "Can't go, there are monsters in the way!" << endl;
        cout << endl;
        cout << currentRoom->longDescription() << endl;

    } else if  (currentRoom->getammoutofenemy() == 0){

    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input"<< endl;
    else {
        currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;
    }
}
}

string ZorkUL::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("direction null");
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}
