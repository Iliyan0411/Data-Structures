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

    void buildRoom();
    void setCurrPos(const Position& pos);
    void setGoalPos(const Position& pos);

public:
    Drone();    

    Position getCurrPos() const;
    Position getGoalPos() const;
    std::vector<std::vector<char>> getRoom() const;
    bool correctPos() const;

    void setRoom(const char& c);
    int getRoomLenght() const;
    int getRoomWidth() const;

    Drone& N();
    Drone& S();
    Drone& E();
    Drone& W();
    void P();
};

#endif