#include <iostream>
#include <string>
#include <vector>
#include <queue>


struct Node
{
    char data;
    Node *left, *right;

    Node(char _data) : data(_data), left(nullptr), right(nullptr) {}
    Node(char _data, Node* _left, Node* _right) : data(_data), left(_left), right(_right) {}
};


std::vector<std::string> getBFSwords (Node *root)
{
    std::vector<std::string> result;
    std::queue<Node*> bfsQueue;

    bfsQueue.push(root);
    bfsQueue.push(nullptr);

    std::string levelWord;
    while(!bfsQueue.empty())
    {
        Node* curr = bfsQueue.front();
        bfsQueue.pop();

        if(curr == nullptr)
        {
            if(levelWord == "") break;

            result.push_back(levelWord);
            bfsQueue.push(nullptr);
            levelWord = "";
        }
        else
        {
            levelWord += curr->data;

            if(curr->left) bfsQueue.push(curr->left);
            if(curr->right) bfsQueue.push(curr->right);
        }
    }

    return result;
}

void dfsHelper (Node* root, std::string currWord, std::vector<std::string>& result)
{
    if(!root) return;

    currWord += root->data;

    if(!root->left && !root->right)
    {
        result.push_back(currWord);
        return;
    }

    dfsHelper(root->left, currWord, result);
    dfsHelper(root->right, currWord, result);
}

std::vector<std::string> getDFSwords (Node* root)
{
    std::vector<std::string> result;

    dfsHelper(root, std::string(), result);

    return result;
}

void BFSeq_wordsDFS (Node* root)
{
    if(!root)
    {
        return;
    }

    std::vector<std::string> bfsWords = getBFSwords(root);
    std::vector<std::string> dfsWords = getDFSwords(root);

    for(auto bfsW : bfsWords)
    {
        for(auto dfsW : dfsWords)
        {
            if(bfsW == dfsW) std::cout << bfsW << std::endl;
        }
    }
}


int main()
{
    Node* root = new Node('a');
    root->left = new Node('b');
    root->left->left = new Node('c');
    root->left->right = new Node('d');
    root->left->right->left = new Node('e');
    root->left->right->left->left = new Node('f');
    root->left->right->left->left->left = new Node('g');
    root->right = new Node('h');

    BFSeq_wordsDFS(root);

    return 0;
}