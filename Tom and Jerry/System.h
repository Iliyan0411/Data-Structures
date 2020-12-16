#ifndef _SYSTEM_H
#define _SYSTEM_H
#include "PathTree.h"
#include "Drone.h"


class System
{
private:
    PTree tree;
    Drone drone;
    std::vector<std::queue<char>> allPathInstr;
    std::vector<std::queue<char>> allMinPathInstr; 


    void buildTree(const std::vector<std::queue<char>>&);
    
    std::vector<std::vector<Position>> findPaths();
    void findPathsHelper(Position, Position, std::vector<Position>&, std::vector<std::vector<char>>, std::vector<std::vector<Position>>&);

    void convertToInstructions(const std::vector<std::vector<Position>>&, std::vector<std::queue<char>>&);
    std::vector<std::vector<Position>> filterAllMinPaths(const std::vector<std::vector<Position>>&);
   
    std::vector<std::queue<char>> MAXpaintMINturns();
    int paintCount(std::queue<char>) const;
    int turnsCount(std::queue<char>) const;

    int setTurns(const std::string&);
    int setPaintedPlaces(const std::string&);
    int setPathLenght(const std::string&);

    void load();

public:
    void run();
};

#endif