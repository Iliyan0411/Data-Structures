#include <iostream>

struct Interval
{
    int a, b;

    bool section (const Interval& other)
    {
        return (a >= other.a && a <= other.b) || 
                (b >= other.a && b <= other.b);
    }

    double avg() const
    {
        return (a + b) / 2;
    }
};

struct Node
{
    Interval data;
    Node* left, *right;

    Node(Interval _data, Node* _left, Node* _right) : data(_data), left(_left), right(_right) {}
    Node(Interval _data) : data(_data), left(nullptr), right(nullptr) {}
};


void insert(Node *&root, int a, int b)
{
    if(!root)
    {
        root = new Node({a,b});
        return;
    }

    if(root->data.avg() <= (Interval){a,b}.avg()) insert(root->left, a, b);
    else  insert(root->right, a, b);
}

bool hasSections(Node* root, Interval inter)
{
    return !root || 
            (root->data.section(inter) &&
            hasSections(root->left, inter) && hasSections(root->right, inter));
}

void findMaxHelper(Node* root, Node* mainRoot, Interval& result)
{
    if(!root) return;

    findMaxHelper(root->right, mainRoot, result);

    if(hasSections(mainRoot, root->data))
    {
        result.a = root->data.a;
        result.b = root->data.b;
        return;
    }

    findMaxHelper(root->left, mainRoot, result);
}

Interval findMax(Node* root)
{
    if(!root) return {0,0};

    bool nodeFinded = false;
    Interval result, temp;
    temp = result;

    findMaxHelper(root, root, result);

    if(temp.a != result.a || temp.b != result.b) return result;

    return {0,0};
}



int main()
{
    

    return 0;
}