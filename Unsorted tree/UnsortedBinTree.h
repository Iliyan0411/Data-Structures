#ifndef UNSORTED_BIN_TREE_H
#define UNSORTED_BIN_TREE_H


template <class T>
class UnsBinTree
{
private:
    struct node
    {
        T data;
        node* left, right;

        node(const T& _data, node* _left, node* _right);
    };
    node* root;

public:
    UnsBinTree();

    void add(const T& x, char* path);
};

#endif
