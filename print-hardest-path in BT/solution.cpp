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
    vector<int> currPath, result;
    
<<<<<<< HEAD
    dfs(root, 0, max, currPath, result);
=======
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
        else if(i > 0 && sum > max){
                max = sum;
                maxIndex = i;
        }
    }
>>>>>>> e14504516572a0dc1ffb8a15a32f388b671b2139
    
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
