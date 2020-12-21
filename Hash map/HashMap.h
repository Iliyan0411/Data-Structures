#ifndef __HASMAP_H
#define __HASMAP_H

#include <functional>

template <class Keys, class Values>
class HashMap
{
private:

    struct Entry
    {
        Keys key;
        Values value;
        Entry *next;
    };

    Entry **table;
    size_t size;
    std::function<size_t(const Keys&)> h{};

    Entry *locate (size_t, const Keys&) const;


public:
    HashMap (std::function<size_t(const Keys&)>);
    HashMap();
    HashMap(const HashMap<Keys,Values>& other);
    ~HashMap();

    HashMap& operator = (const HashMap<Keys,Values>& other);
    Values operator [](const Keys&) const;
    Values& operator [](const Keys&);
    bool hasKey(const Keys&) const;
    int numElements() const;


    class Iterator
    {
    public:
        Iterator(Entry**, size_t);

        Keys operator *() const;
        Iterator& operator ++();
        bool operator !=(const Iterator&) const;

    private:
        size_t size;
        Entry** table;

        Entry* currCol;
        size_t currRow;
    };

    Iterator begin() const;
    Iterator end() const;
};

#endif
#include "HashMap.cpp"
