#ifndef __BSTREE__
#define __BSTREE__
#include<iostream>

class BSTree {
    struct BTreeNode {
        int data;
        BTreeNode* left;
        BTreeNode* right;
        int height;

        BTreeNode(const int& _data, BTreeNode* _left=nullptr, BTreeNode* _right=nullptr, int _height=0)
            : data{_data}, left{_left}, right{_right}, height{_height} {}
    };
    BTreeNode* root;

    void addHelper(const int&, BSTree::BTreeNode*&);
    bool memberHelper(const int&, const BSTree::BTreeNode*) const;
    void removeHelper(const int&, BSTree::BTreeNode*&);
    void printHelper(BSTree::BTreeNode*) const;
    void printDotHelp(std::ostream& , BSTree::BTreeNode*) const;
    BTreeNode* findMinInRightSubtree(BTreeNode*);
    int heightHelper (BSTree::BTreeNode*) const;
    int balance(const BSTree::BTreeNode*) const;
    void leftRotation(BSTree::BTreeNode*&);
    void rightRotation(BSTree::BTreeNode*&);

    public:
    BSTree(): root{nullptr} {}
    void add(const int&);
    void remove(const int&);
    void print() const;
    void printDot(std::ostream& out) const;
    bool member(const int&) const;
    bool empty() const;
    int height() const;
};

#endif