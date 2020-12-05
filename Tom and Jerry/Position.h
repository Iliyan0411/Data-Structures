#ifndef POSITION_H  
#define POSITION_H
#include <iostream>


struct Position
{
    int x,y;

    Position& operator = (const Position& other)
    {
        if(this != &other)
        {
            x = other.x;
            y = other.y;
        }

        return *this;
    }

    bool operator == (const Position& other)
    {
        return x == other.x && y == other.y;
    }

    void set(const int& _x, const int& _y)
    {
        x = _x;
        y = _y;
    }

    void print() const
    {
        std::cout << "(" << x << "," << y << ")\t";
    }
};


#endif