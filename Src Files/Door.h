#ifndef DOOR_H
#define DOOR_H

#include <string>
using namespace std;
#include <vector>
using std::vector;


class Door {
private:
protected:
    string direction;
    string type;
    int keyid;
    bool isLocked;
public:
    Door(bool isLocked, int keyid, string direction, string type);
    void setUnlocked();
    int getId();
    int lockedCheck();
    string getDirection();
    string getType();
};

#endif /*DOOR_H_*/
