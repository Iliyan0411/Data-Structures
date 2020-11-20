#include <iostream>
#include <stack>
#include <vector>

std::stack<int> mergeStacks(std::stack<int> s1, std::stack<int> s2)
{
    std::stack<int> s;

    while(!s1.empty() || !s2.empty())
    {
        if(s1.empty() && !s2.empty())
        {
            while(!s2.empty())
            {
                s.push(s2.top());
                s2.pop();
            }
        }
        else if(s2.empty() && !s1.empty())
        {
            while(!s1.empty())
            {
                s.push(s1.top());
                s1.pop();
            }
        }
        else
        {
            if(s1.top() > s2.top())
            {
                s.push(s1.top());
                s1.pop();
            }
            else
            {
                s.push(s2.top());
                s2.pop();
            }
        }
    }

    return s;
}

int stackFibb(unsigned int n)
{
    std::stack<int> s;
    
    s.push(0);
    if(n == 0)
    {
        return 0;
    }

    s.push(1);
    if(n == 1)
    {
        return 1;
    }

    while(n >= 1)
    {
        int b = s.top(); s.pop();
        int a = s.top(); s.pop();
        s.push(b);

        s.push(a+b);
        --n;
    }

    return s.top();
}

template<class T>
void printStack(std::stack<T> s)
{
    while(!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }std::cout << std::endl;
}

template<class T>
struct Node
{
    T data{};
    Node* next;

    Node(const T& _data, Node* _next = nullptr) : data(_data), next(_next){}
};

template<class T>
void pushBack(Node<T>*& first, const T& x)
{
    if(first == nullptr)
    {
        first = new Node<T>(x,nullptr);
        return;
    }

    Node<T>* curr = first;
    while(curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = new Node<T>(x,nullptr);
}

template<class T>
void print(Node<T>* first)
{
    if(!first)
    {
        return;
    }

    Node<T>* curr = first;
    while(curr)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

Node<int>* removeEven(Node<int>* first)
{
    if(first == nullptr)
    {
        return nullptr;
    }

    Node<int>* curr = first;
    std::vector<int> v;
    while(curr != nullptr)
    {
        if(curr->data % 2 != 0)
        {
            v.push_back(curr->data);
        }
        curr = curr->next;
    }

    Node<int>* l = nullptr;
    for(int x : v)
    {
        if(l == nullptr)
        {
            l = new Node<int>(x,nullptr);
            curr = l;
        }
        else
        {
            curr->next = new Node<int>(x,nullptr);
            curr = curr->next;
        }
    }

    return l;
}

template<class T>
Node<T>* reverse(Node<T>* first)
{
    if(first == nullptr)
    {
        return nullptr;
    }
    if(first->next == nullptr)
    {
        return first;
    }

    Node<T>* l = new Node<T>(first->data,nullptr);
    Node<T>* curr = first->next;

    while(curr != nullptr)
    {
        l = new Node<T>(curr->data, l);
        curr = curr->next;
    }

    return l;
}

int main()
{
    


    return 0;
}