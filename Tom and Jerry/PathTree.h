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
        int index; // всички върхове, които не са листа имат индекс -1

        node(const char& _data, const std::vector<node*> _instr) : data(_data), instr(_instr), index(-1) {}
    };
    node* root;

    void clear(node* curr); // изтрива дървото от паметта
    void addHelper(std::queue<char> c, node*& curr);
    void vizHelper(std::ostream& out, node* curr) const;
    void moveTo(const char& c, node*& curr); //придвижване на curr с една стъпка спрямо това какъв символ е 'c'
    void createLeafIndexHelper(node* curr);
    void wantedPathHelper(const int& id, node* curr, std::string& str) const;

    bool hasSymbolChild(const char& c, node* curr) const;
    bool isLeaf(node* curr) const;
    bool member(const int& id, node* curr) const; // проверява дали curr съдържа в поддървото си връх с индекс id

public:
    static int indexCounter; // статична променлива помагаща за индексиране на листата

    PTree();
    ~PTree();

    void add(const std::queue<char>& c);
    void viz(std::ostream& out) const; // отпечатва дървото в viz.dot
    void createLeafIndex(); // индексира листата от ляво на дясно
    
    std::string wantedPath(const int& id) const; // връща пътя от корена на дървото до листо с индекс 'id'
};



#endif