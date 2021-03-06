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
    std::vector<Position> paintPoses{}; // вектор с всички позиции, на които е възможно разливане на боя

    void deserialization();
    void buildRoom();
    void setCurrPos(const Position&);
    void setGoalPos(const Position&);

public:
    Drone();

    Position getCurrPos() const;
    Position getGoalPos() const;

    std::vector<std::vector<char>> getRoom() const;
    std::vector<Position> getPaintPoses() const;
    
    int getRoomLenght() const;
    int getRoomWidth() const;
};

#endif