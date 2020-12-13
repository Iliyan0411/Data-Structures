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
    std::vector<std::vector<Position>> allPaths{}; // съдържа всички пътища от Том до Джери
    std::vector<std::vector<Position>> allMinPaths{}; // съдържа само най-късите пътища от Том до Джери
    
    std::vector<std::queue<char>> allPathInstr{}; // съдържа всички пътища от Том до Джери под формата на инструкции, определящи 
                                                  // в коя посока да се движим 
    
    std::vector<std::queue<char>> allMinPathInstr{}; // съдържа всички най-къси пътища от Том до Джери под формата на инструкции, определящи 
                                                  // в коя посока да се движим

    void buildTree(const std::vector<std::queue<char>>& v);
    void findPaths(); // намира всички пътища от Том до Джери
    void findPathsHelper(Position curr, Position goal, std::vector<Position>& v, std::vector<std::vector<char>> room);

    // конвертира пътищата от позиции в пътища от инструкци
    void convertToInstructions(const std::vector<std::vector<Position>>& paths, std::vector<std::queue<char>>& instructions);
    void filterAllMinPaths(); // намира най-късите пътища
    void load();
    void setTurns(const std::string& path);
    void setPaintedPlaces(const std::string& path);
    void setPathLenght(const std::string& path);

public:
    System() : paintedPlaces(0), turns(0), pathLenght(0) {}

    void run(); // обща функция изпълняваща всички функционалности на проекта
};

#endif