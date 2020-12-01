#include "Drone.h"

//constructor:
Drone::Drone(const Room& _room)
{
    room = _room;
    painted = 0;
    turns = 0;
}

// get methods:
int Drone::getPainted() const
{
    return painted;
}
int Drone::getTurns() const
{
    return turns;
}
Room Drone::getRoom() const
{
    return room;
}

// increase methods:
void Drone::increaseTurns()
{
    ++turns;
}

// drone moving:
Position Drone::N()
{
    room.moveDrone({-1,0});

    return room.getDronePos();
}
Position Drone::S()
{
    room.moveDrone({1,0});
}
Position Drone::E()
{
    room.moveDrone({0,1});
}
Position Drone::W()
{
    room.moveDrone({0,-1});
}
void Drone::P()
{
    room.setPos('p');
    ++painted;
}