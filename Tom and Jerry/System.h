#ifndef _SYSTEM_H
#define _SYSTEM_H
#include "PathTree.h"
#include "Drone.h"


class System
{
private:
    int paintedPlaces;
    int turns;
    int pathLenght;

    PTree tree{};
    Drone drone{};
    std::vector<std::vector<Position>> allPaths{};
    std::vector<std::vector<Position>> allMinPaths{};
    std::vector<std::queue<char>> allPathInstr{};
    std::vector<std::queue<char>> allMinPathInstr{};

    void buildTree(const std::vector<std::queue<char>>& v);
    void findPaths();
    void findPathsHelper(Position curr, Position goal, std::vector<Position>& v, std::vector<std::vector<char>> room);
    void convertToInstructions(const std::vector<std::vector<Position>>& paths, std::vector<std::queue<char>>& instructions);
    void filterAllMinPaths();
    void load();
    void setTurns(const std::string& path);
    void setPaintedPlaces(const std::string& path);
    void setPathLenght(const std::string& path);

public:
    System() : paintedPlaces(0), turns(0), pathLenght(0) {}

    void run();
};

#endif