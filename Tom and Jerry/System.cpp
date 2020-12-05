#include "System.h"


void System::buildTree(const std::vector<std::queue<char>>& v)
{
    PTree tree;

    for(std::queue<char> q : v)
    {
        tree.add(q);
    }

    std::ofstream out("viz.dot");
    tree.viz(out);
    out.close();
}

void System::findPaths()
{
    std::vector<Position> v{};

    findPathsHelper(drone.getCurrPos(), drone.getGoalPos(), v, drone.getRoom());
}

void System::findPathsHelper(Position curr, Position goal, std::vector<Position>& v, std::vector<std::vector<char>> room)
{
    if(curr.x < 0 || curr.y < 0 || curr.x >= drone.getRoomLenght() || curr.y >= drone.getRoomWidth() ||
        room[curr.x][curr.y] == '1')
    {
        return;
    }

    int len = v.size();
    v.push_back(curr);

    if(curr == goal)
    {
        allPaths.push_back(v);
    }
    else
    {
        room[curr.x][curr.y] = '1';

        findPathsHelper({curr.x-1, curr.y}, goal, v, room);
        findPathsHelper({curr.x+1, curr.y}, goal, v, room);
        findPathsHelper({curr.x, curr.y+1}, goal, v, room);
        findPathsHelper({curr.x-1, curr.y-1}, goal, v, room);

        room[curr.x][curr.y] = '0';
    }
    
    v.resize(len);
}

void System::convertToInstructions()
{
    std::queue<char> q;

    for(int i = 0; i < allPaths.size(); i++)
    {
        for(int j = 1; j < allPaths[i].size(); j++)
        {
            if(allPaths[i][j].x + 1 == allPaths[i][j-1].x && allPaths[i][j].y == allPaths[i][j-1].y)
            {
                q.push('N');
            }
            if(allPaths[i][j].x - 1 == allPaths[i][j-1].x && allPaths[i][j].y == allPaths[i][j-1].y)
            {
                q.push('S');
            }
            if(allPaths[i][j].x == allPaths[i][j-1].x && allPaths[i][j].y - 1 == allPaths[i][j-1].y)
            {
                q.push('E');
            }
            if(allPaths[i][j].x == allPaths[i][j-1].x && allPaths[i][j].y + 1 == allPaths[i][j-1].y)
            {
                q.push('W');
            }
        }

        allPathInstr.push_back(q);

        while(!q.empty())
        {
            q.pop();
        }
    }
}

void System::filterAllMinPaths()
{
    int min = allPaths[0].size();

    for(int i = 1; i < allPaths.size(); i++)
    {
        if(allPaths[i].size() < min)
        {
            min = allPaths[i].size();
        }
    }

    for(int i = 0; i < allPaths.size(); i++)
    {
        if(allPaths[i].size() == min)
        {
            allMinPaths.push_back(allPaths[i]);
        }
    }
}

void System::filterAllMinPathInstructions()
{
    int min = allPathInstr[0].size();

    for(int i = 1; i < allPathInstr.size(); i++)
    {
        if(allPathInstr[i].size() < min)
        {
            min = allPathInstr[i].size();
        }
    }

    for(int i = 0; i < allPathInstr.size(); i++)
    {
        if(allPathInstr[i].size() == min)
        {
            allMinPathInstr.push_back(allPathInstr[i]);
        }
    }
}

void System::run()
{
    std::cout << "\t\t\tTOM AND JERRY\n";
    std::cout << "\t\t      ==================\n\n";
    //============

    findPaths();
    convertToInstructions();

    filterAllMinPaths();
    filterAllMinPathInstructions();

    //=============
    std::cout << "[1] View all possible paths\n";
    std::cout << "[2] View all min paths\n\n";
    std::cout << "Enter number(1-2):";
    
    int x;
    do
    {
        std::cin >> x;
    }while(x < 1 || x > 2);

    if(x == 1) buildTree(allPathInstr);
    if(x == 2) buildTree(allMinPathInstr);
}