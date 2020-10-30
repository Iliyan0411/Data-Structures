#include "Position.h"
#include <iostream>
#include <stack>

const int labSize = 8;
 int lab[labSize][labSize] = 
    {
        0,1,0,0,0,0,0,0,
        0,1,0,0,0,0,0,0,
        0,1,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        1,0,1,0,0,0,0,0,
        0,0,1,0,0,0,0,0,
        0,0,1,0,0,0,1,0,
        0,0,1,0,0,0,1,0
    };

bool validPosition(const Position& curr)
{
    return curr.row >= 0 &&
            curr.col >= 0 &&
            curr.row < labSize &&
            curr.col < labSize &&
            lab[curr.row][curr.col] == 0;
}

bool findPath(const Position& start, const Position& goal)
{
    std::stack<Position> s;
    s.push(start);

    while(!s.empty() && s.top() != goal)
    {
        Position current = s.top();
        s.pop();

        if(validPosition(current))
        {
            lab[current.row][current.col] = -1;

            s.push(current.down());
            s.push(current.right());
            s.push(current.left());
            s.push(current.up());
        }
    }

    return !s.empty();
}


int main()
{
    std::cout << findPath({0,0}, {7,7});
}