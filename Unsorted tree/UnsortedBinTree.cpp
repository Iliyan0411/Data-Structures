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
bool UnsBinTree<T>::isLeaf(UnsBinTree<T>::node* nod) const
{
    return !nod->left && !nod->right;
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
T UnsBinTree<T>::maxLeaf() const
{
    T smax = randLeaf(root)->data;

    return maxLeafHelp(root,smax);
}

template <class T>
T UnsBinTree<T>::maxLeafHelp(UnsBinTree<T>::node* curr, T maxl) const
{
    if(!curr)
    {
        return maxl;
    }

    if(isLeaf(curr) && curr->data > maxl)
    {
        maxl = curr->data;
    }

    return std::max(maxLeafHelp(curr->left, maxl), maxLeafHelp(curr->right, maxl));
}

template <class T>
T UnsBinTree<T>::minLeaf() const
{
    T smin = randLeaf(root)->data;

    return minLeafHelp(root, smin);
}

template <class T>
T UnsBinTree<T>::minLeafHelp(UnsBinTree<T>::node* curr, T minl) const
{
    if(!curr)
    {
        return minl;
    }

    if(isLeaf(curr) && curr->data < minl)
    {
        minl = curr->data;
    }

    return std::min(minLeafHelp(curr->left, minl), minLeafHelp(curr->right, minl));
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
typename UnsBinTree<T>::node* UnsBinTree<T>::randLeaf(UnsBinTree<T>::node* curr) const
{
    assert(curr);

    if(curr->left) 
    {
        return randLeaf(curr->left);
    }
    if(curr->right) 
    {
        return randLeaf(curr->right);
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

template <class T>
int UnsBinTree<T>::size() const
{
    return sizeHelp(root);
}

template <class T>
int UnsBinTree<T>::sizeHelp(UnsBinTree<T>::node* curr) const
{
    if(curr == nullptr)
    {
        return 0;
    }

    return 1 + sizeHelp(curr->left) + sizeHelp(curr->right);
}

template <class T>
int UnsBinTree<T>::searchCount(bool (*pred)(const T&)) const
{
    return searchCountHelp(pred, root);
}

template <class T>
int UnsBinTree<T>::searchCountHelp(bool (*pred)(const T&), UnsBinTree<T>::node* curr) const
{
    if(curr == nullptr || (!pred(curr->data) && curr != root))
    {
        return 0;
    }
    return 1 + searchCountHelp(pred, curr->left) + searchCountHelp(pred, curr->right); 
}

template <class T>
int UnsBinTree<T>::countLeaves() const
{
    return countLeavesHelp(root);
}

template <class T>
int UnsBinTree<T>::countLeavesHelp(UnsBinTree<T>::node* curr) const
{
   if(!curr)
   {
       return 0;
   }
   if(!curr->left && !curr->right)
   {
       return 1 + countLeavesHelp(curr->left) + countLeavesHelp(curr->right);
   }

   return countLeavesHelp(curr->left) + countLeavesHelp(curr->right);
}

#endif