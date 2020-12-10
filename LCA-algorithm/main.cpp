#include <iostream>

struct node
{
public:
    int data;
    node *left, *right;

    node(const int& _data, node* _left, node* _right) : data(_data), left(_left), right(_right) {}
    node() : data(0), left(nullptr), right(nullptr) {}
};


node* LCA_ordered_tree(node* root, int m, int n)
{
    if(root->data == m || root->data == n || !root) return root;

    if(m < root->data && n < root->data) return LCA_ordered_tree(root->left, m, n);
    if(m > root->data && n > root->data) return LCA_ordered_tree(root->right, m, n);

    return root;
}

node* LCA_not_ordered_tree(node* root, int m, int n)
{
    if(!root || root->data == m || root->data == n) return root;
        
    node* left = LCA_not_ordered_tree(root->left, m, n);
    node* right = LCA_not_ordered_tree(root->right, m, n);
   
    if(left && right) return root;
    
    if(left) return left;

    return right;
}

int main()
{
    node* root = new node(10,
                    new node(5,
                    new node(2,nullptr,nullptr), 
                    new node(7,nullptr,nullptr)),
                    new node(15,nullptr,nullptr));

    std::cout << LCA_ordered_tree(root, 2, 15)->data << std::endl;
    std::cout << LCA_not_ordered_tree(root, 2, 5)->data << std::endl;


    return 0;
}