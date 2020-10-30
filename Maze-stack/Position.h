#ifndef POSITION_H
#define POSITION_H

struct Position
{
    int row, col;

    Position down()
    {
        return {row+1,col};
    }
    Position right()
    {
        return {row,col+1};
    }
    Position left()
    {
        return {row,col-1};
    }
    Position up()
    {
        return {row-1,col};
    }

    Position& operator = (const Position& other)
    {
        row = other.row;
        col = other.col;

        return *this;
    }
    bool operator != (const Position& other) const
    {
        return row != other.row || col != other.col;
    }
};


#endif
