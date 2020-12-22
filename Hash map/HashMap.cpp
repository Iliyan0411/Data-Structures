#ifndef __HASMAP_CPP
#define __HASMAP_CPP

#include "HashMap.h"


template <class Keys, class Values>
HashMap<Keys,Values>::HashMap (std::function<size_t(const Keys&)> _h) : h(_h)
{
    size = 20;
    all = 0;
    table = new HashMap<Keys,Values>::Entry*[size];

    for (int i = 0; i < size; ++i)
    {
        table[i] = nullptr;
    }  
}

template <class Keys, class Values>
HashMap<Keys,Values>::HashMap()
{
    table = nullptr;
    all = 0;
    size = 0;
}

template <class Keys, class Values>
HashMap<Keys,Values>::HashMap(const HashMap<Keys,Values>& other) : h(other.h), size(other.size), all(other.all), table(other.table) 
{

}

template <class Keys, class Values>
HashMap<Keys,Values>::~HashMap()
{
    for(int i = 0; i < size; ++i)
    {
        HashMap<Keys,Values>::Entry* curr = nullptr;
        
        if(table[i]) HashMap<Keys,Values>::Entry* curr = table[i];

        while(curr)
        {
            HashMap<Keys,Values>::Entry* save = curr;
            curr = curr->next;
            delete save;
        }
    }

    delete[] table;
}

template <class Keys, class Values>
HashMap<Keys,Values>& HashMap<Keys,Values>::operator = (const HashMap<Keys,Values>& other)
{
    h = other.h;
    size = other.size;
    all = other.all;

    table = other.table;

    return *this;
}

template <class Keys, class Values>
typename HashMap<Keys,Values>::Entry* HashMap<Keys,Values>::locate (size_t index, const Keys &key) const
{
    typename HashMap<Keys,Values>::Entry *current = table[index];
    while (current != nullptr && current->key != key)
    {
        current = current->next;
    }

    return current;
}

template <class Keys, class Values>
Values HashMap<Keys,Values>::operator [](const Keys &key) const
{
    size_t index = h(key) % size;
    
    HashMap<Keys,Values>::Entry *kvpair = locate (index,key);
    assert (kvpair != nullptr);

    return kvpair->value;
}

template <class Keys, class Values>
Values& HashMap<Keys,Values>::operator [](const Keys &key)
{
    size_t index = h(key) % size;
    
    HashMap<Keys,Values>::Entry *kvpair = locate (index,key);

    if (kvpair != nullptr)
    {
        return kvpair->value;
    } 
    
    table[index] = new HashMap<Keys,Values>::Entry {key,Values(),table[index]};
    all++;
   
    return table[index]->value;
}

template <class Keys, class Values>
size_t HashMap<Keys,Values>::numElements() const
{
    return all;
}

template <class Keys, class Values>
size_t HashMap<Keys,Values>::coliding () const
{
    size_t counter = 0;

    for(size_t i = 0; i < size; ++i)
    {
       if(table[i])
       {
          HashMap<Keys,Values>::Entry* curr = table[i];
          curr = curr->next;

          while(curr)
          {
            counter++;
            curr = curr->next;
          } 
       }
    }

    return counter;
}

template <class Keys, class Values>
bool HashMap<Keys,Values>::hasKey(const Keys &key) const
{
    size_t index = h(key) % size;
    HashMap<Keys,Values>::Entry *kvpair = locate (index,key);

    return kvpair != nullptr;
}

template <class Keys, class Values>
double HashMap<Keys,Values>::efficiency() const
{
    return ((double)all - (double)coliding()) / (double)all;   
}

template <class Keys, class Values>
std::ostream& operator <<(std::ostream& out, const HashMap<Keys,Values>& hmap)
{
    for(Keys key : hmap)
    {
        out << key << '\t' << hmap[key] << std::endl;
    }

    return out;
}

template <class Keys, class Values>
HashMap<Keys,Values>::Iterator::Iterator(HashMap<Keys,Values>::Entry** _table, size_t _size) : table(_table), size(_size)
{
    currRow = 0;
    currCol = nullptr;

    if(!table)
    {
        return;
    }

    size_t i = 0;
    while(i < size && !table[i])
    {
        i++;
    }

    if(i < size)
    {
        currRow = i;
        currCol = table[i];
    }
}

template <class Keys, class Values>
Keys HashMap<Keys,Values>::Iterator::operator *() const
{
    assert(currCol);

    return currCol->key;
}

template <class Keys, class Values>
typename HashMap<Keys,Values>::Iterator& HashMap<Keys,Values>::Iterator::operator ++()
{
    assert(currCol);

    currCol = currCol->next;

    if(!currCol)
    {
        currRow++;

        while(currRow < size && !table[currRow])
        {
            currRow++;
        }
        if(currRow < size)
        {
            currCol = table[currRow];
        }
    }

    return *this;
}

template <class Keys, class Values>
bool HashMap<Keys,Values>::Iterator::operator !=(const HashMap<Keys,Values>::Iterator& other) const
{
    return currCol != other.currCol;
}

template <class Keys, class Values>
typename HashMap<Keys,Values>::Iterator HashMap<Keys,Values>::begin() const
{
    return HashMap<Keys,Values>::Iterator(table, size);
}

template <class Keys, class Values>
typename HashMap<Keys,Values>::Iterator HashMap<Keys,Values>::end() const
{
    return HashMap<Keys,Values>::Iterator(nullptr, size);
}


#endif
