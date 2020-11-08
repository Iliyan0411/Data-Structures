#ifndef DRONE_H
#define DRONE_H
#include "Room.h"

class Drone
{
private:
    Room r;
    Position posInRoom;
    int painted;
    int turns;

public:
    // constructors:
    Drone(const Room& _r);
    Drone();

    // set methods:
    void setPainted(const int& _painted);
    void setTurns(const int& _turns);
    void setPosInRoom(const Position& _posInRoom);

    // get methods:
    int getPainted() const;
    int getTurns() const;
    Position getPosInRoom() const;

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