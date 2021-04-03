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
    int keyid;
    bool isLocked;
public:
    Door(bool isLocked, int keyid, string direction);
    void setUnlocked();
    int getId();
    int lockedCheck();
    string getDirection();
};

#endif /*DOOR_H_*/
