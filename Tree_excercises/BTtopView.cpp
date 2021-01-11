#include <iostream>
#include <stack>
#include <optional>
#include <cmath>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
  
  Node(int _data, Node* _left, Node* _right) : data(_data), left(_left), right(_right) {}
  Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
  Node() : data(0), left(nullptr), right(nullptr) {}
};


void topView(Node * root) {
    if(!root) return;

    int minIndex = 0, maxIndex = 0;

    stack<pair<Node*,int>> s;
    s.push({root, 0});

    while(!s.empty())
    {
        auto top = s.top();
        s.pop();

        if(top.second < minIndex) 
        {
            cout << top.first->data << " ";
            minIndex--;
        }
        else if(top.second > maxIndex) 
        {
            cout << top.first->data << " ";
            maxIndex++;
        }
        else if(minIndex == maxIndex) cout << top.first->data << " ";

        if(top.first->right) s.push({top.first->right, top.second+1});
        if(top.first->left) s.push({top.first->left, top.second-1});
    }
}

bool continiousTree (Node* root)
{
    if(!root) return true;

    if(root->left && abs(root->data - root->left->data) > 1) return false;
    if(root->right && abs(root->data - root->right->data) > 1) return false;

    return continiousTree(root->left) && continiousTree(root->right);
}

int main()
{
    Node* root = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    // root->left->right->left = new Node(6);
    // root->left->right->left->left = new Node(7);
    // root->left->right->left->left->left = new Node(8);
    root->right = new Node(4);
    root->right->right = new Node(5);

    // topView(root);
    std::cout << continiousTree(root) << std::endl;


    return 0;
}