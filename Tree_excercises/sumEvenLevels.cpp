#include <iostream>

struct Node
{
    int data;
    Node* left, *right;

    Node(int _data, Node* _left, Node* _right) : data(_data), left(_left), right(_right) {}
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

int helper(Node* root, int lvl)
{
    if (!root) return 0;

    if (lvl % 2 == 0 && root->left && !root->right)
    {
        return root->data + helper(root->left, lvl+1);
    }
    
    return helper(root->left, lvl+1) + helper(root->right, lvl+1);
}

int sumEvenLevel(Node* root)
{
    if(!root) return 0;

    return helper(root, 0); 
}


int main()
{
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->right->right = new Node(2);
    root->right->right->left = new Node(3);
    root->left->left = new Node(6);
    root->left->right = new Node(1);
    root->left->left->left = new Node(7);

    std::cout << sumEvenLevel(root) << std::endl;

    return 0;
}