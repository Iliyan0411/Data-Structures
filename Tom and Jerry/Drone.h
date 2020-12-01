#ifndef DRONE_H
#define DRONE_H
#include "Room.h"

class Drone
{
private:
    Room room;
    int painted;
    int turns;

public:
    // constructor:
    Drone(const Room& _room);

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