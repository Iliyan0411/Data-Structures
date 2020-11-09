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
    int numFurniture;
    int numPaintPos;

public:
    // constructors:
    Room(const int& _lenght, const int& _width, const Position& _JerryPos, const Position& _TomPos,
    const int& _numFurniture, const int& _numPaintPos);
    Room();

    // set methods:
    void setLenght(const int& _lenght);
    void setWidth(const int& _width);
    void setRoom();
    void setJerryPos(const Position& _JerryPos);
    void setTomPos(const Position& _TomPos);
    void setNumFurniture(const int& _numFurniture);
    void setNumPaintPos(const int& _numFurniture);

    // get methods:
    int getLenght() const;
    int getWidth() const;
    std::vector<std::vector<char>> getRoom() const;
    Position getJerryPos() const;
    Position getTomPos() const;
    int getNumFurniture() const;
    int getNumPaintPos() const;

    // operators:

    Room& operator = (const Room& other);
};


#endif