#include <iostream>
#include <vector>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
  
  Node(int _data, Node* _left=nullptr, Node* _right=nullptr) : data(_data), left(_left), right(_right) {}
};


void dfs(Node* curr, int sum, int& max, vector<int> currPath, vector<int>& result)
{
    if(!curr) return;
    
    sum += curr->data;
    currPath.push_back(curr->data);
    
    if(!curr->left && !curr->right && sum > max) result = currPath;
    if(sum > max) max = sum;
    
    dfs(curr->left, sum, max, currPath, result);
    dfs(curr->right, sum, max, currPath, result);
}

vector<int> hardestPath(Node* root)
{
    int max = root->data;
    vector<int> result;
    
    dfs(root, 0, max, vector<int>(), result);
    
    return result;
}


int main()
{
    Node *root = new Node(5, new Node(4, new Node(2, nullptr, nullptr), nullptr), new Node(7, new Node(8,nullptr,nullptr), 
                new Node(6, new Node(4,nullptr,nullptr), nullptr)));


    for(int elem : hardestPath(root))
    {
        std::cout << elem << " ";
    }


    return 0;
}