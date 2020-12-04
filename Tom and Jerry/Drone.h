#ifndef _DRONE_H
#define _DRONE_H
#include <vector>
#include <fstream>
#include "Position.h"


class Drone
{
private:
    std::vector<std::vector<char>> room;
    int roomLenght, roomWidth;
    Position currPos;
    Position goalPos;
    int turns;
    int paintedPos;

public:
    Drone();

    void setRoom();
    void setCurrPos(const Position& pos);
    void setGoalPos(const Position& pos);

    void N();
    void S();
    void E();
    void W();
    void P();
};

#endif