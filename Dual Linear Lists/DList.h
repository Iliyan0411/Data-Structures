#ifndef DLIST_H
#define DLIST_H
#include <iostream>


template <typename T>
class DList
{
private:
	struct Box
	{
		T data;
		Box* next, * prev;

		Box(const T& _data, Box* _next, Box* _prev) : 
			data(_data), next(_next), prev(_prev)
		{}
	};

public:
	class Iterator
	{
	private:
		Box* current;

	public:
		Iterator(Box* _current);

		T& operator * ();
		Iterator& operator ++ ();
		bool operator != (const Iterator& other);
	};

	Iterator begin();
	Iterator end();

private:
	Box* first, *last;
	
	void clear();
	void copy(const DList<T>& other);

	template <typename P>
	friend std::ostream& operator<< (std::ostream& out, const DList<P>& list);

public:
	DList(const DList<T>& other);
	DList();
	~DList();
	
	DList<T>& operator= (const DList<T>& other);
	DList<T>& operator+= (const DList<T>& other);
	T& operator[] (size_t i) const;

	size_t size() const;
	void push_back(const T& x);
	void push(const T& x);
	void reverse();
	void pop();
};

#include "DList.cpp"

#endif