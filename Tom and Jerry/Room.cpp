#include "Room.h"

Room::Room(const int& _lenght, const int& _width, const Position& _JerryPos, const Position& _TomPos)
    {
        setLenght(_lenght);
        setWidth(_width);
        setJerryPos(_JerryPos);
        setTomPos(_TomPos);
        setRoom();

        dronePos = TomPos;
    }
Room::Room()
{
    setLenght(0);
    setWidth(0);
    setJerryPos({0,0});
    setTomPos({0,0});

    dronePos = TomPos;
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
            room[i][j] = ' ';
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
void Room::moveDrone(const Position& newPos)
{
    dronePos.x += newPos.x;
    dronePos.y += newPos.y;
}
void Room::setPos(const char& c)
{
    room[dronePos.x][dronePos.y] = c;
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
std::vector<std::vector<char>> Room::get_room() const
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
Position Room::getDronePos() const
{
    return dronePos;
}

// operators:
Room& Room::operator = (const Room& other)
{
    lenght = other.lenght;
    width = other.width;

    JerryPos = other.JerryPos;
    TomPos = other.TomPos;
    dronePos = other.dronePos;

    setRoom();
    for(int i = 0; i < lenght; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            room[i][j] = other.room[i][j];
        }
    }

    return *this;
}