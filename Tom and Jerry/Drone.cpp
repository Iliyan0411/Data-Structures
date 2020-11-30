#include "Drone.h"

//constructor:
Drone::Drone(const Room& _r)
{
    r = _r;
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
    return r;
}

// increase methods:
void Drone::increaseTurns()
{
    ++turns;
}

// drone moving:
void Drone::N()
{
    r.moveDrone({-1,0});
}
void Drone::S()
{
    r.moveDrone({1,0});
}
void Drone::E()
{
    r.moveDrone({0,1});
}
void Drone::W()
{
    r.moveDrone({0,-1});
}
void Drone::P()
{
    r.paintPos();
    ++painted;
}