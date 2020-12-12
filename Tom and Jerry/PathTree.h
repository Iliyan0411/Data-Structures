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

    void clear(node* curr);
    void addHelper(std::queue<char> c, node*& curr);
    void vizHelper(std::ostream& out, node* curr) const;
    void moveTo(const char& c, node*& curr);
    void createLeafIndexHelper(node* curr);
    void wantedPathHelper(const int& id, node* curr, std::string& str) const;

    bool hasSymbolChild(const char& c, node* curr) const;
    bool isLeaf(node* curr) const;
    bool member(const int& id, node* curr) const;

public:
    static int indexCounter;

    PTree();
    ~PTree();

    void add(const std::queue<char>& c);
    void viz(std::ostream& out) const;
    void createLeafIndex();
    
    std::string wantedPath(const int& id) const;
};



#endif