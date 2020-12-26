#include "Game.h"


void Game::buildTree(const std::vector<std::queue<char>>& v)
{
    tree.clear();
    tree.reset();

    for(std::queue<char> q : v)
    {
        tree.add(q);
    }

    tree.createLeafIndex();

    std::ofstream out("viz.dot");
    if(!out){
        throw std::runtime_error ("File error");
    }

    tree.viz(out);

    if(!out){
        throw std::runtime_error ("File error");
    }
    
    out.close();
}

std::vector<std::vector<Position>> Game::findPaths()
{
    std::vector<Position> currPath;
    std::vector<std::vector<Position>> allPaths;

    findPathsHelper(drone.getCurrPos(), drone.getGoalPos(), currPath, drone.getRoom(), allPaths);

    return allPaths;
}

void Game::findPathsHelper(Position curr, Position goal, std::vector<Position>& currPath, std::vector<std::vector<char>> room,
                            std::vector<std::vector<Position>>& allPaths)
{
    if(curr.x < 0 || curr.y < 0 || curr.x >= drone.getRoomLenght() || curr.y >= drone.getRoomWidth() ||
        room[curr.x][curr.y] == '1')
    {
        return;
    }

    int len = currPath.size();
    currPath.push_back(curr);

    if(curr == goal)
    {
        allPaths.push_back(currPath);
    }
    else
    {
        room[curr.x][curr.y] = '1';

        findPathsHelper({curr.x-1, curr.y}, goal, currPath, room, allPaths);
        findPathsHelper({curr.x+1, curr.y}, goal, currPath, room, allPaths);
        findPathsHelper({curr.x, curr.y+1}, goal, currPath, room, allPaths);
        findPathsHelper({curr.x, curr.y-1}, goal, currPath, room, allPaths);

        room[curr.x][curr.y] = '0';
    }
    
    currPath.resize(len);
}

void Game::convertToInstructions(const std::vector<std::vector<Position>>& paths, std::vector<std::queue<char>>& instructions)
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

std::vector<std::vector<Position>> Game::filterAllMinPaths(const std::vector<std::vector<Position>>& allPaths)
{
     int min = allPaths[0].size();

    for(int i = 1; i < allPaths.size(); i++)
    {
        if(allPaths[i].size() < min)
        {
            min = allPaths[i].size();
        }
    }

    std::vector<std::vector<Position>> allMinPaths;
    for(int i = 0; i < allPaths.size(); i++)
    {
        if(allPaths[i].size() == min)
        {
            allMinPaths.push_back(allPaths[i]);
        }
    }

    return allMinPaths;
}

int Game::setTurns(const std::string& path)
{
    int turns = 0;

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
    if(turns > 0) turns--;

    return turns;
}

int Game::setPaintedPlaces(const std::string& path)
{
    int paintedPlaces = 0;

    for(char c : path)
    {
        if(c == 'P')
        {
            paintedPlaces++;
        }
    }

    return paintedPlaces;
}

int Game::setPathLenght(const std::string& path)
{
    int pathLenght = 0;

    for(int i = 1; i < path.size(); i++)
    {
        if(path[i] != 'P')
        {
            pathLenght++;
        }
    }

    return pathLenght;
}

int Game::paintCount(std::queue<char> q) const
{
    int count = 0;
    while(!q.empty())
    {
        if(q.front() == 'P')
        {
            count++;
        }

        q.pop();
    }

    return count;
}

int Game::turnsCount(std::queue<char> q) const
{
    int count = 0;

    std::string str;
    while(!q.empty())
    {
        str.push_back(q.front());
        q.pop();
    }

    for(int i = 1; i < str.size(); i++)
    {
       if(str[i] != str[i - 1] && str[i] != 'P' && str[i - 1] != 'P')
       {
           count++;
       }
       else if(str[i - 1] == 'P' && str[i] != str[i - 2])
       {
           count++;
       }
    }
    count--;


    return count;
}

std::vector<std::queue<char>> Game::MAXpaintMINturns()
{
    int paintMax = paintCount(allPathInstr[0]);
    std::vector<int> indexes;

    for(int i = 1; i < allPathInstr.size(); i++)
    {
        if(paintCount(allPathInstr[i]) > paintMax)
        {
            paintMax = paintCount(allPathInstr[i]);
        }
    }

    for(int i = 0; i < allPathInstr.size(); i++)
    {
        if(paintCount(allPathInstr[i]) == paintMax)
        {
            indexes.push_back(i);
        }
    }

    int turnsMin = turnsCount(allPathInstr[indexes[0]]);

    for(int i = 1; i < indexes.size(); i++)
    {
        if(turnsCount(allPathInstr[indexes[i]]) < turnsMin)
        {
            turnsMin = turnsCount(allPathInstr[indexes[i]]);
        }
    }


    std::vector<std::queue<char>> result;

    for(int i = 0; i < indexes.size(); i++)
    {
        if(turnsCount(allPathInstr[indexes[i]]) == turnsMin)
        {
            result.push_back(allPathInstr[indexes[i]]);
        }
    }

    return result;
}

void Game::load()
{
    std::vector<std::vector<Position>> buffer = findPaths();
    
    convertToInstructions(buffer, allPathInstr);
    convertToInstructions(filterAllMinPaths(buffer), allMinPathInstr);
}

void Game::userInput(int& choose)
{
    while(!(std::cin >> choose)) 
    {
        std::cin.clear();

        while (std::cin.get() != '\n')
        {
            continue;
        }

        std::cout << "Enter number again: ";
    }		
}

void Game::run()
{
    load();

    //============
    std::cout << "\n\t\t\tTOM AND JERRY\n";
    std::cout << "\t\t      =================\n\n";

    int choose = 0;

    while(choose != 4)
    {
        PTree::indexCounter = 0;

        std::cout << "[1] View all paths\n";
        std::cout << "[2] View all min paths\n";
        std::cout << "[3] View paths with maximum painted places and minimum turns\n";
        std::cout << "[4] Exit\n\n";
        //============
        
        //============
        std::cout << "Enter number(1-4): ";
        do{
            userInput(choose);
        } while(choose < 1 || choose > 4);


        if(choose == 1) buildTree(allPathInstr);
        if(choose == 2) buildTree(allMinPathInstr);
        if(choose == 3) buildTree(MAXpaintMINturns());
        if(choose == 4) return;
        //============

        //============
        PTree::indexCounter--;
        std::cout << "\nChoose path(0 - " << PTree::indexCounter << "): ";

        int id = 0;
        do{
            userInput(id);
        } while(id < 0 || id > PTree::indexCounter);


        std::string path = tree.wantedPath(id);
        int turns = setTurns(path);
        int paintedPlaces = setPaintedPlaces(path);
        int pathLenght = setPathLenght(path);
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
        
        //============
        for(int i = 0; i < 7; i++)
        {
            std::cout << "#\n";
        }std::cout << std::endl;
    }
}