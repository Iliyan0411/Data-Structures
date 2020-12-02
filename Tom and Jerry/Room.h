#ifndef ROOM_H
#define ROOM_H
#include "Position.h"
#include <vector>


class Room
{
private:
    int lenght, width;
    std::vector<std::vector<char>> room{};
    Position JerryPos;
    Position TomPos;
    Position dronePos;

public:
    // constructors:
    Room(const int& _lenght, const int& _width, const Position& _JerryPos, const Position& _TomPos);
    Room();

    // set methods:
    void setLenght(const int& _lenght);
    void setWidth(const int& _width);
    void setRoom();
    void setJerryPos(const Position& _JerryPos);
    void setTomPos(const Position& _TomPos);
    void moveDrone(const Position& newPos);
    void setPos(const char& c);

    // get methods:
    int getLenght() const;
    int getWidth() const;
    std::vector<std::vector<char>> get_room() const;
    Position getJerryPos() const;
    Position getTomPos() const;
    Position getDronePos() const;

    // operators:

    Room& operator = (const Room& other);
};


#endif