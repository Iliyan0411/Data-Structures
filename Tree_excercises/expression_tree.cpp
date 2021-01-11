#include <iostream>
#include <vector>
#include <cassert>
#include <stack>


struct Node
{
  char data;
  Node* left;
  Node* right;
  
  Node(char _data, Node* _left, Node* _right) : data(_data), left(_left), right(_right) {}
  Node(char _data) : data(_data), left(nullptr), right(nullptr) {}
};

bool isNum(char c)
{
    return c >= '0' && c <= '9';
}

bool isOper(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void createExpr(Node* root, std::vector<char>& expression)
{
    if(!root) return;

    if(isNum(root->data) && (root->left || root->right)) assert(false);
    if(isOper(root->data) && (!root->left || !root->right)) assert(false);
 
    expression.push_back(root->data);

    createExpr(root->left, expression);
    createExpr(root->right, expression);
}

int operate(int a, int b, char c)
{
    switch(c)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

int toDigit(char c)
{
    return (int)(c - '0');
} 

int evaluete(Node* root)
{
    if(!root) return 0;

    std::vector<char> expression;

    createExpr(root, expression);

    for(int i = 0; i < expression.size() / 2; i++)
    {
        std::swap(expression[i], expression[expression.size() - i - 1]);
    }

    std::stack<int> symbols;
    for(char c : expression)
    {
        if(isNum(c)) symbols.push(toDigit(c));
        else if(isOper(c))
        {
            int a = symbols.top(); symbols.pop();
            int b = symbols.top(); symbols.pop();
            symbols.push(operate(a,b,c));
        }
        else assert(false);
    }

    assert(!symbols.empty());
    return symbols.top();
}

int main()
{
    Node* root = new Node('+');
    root->left = new Node('*');
    root->right = new Node('-');
    root->left->left = new Node('5');
    root->left->right = new Node('4');
    root->right->left = new Node('1');
    root->right->right = new Node('2');

    std::cout << evaluete(root) << std::endl;



    return 0;
}