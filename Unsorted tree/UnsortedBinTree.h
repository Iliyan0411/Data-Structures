#ifndef UNSORTED_BIN_TREE_H
#define UNSORTED_BIN_TREE_H
#include <iostream>


template <class T>
class UnsBinTree
{
private:
    struct node
    {
        T data;
        node *left, *right;

        node(const T& _data, node* _left, node* _right):
            data(_data),left(_left),right(_right){}
    };
    node* root;

    void printHelp(std::ostream& out, UnsBinTree<T>::node* curr) const;
    void printDotHelp(std::ostream& out, UnsBinTree<T>::node* curr) const;
    
    bool memberHelp(const T& x, UnsBinTree<T>::node* curr) const;
    bool isLeaf(UnsBinTree<T>::node* nod) const;
    
    int heightHelp(UnsBinTree<T>::node* curr) const;
    int minPathToLeafHelp(UnsBinTree<T>::node* curr) const;
    int sizeHelp(UnsBinTree<T>::node* curr) const;
    int searchCountHelp(bool (*pred)(const T&), UnsBinTree<T>::node* curr) const;
    int countLeavesHelp(UnsBinTree<T>::node* curr) const;
    
    node* locate(const char* path) const;
    node* randLeaf(UnsBinTree<T>::node* curr) const;

    T maxElementHelp(UnsBinTree<T>::node* curr, T max) const;
    T minElementHelp(UnsBinTree<T>::node* curr, T min) const;
    T maxLeafHelp(UnsBinTree<T>::node* curr, T maxl) const;
    T minLeafHelp(UnsBinTree<T>::node* curr, T minl) const;

public:
    UnsBinTree();

    void add(const T& x, const char* path);
    void printAll(std::ostream& out) const;
    void printDot(std::ostream& out) const;
    void set(const T& x, const char* path);

    bool member(const T& x) const;

    int height() const;
    int minPathToLeaf() const;
    int size() const;
    int searchCount(bool (*pred)(const T&)) const;
    int countLeaves() const;

    T operator[](const char* path) const;
    T maxElement() const;
    T minElement() const;
    T maxLeaf() const;
    T minLeaf() const;
};

#include "UnsortedBinTree.cpp"
#endif
