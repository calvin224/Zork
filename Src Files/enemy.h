#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <QPixmap>
#include <iostream>
using namespace std;

template <class T>
class mypair {
    T a, b;
  public:
    mypair (T first, T second)
      {a=first; b=second;}
    T getmax ();
};

template <class T>
T mypair <T>::getmax ()
{
  T retval;
  retval = a>b? a : b;
  return retval;
}

//abstract class with virtual functions
class Enemy
{
protected:
    //bit structures
    unsigned int hp = 10;
    unsigned int dmgout : 6;
    unsigned int accuracy;
    string image;
public:
   template<typename T>
    T Min(T x, T y){
        return (x < y)? x: y;
    }
   string name;
   virtual string getShortDescription();
   virtual int gethp();
   virtual void sethp(int damage);
   virtual int getdmgout();
   virtual  int getaccuracy() ;
   virtual string getimage();
};
//polymorphism + inheritance
class Goblin: public Enemy{
public:
    Goblin();
    friend Enemy;
};
class superArcher {
public:
    string newname = "superArcher";
    int newdmgout = 4;
    string newimage = ":/Images/superSkeleton.jpg";
};
//multi inheritance
class Archer: public Enemy, public superArcher{
public:
    Archer();
    friend superArcher;
};

#endif // ENEMY_H
