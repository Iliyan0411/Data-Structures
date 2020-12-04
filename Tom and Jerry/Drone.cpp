#include "Drone.h"

Drone::Drone()
{
    std::ifstream in("parameters.txt");

    in >> roomWidth;
    in >> roomLenght;
    in.ignore();

    setRoom();

    int x, y;
    in >> x;
    in >> y;
    in.ignore();

    room[x][y] = 'J';
    setGoalPos({x,y});

    in >> x;
    in >> y;
    in.ignore();

    setCurrPos({x,y});

    int K, L;
    in >> K;
    in >> L;
    in.ignore();

    for(int i = 0; i < K; i++)
    {
        in >> x;
        in >> y;
        in.ignore();

        int tempY = y;

        while(in.peek() != '=')
        {            
            while(in.peek() != '\n')
            {
                char c;
                in.get(c);

                if(c == '1')
                {
                    room[x][y] = '1';
                    y++;
                }
                if(c == ' ')
                {
                    y++;
                }
            }
            if(in.peek() == '\n')
            {
                in.ignore();
                x++;
                y = tempY;
            }
        }

        while(in.peek() != '\n')
        {
            in.get();
        }in.ignore();
    }

    for(int i = 0; i < L; i++)
    {
        in >> x;
        in >> y;
        in.ignore();

        room[x][y] = 'p';
    }

    in.close();
}

void Drone::setRoom()
{
    room.resize(roomLenght);

    for(int i = 0; i < roomLenght; ++i)
    {
        room[i].resize(roomWidth);
    }

    for(int i = 0; i < roomLenght; ++i)
    {
        for(int j = 0; j < roomWidth; ++j)
        {
            room[i][j] = '0';
        }
    }
}

void Drone::setCurrPos(const Position& pos)
{
    currPos = pos;
}

void Drone::setGoalPos(const Position& pos)
{
    goalPos = pos;
}

void Drone::N()
{

}

void Drone::S()
{

}

void Drone::E()
{

}

void Drone::W()
{

}

void Drone::P()
{

}