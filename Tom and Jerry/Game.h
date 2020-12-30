#ifndef _GAME_H
#define _GAME_H
#include "PathTree.h"
#include "Drone.h"


class Game
{
private:
    PTree tree;
    Drone drone;
    std::vector<std::queue<char>> allPathInstr; // вектор от всички възможни пътища
    std::vector<std::queue<char>> allMinPathInstr; // вектор от най-късите пътища


    // създава дърво от всички пътища подадени чрез вектора
    void buildTree(const std::vector<std::queue<char>>&);
    
    std::vector<std::vector<Position>> findPaths(); // намира всички пътища от Том до Джери
    void findPathsHelper(Position, Position, std::vector<Position>&, std::vector<std::vector<char>>, std::vector<std::vector<Position>>&);

    // вектор от пътища под формата на позиции --> вектор от пътища под формата на инструкции
    void convertToInstructions(const std::vector<std::vector<Position>>&, std::vector<std::queue<char>>&);

    // връща вектор само от най-късите пътища
    std::vector<std::vector<Position>> filterAllMinPaths(const std::vector<std::vector<Position>>&);

    // връща пътищата, при които се разлива най-много боя и се правят най-малко завои
    std::vector<std::queue<char>> MAXpaintMINturns();

    std::string queueTOstring(std::queue<char>) const;
    int countTurns(const std::string&) const;
    int countPaintedPlaces(const std::string&) const;
    int countPathLenght(const std::string&) const;

    void load(); // зарежда някои основни функционалности
    void userInput(int&, const int&, const int&) const; // грижи се за валидност на потребителския вход

public:
    void run(); // изпълнява всички функционалности на проекта
};

#endif