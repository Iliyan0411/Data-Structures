#include "System.h"


void System::buildTree(const std::vector<std::queue<char>>& v)
{
    for(std::queue<char> q : v)
    {
        tree.add(q);
    }

    tree.createLeafIndex();

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
        findPathsHelper({curr.x, curr.y-1}, goal, v, room);

        room[curr.x][curr.y] = '0';
    }
    
    v.resize(len);
}

void System::convertToInstructions(const std::vector<std::vector<Position>>& paths, std::vector<std::queue<char>>& instructions)
{
    std::queue<char> q;

    for(int i = 0; i < paths.size(); i++)
    {
        for(int j = 1; j < paths[i].size(); j++)
        {
            if(paths[i][j].x + 1 == paths[i][j-1].x && paths[i][j].y == paths[i][j-1].y)
            {
                q.push('N');

            }
            else if(paths[i][j].x - 1 == paths[i][j-1].x && paths[i][j].y == paths[i][j-1].y)
            {
                q.push('S');
            }
            else if(paths[i][j].x == paths[i][j-1].x && paths[i][j].y - 1 == paths[i][j-1].y)
            {
                q.push('E');
            }
            else if(paths[i][j].x == paths[i][j-1].x && paths[i][j].y + 1 == paths[i][j-1].y)
            {
                q.push('W');
            }

            for(Position p : drone.getPaintPoses())
            {
                if (p == paths[i][j])
                {
                    q.push('P');
                    break;
                }
            }
        }

        instructions.push_back(q);

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

void System::load()
{
    findPaths();
    
    convertToInstructions(allPaths, allPathInstr);

    filterAllMinPaths();
    convertToInstructions(allMinPaths, allMinPathInstr);
}

void System::setTurns(const std::string& path)
{
    for(int i = 1; i < path.size(); i++)
    {
       if(path[i] != path[i - 1] && path[i] != 'P' && path[i - 1] != 'P')
       {
           turns++;
       }
       else if(path[i - 1] == 'P' && path[i] != path[i - 2])
       {
           turns++;
       }
    }
    turns--;
}

void System::setPaintedPlaces(const std::string& path)
{
    for(char c : path)
    {
        if(c == 'P')
        {
            paintedPlaces++;
        }
    }
}

void System::setPathLenght(const std::string& path)
{
    for(int i = 1; i < path.size(); i++)
    {
        if(path[i] != 'P')
        {
            pathLenght++;
        }
    }
}


void System::run()
{
    load();

    //============
    std::cout << "\t\t\tTOM AND JERRY\n";
    std::cout << "\t\t      ==================\n\n";

    std::cout << "[1] View all possible paths\n";
    std::cout << "[2] View all min paths\n\n";
    //============
    
    //============
    int x;
    do
    {
        std::cout << "Enter number(1-2): ";
        std::cin >> x;
    }while(x < 1 || x > 2);

    if(x == 1) buildTree(allPathInstr);
    if(x == 2) buildTree(allMinPathInstr);
    //============

    //============
    PTree::indexCounter--;
    std::cout << "\nChoose path: (0 - " << PTree::indexCounter << ")\n";

    do{
        std::cout << "Enter number: ";
        std::cin >> x;
    }while(x < 0 || x > PTree::indexCounter);

    std::string path = tree.wantedPath(x);
    setTurns(path);
    setPaintedPlaces(path);
    setPathLenght(path);
    //============
    

    //============
    std::cout << std::endl;
    for(char c : path)
    {
        std::cout << c << "->";
    }
    std::cout << "Jerry" << std::endl;

    std::cout << "# Path lenght: " << pathLenght << std::endl;
    std::cout << "# Turns: " << turns << std::endl;
    std::cout << "# Painted places: " << paintedPlaces << std::endl;
}