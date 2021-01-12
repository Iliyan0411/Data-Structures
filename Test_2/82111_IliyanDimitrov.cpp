#include <iostream>
#include <vector>
#include <queue>
#include <map>


struct Node
{
    int data;
    Node *left, *right;

    Node(int _data, Node* _left, Node* _right) : data(_data), left(_left), right(_right) {}
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

struct charNode
{
    char data;
    charNode *left, *right;

    charNode(char _data, charNode* _left, charNode* _right) : data(_data), left(_left), right(_right)
    {
    }
    charNode(char _data) : data(_data), left(nullptr), right(nullptr) {}
};


// ex1
// помощна функция
void maxpathHelper(Node* t, int sum, std::vector<int>& maxSums)
{
    if(!t->left && !t->right)
    {
        maxSums.push_back(sum+t->data);
        return;
    }

    if(t->left && t->data < t->left->data) maxpathHelper(t->left, sum+t->data, maxSums);
    if(t->right && t->data < t->right->data) maxpathHelper(t->right, sum+t->data, maxSums);
}

int maxpath (Node *t)
{
    std::vector<int> maxSums;

    maxpathHelper(t, 0, maxSums);

    int max = maxSums[0];
    for(int i = 1; i < maxSums.size(); ++i)
    {
        if(maxSums[i] > max) max = maxSums[i];
    }

    return max;
}


// ex2
std::vector<int> average(Node* root)
{
    if(!root) return std::vector<int>();

    std::vector<int> result;
    std::queue<Node*> q;

    q.push(root);
    q.push(nullptr);

    int sum = 0, div = 0;

    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();

        if(curr == nullptr)
        {
            if(div == 0) break; // за да не зацикли програмата, въртейки в опашката един nullptr

            result.push_back(sum / div);
            q.push(nullptr);
            sum = 0;
            div = 0;
        }
        else
        {
            sum += curr->data;
            div++;
        }

        if(curr && curr->left) q.push(curr->left);
        if(curr && curr->right) q.push(curr->right);
    }

    return result;
}


// ex3
// добавя в words всички думи, които представляват път от корен до листо
void dfsWords(charNode* root, std::string currWord, std::vector<std::string>& words)
{
    if(!root)
    {
        words.push_back(currWord);
        return;
    }

    currWord += root->data;

    dfsWords(root->left, currWord, words);
    dfsWords(root->right, currWord, words);
}

// добавя в words всички думи, които се получават при обхождане по нива
void bfsWords(charNode* root, std::string currWord, std::vector<std::string>& words)
{
    std::queue<charNode*> q;

    q.push(root);
    q.push(nullptr);

    while(!q.empty())
    {
        charNode* curr = q.front();
        q.pop();

        if(curr == nullptr)
        {
            if(currWord == "") break; // за да не зацикли програмата, въртейки в опашката един nullptr
            
            words.push_back(currWord);
            currWord = "";
            q.push(nullptr);
        }
        else
        {
            currWord += curr->data;
        }

        if(curr && curr->left) q.push(curr->left);
        if(curr && curr->right) q.push(curr->right);
    }
}

std::string mostFrequent(charNode* root)
{
    if(!root) return std::string();

    std::vector<std::string> words;

    dfsWords(root, std::string(), words);
    bfsWords(root, std::string(), words);

    std::map<std::string, int> countWords;
    int max = -1;
    std::string result;

    for(std::string word : words)
    {
        if(!countWords.count(word)) 
        {
            countWords[word] = 0;
        }
        else 
        {
            countWords[word]++;
        }

        if(countWords[word] > max) result = word;
    }

    return result;
}


int main()
{
    // ----------------------------- ex1
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(1);
    // root->left->left = new Node(3);
    // root->right->right = new Node(8);
    // root->right->left = new Node(9);

    // std::cout << maxpath(root);


    // ----------------------------- ex2
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(5);
    // root->left->right = new Node(5);

    // for(int el : average(root))
    // {
    //     std::cout << el << " ";
    // }


    // ----------------------------- ex3
    // charNode* root = new charNode('c');
    // root->left = new charNode('a');
    // root->right = new charNode('a');
    // root->left->left = new charNode('c');
    // root->right->left = new charNode('a');
    // root->right->right = new charNode('c');

    // std::cout << mostFrequent(root) << std::endl;



    return 0;
}