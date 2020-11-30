#ifndef DRONE_H
#define DRONE_H
#include "Room.h"

class Drone
{
private:
    Room r;
    int painted;
    int turns;

public:
    // constructor:
    Drone(const Room& _r);

    // get methods:
    int getPainted() const;
    int getTurns() const;
    Room getRoom() const;

    // increasing:
    void increasePainted();
    void increaseTurns();

    // moving:
    void N();
    void S();
    void E();
    void W();
    void P();
};

#endif