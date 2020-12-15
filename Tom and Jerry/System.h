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
    
    std::vector<std::queue<char>> allPathInstr{}; // съдържа всички пътища от Том до Джери под формата на инструкции, определящи 
                                                  // в коя посока да се движим 
    
    std::vector<std::queue<char>> allMinPathInstr{}; // съдържа всички най-къси пътища от Том до Джери под формата на инструкции, определящи 
                                                  // в коя посока да се движим

    void buildTree(const std::vector<std::queue<char>>& v);
    std::vector<std::vector<Position>> findPaths(); // намира всички пътища от Том до Джери
    void findPathsHelper(Position curr, Position goal, std::vector<Position>& v, std::vector<std::vector<char>> room,
                        std::vector<std::vector<Position>>&);

    // конвертира пътищата от позиции, в пътища от инструкци
    void convertToInstructions(const std::vector<std::vector<Position>>& paths, std::vector<std::queue<char>>& instructions);
    std::vector<std::vector<Position>> filterAllMinPaths(const std::vector<std::vector<Position>>&); // намира най-късите пътища
    void load();
    void setTurns(const std::string& path);
    void setPaintedPlaces(const std::string& path);
    void setPathLenght(const std::string& path);
   
    std::vector<std::queue<char>> MAXpaintMINturns();

    int paintCount(std::queue<char> q) const;
    int turnsCount(std::queue<char> q) const;

public:
    System() : paintedPlaces(0), turns(0), pathLenght(0) {}

    void run(); // изпълнява всички функционалности на проекта
};

#endif