#include "Room.h"

Room::Room(const int& _lenght, const int& _width, const Position& _JerryPos, const Position& _TomPos, 
            const int& _numFurniture, const int& _numPaintPos)
    {
        setLenght(_lenght);
        setWidth(_width);
        setJerryPos(_JerryPos);
        setTomPos(_TomPos);
        setNumFurniture(_numFurniture);
        setNumPaintPos(_numPaintPos);
        setRoom();
    }
Room::Room()
{
    setLenght(0);
    setWidth(0);
    setJerryPos({0,0});
    setTomPos({0,0});
    setNumFurniture(0);
    setNumPaintPos(0);
}

// set methods:
void Room::setLenght(const int& _lenght)
{
    lenght = _lenght;
}
void Room::setWidth(const int& _width)
{
    width = _width;
}
void Room::setRoom()
{
    room.resize(lenght);

    for(int i = 0; i < lenght; ++i)
    {
        room[i].resize(width);
    }

    for(int i = 0; i < lenght; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            room[i][j] = '0';
        }
    }
}
void Room::setJerryPos(const Position& _JerryPos)
{
    JerryPos = _JerryPos;
}
void Room::setTomPos(const Position& _TomPos)
{
    TomPos = _TomPos;
}
void Room::setNumFurniture(const int& _numFurniture)
{
    numFurniture = _numFurniture;
}
void Room::setNumPaintPos(const int& _numPaintPos)
{
    numPaintPos = _numPaintPos;
}

// get methods:
int Room::getLenght() const
{
    return lenght;
}
int Room::getWidth() const
{
    return width;
}
std::vector<std::vector<char>> Room::getRoom() const
{
    return room;
}
Position Room::getJerryPos() const
{
    return JerryPos;
}
Position Room::getTomPos() const
{
    return TomPos;
}
int Room::getNumFurniture() const
{
    return numFurniture;
}
int Room::getNumPaintPos() const
{
    return numPaintPos;
}