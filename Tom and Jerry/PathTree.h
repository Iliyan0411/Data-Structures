#ifndef _PATH_TREE_H
#define _PATH_TREE_H
#include <iostream>
#include <vector>
#include <queue>
#include <string>


class PTree
{
private:
    struct node
    {
        char data{};
        std::vector<node*> instr{}; // възможните посоки, в които дронът може да завива
        int index; // всяко листо има уникален индекс. Останалите върхове са с индекс -1

        node(const char& _data, const std::vector<node*> _instr) : data(_data), instr(_instr), index(-1) {}
    };
    node* root;
    int numberOfLeaves;

    void addHelper(std::queue<char>, node*&);
    void vizHelper(std::ostream&, node*) const;
    void moveTo(const char&, node*&); // придвижва указателя според подадения символ
    void createLeafIndexHelper(node*, int&);
    void wantedPathHelper(const int&, node*, std::string&) const;
    void clearHelper(node*);

    bool hasSymbolChild(const char&, node*) const;
    bool isLeaf(node*) const;
    bool member(const int&, node*) const; // проверява дали даденият връх съдържа в поддървото си връх с конкретния индекс

public:
    PTree();
    ~PTree();

    void add(const std::queue<char>&);
    void viz(std::ostream&) const;
    void createLeafIndex(); // създава индекс на всяко листо
    void clear(); // освобождава динамичната памет
    void reset(); // зарежда дървото в началното му състояние(само с един връх)
    
    std::string wantedPath(const int&) const; // връща пътя от корена до исканото от потребителя листо под формата на низ

    int leavesNum() const; // връща броя на листата
};



#endif