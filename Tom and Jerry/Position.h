#ifndef POSITION_H  
#define POSITION_H


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
};


#endif