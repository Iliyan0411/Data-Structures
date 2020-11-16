#ifndef UNSORTED_BIN_TREE_CPP
#define UNSORTED_BIN_TREE_CPP
#include "UnsortedBinTree.h"
#include <cassert>


template <class T>
UnsBinTree<T>::UnsBinTree()
{
    root = nullptr;
}

template <class T>
void UnsBinTree<T>::add(const T& x, const char* path)
{
    if(root == nullptr)
    {
        assert(path[0] == 0);
        root = new UnsBinTree<T>::node{x,nullptr,nullptr};
        return;
    }

    UnsBinTree<T>::node* curr = root;
    while(curr != nullptr && path[1] != 0)
    {
        if(path[0] == 'L')
        {
            curr = curr->left;
        }
        else if(path[0] == 'R')
        {
            curr = curr->right;
        }
        else
        {
            assert(false);
        }
        
        path++;
    }

    if(path[0] == 'L')
    {
        curr->left = new node{x,nullptr,nullptr};
    }
    else
    {
        curr->right = new node{x,nullptr,nullptr};
    }
    
}

template <class T>
void UnsBinTree<T>::printAll(std::ostream& out) const
{
    printHelp(out, root);
    out << std::endl;
}

template <class T>
void UnsBinTree<T>::printHelp(std::ostream& out, UnsBinTree<T>::node* curr) const
{
    if(curr == nullptr)
    {
        return;
    }

    printHelp(out, curr->left);
    out << curr->data << " ";
    printHelp(out, curr->right);
}

template <class T>
void UnsBinTree<T>::printDot(std::ostream& out) const
{
    out << "digraph G{\n";
    printDotHelp(out,root);
    out << "}";
}

template <class T>
void UnsBinTree<T>::printDotHelp(std::ostream& out, UnsBinTree<T>::node* curr) const
{
    if(curr == nullptr)
    {
        return;
    }

    printDotHelp(out,curr->left);

    out << (long)curr << "[label=\"" << curr->data << "\"]\n";
    
    if(curr->left != nullptr)
    {
        out << (long)curr << "->" << (long)curr->left << "[color=red]"<< ";\n";
    }

    if(curr->right != nullptr)
    {
        out << (long)curr << "->" << (long)curr->right << "[color=blue]"<< ";\n";
    }

    printDotHelp(out,curr->right); 
}

template <class T>
void UnsBinTree<T>::set(const T& x, const char* path)
{
    locate(path)->data = x;
}

template <class T>
bool UnsBinTree<T>::member(const T& x) const
{
    return memberHelp(x,root);
}

template <class T>
bool UnsBinTree<T>::memberHelp(const T& x, UnsBinTree<T>::node* curr) const
{
    return curr &&
        (curr->data == x ||
        memberHelp(x,curr->left)||
        memberHelp(x,curr->right));
}

template <class T>
int UnsBinTree<T>::height() const
{
    return heightHelp(root);
}

template <class T>
int UnsBinTree<T>::heightHelp(UnsBinTree<T>::node* curr) const
{
    if(curr == nullptr || (!curr->right && curr->left))
    {
        return 0;
    }

    return 1 + std::max(heightHelp(curr->left), heightHelp(curr->right));
}

template <class T>
T UnsBinTree<T>::operator[](const char* path) const
{
   return locate(path)->data;
}

template <class T>
T UnsBinTree<T>::maxElement() const
{
    return maxElementHelp(root, root->data);
}

template <class T>
T UnsBinTree<T>::maxElementHelp(UnsBinTree<T>::node* curr, T max) const
{
   if(curr == nullptr)
   {
       return max;
   }

   if(curr->data > max)
   {
       max = curr->data;
   }

    return std::max(maxElementHelp(curr->left, max), maxElementHelp(curr->right, max));
}

template <class T>
T UnsBinTree<T>::minElement() const
{
    return minElementHelp(root, root->data);
}

template <class T>
T UnsBinTree<T>::minElementHelp(UnsBinTree<T>::node* curr, T min) const
{
   if(curr == nullptr)
   {
       return min;
   }

   if(curr->data < min)
   {
       min = curr->data;
   }

    return std::min(minElementHelp(curr->left, min), minElementHelp(curr->right, min));
}

template <class T>
typename UnsBinTree<T>::node* UnsBinTree<T>::locate(const char* path) const
{
    assert(root != nullptr);

    if(path[0] == 0)
    {
        return root;
    }

    UnsBinTree<T>::node* curr = root;

    while(path[0] != 0)
    {
        if(path[0] == 'L')
        {
            curr = curr->left;
        }
        if(path[0] == 'R')
        {
            curr = curr->right;
        }
        
        assert(curr != nullptr);
        
        path++;
    }

    return curr;
}

template <class T>
int UnsBinTree<T>::minPathToLeaf() const
{
    return minPathToLeafHelp(root);
}

template <class T>
int UnsBinTree<T>::minPathToLeafHelp(UnsBinTree<T>::node* curr) const
{
    if(curr == nullptr || (!curr->right && !curr->left))
    {
        return 0;
    }
    
    return 1 + std::min(minPathToLeafHelp(curr->left), minPathToLeafHelp(curr->right));
}

#endif