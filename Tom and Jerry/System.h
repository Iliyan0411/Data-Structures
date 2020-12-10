#ifndef _SYSTEM_H
#define _SYSTEM_H
#include "PathTree.h"
#include "Drone.h"


class System
{
private:
    PTree tree{};
    Drone drone{};
    int paths;
    int minPaths;
    std::vector<std::vector<Position>> allPaths{};
    std::vector<std::vector<Position>> allMinPaths{};
    std::vector<std::queue<char>> allPathInstr{};
    std::vector<std::queue<char>> allMinPathInstr{};

    void buildTree(const std::vector<std::queue<char>>& v);
    void findPaths();
    void findPathsHelper(Position curr, Position goal, std::vector<Position>& v, std::vector<std::vector<char>> room);
    void convertToInstructions();
    void filterAllMinPaths();
    void filterAllMinPathInstructions();
    void load();

public:
    System() : paths(0), minPaths(0) {}

    void run();
};

#endif