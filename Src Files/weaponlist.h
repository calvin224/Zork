#ifndef WEAPONLIST_H
#define WEAPONLIST_H
#include <string>
using namespace std;

class Weaponlist
{
public:
    Weaponlist(string name ,int dmg);
    int damage;
    string name;
};

#endif // WEAPONLIST_H
