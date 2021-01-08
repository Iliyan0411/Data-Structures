#include <iostream>
#include <string>
#include <vector>

struct Node
{
    int data;
    Node* left, *right;

    Node(int _data, Node* _left, Node* _right) : data(_data), left(_left), right(_right) {}
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

bool mirror (Node* t1, Node* t2)
{
    if(!t1 && !t2) return true;

    return (t1 && t2) &&
            t1->data == t2->data &&
            mirror(t1->left, t2->right) &&
            mirror(t1->right, t2->left);
}

void helper(Node* root, std::string currTrace, std::string& result, int x)
{
    if(!root) return;

    if(root->data == x)
    {
        result = currTrace;
        return;
    }

    helper(root->left, currTrace + "L", result, x);
    helper(root->right, currTrace + "R", result, x);
}

std::string findTrace (Node* root, int x)
{
    if(!root) return "_";

    std::string result;
    helper(root, "", result, x);

    if(result.size() == 0) return "_";

    return result;
}

void dfs(Node* root, std::vector<int>& nodes)
{
    if(!root) return;

    dfs(root->left, nodes);

    nodes.push_back(root->data);

    dfs(root->right, nodes);
}

int getAt(Node* root, int i)
{
    std::vector<int> nodes;
    dfs(root, nodes);

    if(i < 0 || i >= nodes.size()) return -1;

    return nodes[i];
}


int main()
{
    Node* root = new Node(5);
    root->left = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->left->left = new Node(10);
    root->left->right->left->left->left = new Node(0);
    root->right = new Node(1);

    // Node* root1 = new Node('a');
    // root1->right = new Node('b');
    // root1->right->right = new Node('c');
    // root1->right->left = new Node('d');
    // root1->right->left->right = new Node('e');
    // root1->right->left->right->right = new Node('f');
    // root1->right->left->right->right->right = new Node('g');
    // root1->left = new Node('h');

    // std::cout << mirror(root, root1);
    // std::cout << findTrace(root, 10);
    // for(int i = 0; i < 8; ++i)
    //     std::cout << getAt(root, i) << " ";

    
    return 0;
}