#include <iostream>
#include <vector>
#include <fstream>
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


int max(const vector<int>& v)
{
    int max = v[0];
    
    for(int elem : v)
    {
        if(elem > max) max = elem;
    }
    
    return max;
}

void buildTree(Node*& curr, vector<int> currNums)
{
    if(currNums.size() == 0) 
    {
        curr = nullptr;
        return;
    }
    
    int maxNum = max(currNums);
    curr = new Node(maxNum, nullptr, nullptr);
    
    vector<int> left{}, right{};
    
    int i = 0;
    while(currNums[i] != maxNum)
    {
        left.push_back(currNums[i]);
        i++;
    }
    
    i = 0;
    while(currNums[i] != maxNum) i++;
    i++;

    while(i < currNums.size())
    {
        right.push_back(currNums[i]);
        i++;
    }

    buildTree(curr->left, left);
    buildTree(curr->right, right);
}

Node* constructMaximumBinaryTree(const vector<int>& nums) 
{
    if(nums.size() == 0) return nullptr;
    
    Node* root = nullptr;
    buildTree(root, nums);
    
    return root;
}

void printTree(Node* root, std::ostream& out)
{
    if(!root) return;

    printTree(root->left, out);
    printTree(root->right, out);


    out << (long)root << "[label=\"" << root->data << "\"]\n";
    
    if(root->left != nullptr)
    {
        out << (long)root << "->" << (long)root->left << "[color=red]"<< ";\n";
    }

    if(root->right != nullptr)
    {
        out << (long)root << "->" << (long)root->right << "[color=blue]"<< ";\n";
    }
}


int main()
{
    vector<int> v{3,2,1,6,0,5};

    Node* root = constructMaximumBinaryTree(v);

    std::ofstream out("mytree.dot");
    out << "digraph G{";
    printTree(root, out);
    out << "}";
    out.close();


    return 0;
}