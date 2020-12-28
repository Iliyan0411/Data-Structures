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



void dfs(Node* curr, int sum, int& max, vector<int> currPath, vector<vector<int>>& allPaths)
{
    if(!curr)
    {
        return;
    }
    
    sum += curr->data;
    currPath.push_back(curr->data);
    
    if(!curr->left && !curr->right && sum > max)
    {
        allPaths.push_back(currPath);
    }
    
    if(sum > max) max = sum;
    
    
    dfs(curr->left, sum, max, currPath, allPaths);
    dfs(curr->right, sum, max, currPath, allPaths);
}

vector<vector<int>> hardestPath(Node* root)
{
    int max = root->data;
    vector<int> currPath;
    vector<vector<int>> allPaths;
    
    dfs(root, 0, max, currPath, allPaths);
    
    return allPaths;
}

void printHardestPath(vector<vector<int>> allPaths)
{
    int max = 0, maxIndex = 0;
    
    for(int i = 0; i < allPaths.size(); ++i)
    {
        int sum = 0;
        for(int j = 0; j < allPaths[i].size(); ++j)
        {
            sum += allPaths[i][j];
        }
        if(i == 0){
            maxIndex = i;
            max = sum;
        }
        else{
            if(sum > max){
                max = sum;
                maxIndex = i;
            }
        }
    }
    
    for(int elem : allPaths[maxIndex])
    {
        cout << elem << " ";
    }
}


int main()
{
    Node *root = new Node(5, new Node(4, new Node(2, nullptr, nullptr), nullptr), new Node(7, new Node(8,nullptr,nullptr), 
                new Node(6, new Node(4,nullptr,nullptr), nullptr)));

    printHardestPath(hardestPath(root));



    return 0;
}