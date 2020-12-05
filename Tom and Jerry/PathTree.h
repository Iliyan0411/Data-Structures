#ifndef _PATH_TREE_H
#define _PATH_TREE_H
#include <iostream>
#include <vector>
#include <queue>

class PTree
{
private:
    struct node
    {
        char data{};
        std::vector<node*> instr{}; // N S E W P

        node(const char& _data, const std::vector<node*> _instr) : data(_data), instr(_instr) {}
    };
    node* root;

    void clear(node* curr);
    void addHelper(std::queue<char> c, node*& curr);
    void printHelper(node* curr) const;
    void vizHelper(std::ostream& out, node* curr) const;
    void moveTo(const char& c, node*& curr);
    bool hasSymbolChild(const char& c, node* curr) const;
    bool hasChild(node* curr) const;

public:
    PTree();
    ~PTree();

    void add(const std::queue<char>& c);
    void viz(std::ostream& out) const;
};



#endif