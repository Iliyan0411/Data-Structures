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
        std::vector<node*> instr{};
        int index;

        node(const char& _data, const std::vector<node*> _instr) : data(_data), instr(_instr), index(-1) {}
    };
    node* root;

    void addHelper(std::queue<char>, node*&);
    void vizHelper(std::ostream&, node*) const;
    void moveTo(const char&, node*&);
    void createLeafIndexHelper(node*);
    void wantedPathHelper(const int&, node*, std::string&) const;
    void clearHelper(node*);

    bool hasSymbolChild(const char&, node*) const;
    bool isLeaf(node*) const;
    bool member(const int&, node*) const;

public:
    static int indexCounter;

    PTree();
    ~PTree();

    void add(const std::queue<char>&);
    void viz(std::ostream&) const;
    void createLeafIndex();
    void clear();
    void reset();
    
    std::string wantedPath(const int&) const;
};



#endif