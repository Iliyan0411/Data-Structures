#ifndef POSITION_H
#define POSITION_H

struct Position
{
    int col, row;

    Position down()
    {
        return {col+1,row};
    }
    Position right()
    {
        return {col,row+1};
    }
    Position left()
    {
        return {col,row-1};
    }
    Position up()
    {
        return {col-1,row};
    }

    // Position& operator = (const Position& other)
    // {
    //     row = other.row;
    //     col = other.col;

    //     return *this;
    // }
    bool operator != (const Position& other) const
    {
        return row != other.row || col != other.col;
    }
};


#endif
