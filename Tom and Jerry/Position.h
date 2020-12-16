#ifndef POSITION_H  
#define POSITION_H
#include <iostream>


struct Position
{
    int x,y;

    bool operator == (const Position& other)
    {
        return x == other.x && y == other.y;
    }
};


#endif
