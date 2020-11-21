#include <iostream>
#include <stack>

template<class T>
struct Node
{
    T data;
    Node* next;

    Node(const T& _data, Node<T>* _next) : data(_data), next(_next){}
};

template<class T>
void pushBack(Node<T>*& l, const T& x)
{
    if(l == nullptr)
    {
        l = new Node<T>(x,nullptr);
        return;
    }

    Node<T>* curr = l;
    while(curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = new Node<T>(x,nullptr);
}

template<class T>
void printList(Node<T>* l)
{
    if(!l)
    {
        return;
    }

    Node<T>* curr = l;

    while(curr)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    }std::cout << std::endl;
}


//=====Problem 1
template<class T>
T reduce(Node<T>* L, T (*F)(const T&, const T&))
{
    if(L == nullptr)
    {
        throw "Empty list!\n";
    }
    if(L->next == nullptr)
    {
        return L->data;
    }

    return F(reduce(L->next,F),L->data);  
}

int sum(const int& a, const int& b)
{
    return a + b;
}


//=======Problem 2
template<class T>
Node<std::stack<T>>* equalize(Node<std::stack<T>>* l)
{
    if(l == nullptr)
    {
        return nullptr;
    }

    if(l->next == nullptr)
    {
        return l;
    }

    Node<std::stack<T>>* curr = l;
    while(curr->next != nullptr)
    {
        while(curr->data.size() >= curr->next->data.size())
        {
            curr->next->data.push(curr->data.top());
            curr->data.pop();
        }

        curr = curr->next;
    }

    return l;
}


//=====Problem 3
template<class T>
void shuffle(Node<T>*& L, int N)
{
    if(L == nullptr || L->next == nullptr)
    {
        return;
    }

    int counter = 0;
    Node<T>* curr = L;
    while(curr != nullptr)
    {
        if(counter < N/2)
        {
            curr = curr->next;
            counter++;
        }
        else if(counter == N/2)
        {
            Node<T>* save = curr;
            curr = curr->next;
            save->next = nullptr;
            counter++;
        }
        else
        {
            Node<T>* temp = curr;
            curr = curr->next;
            temp->next = L;
            L = temp;
            counter++;
        }
    }
}

int main()
{



    return 0;
}