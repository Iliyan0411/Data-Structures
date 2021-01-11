#include <iostream>

struct Node
{
    int data;
    Node* left, *mid, *right;

    Node(int _data, Node* _left, Node* _mid, Node* _right) : data(_data), left(_left), mid(_mid), right(_right) {}
    Node(int _data) : data(_data), left(nullptr), mid(nullptr), right(nullptr) {}
};

void insert(Node*& root, int x, unsigned int R)
{
    if(!root)
    {
        root = new Node(x);
        return;
    }

    if(x < (1-R) * x) insert(root->left, x, R);
    if(x == (1-R) * x) insert(root->mid, x, R);
    if(x > (1-R) * x) insert(root->right, x, R);
}

int main()
{



    return 0;
}