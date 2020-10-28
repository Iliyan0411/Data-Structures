#ifndef DLIST_CPP
#define DLIST_CPP
#include "DList.h"
#include <iostream>
#include <cassert>
#include <exception>

template<typename T>
DList<T>::DList(const DList<T>& other)
{
	copy(other);
}

template<typename T>
DList<T>::DList()
{
	first = nullptr;
	last = nullptr;
}

template<typename T>
DList<T>::~DList()
{
	if(first != nullptr) clear();
}

template<typename T>
DList<T>& DList<T>::operator= (const DList<T>& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}

	return *this;
}

template<typename T>
DList<T>& DList<T>::operator+= (const DList<T>& other)
{
	if (other.first == nullptr) return *this;

	typename DList<T>::Box* crr = other.first;
	while (crr != nullptr)
	{
		push_back(crr->data);
		if (crr->next == nullptr) last = crr;
		crr = crr->next;
	}

	return *this;
}

template<typename T>
T& DList<T>::operator[] (size_t i) const
{
	assert(i < this->size());

	typename DList<T>::Box* crr = first;

	while (i > 0)
	{
		crr = crr->next;
		--i;
	}

	return crr->data;
}

template<typename T>
size_t DList<T>::size() const
{
	if (first == nullptr) return 0;

	size_t count = 0;
	typename DList<T>::Box* curr = first;

	while (curr != nullptr)
	{
		curr = curr->next;
		++count;
	}

	return count;
}

template<typename T>
std::ostream& operator<< (std::ostream& out, const DList<T>& list)
{
	typename DList<T>::Box* crr = list.first;

	while (crr != nullptr)
	{
		out << crr->data << " ";
		crr = crr->next;
	}

	return out;
}

template<typename T>
void DList<T>::clear()
{
	DList<T>::Box* crr = first, * save;

	while (crr != nullptr)
	{
		save = crr;
		crr = crr->next;
		delete save;
	}
}

template<typename T>
void DList<T>::copy(const DList<T>& other)
{
	clear();

	if (other.first == nullptr) return;

	typename DList<T>::Box* crr = other.first;
	for(size_t i = 0; i < other.size(); ++i)
	{
		this->push_back(crr->data);
		crr = crr->next;
	}
}

template<typename T>
void DList<T>::push_back(const T& x)
{
	if (first == nullptr)
	{
		first = new DList<T>::Box(x, first, nullptr);
		last = first;
		return;
	}

	typename DList<T>::Box* crr = first;

	while (crr->next != nullptr)
	{
		crr = crr->next;
	}

	crr->next = new DList<T>::Box(x, nullptr, crr);
	last = crr->next;
}

template<typename T>
void DList<T>::push(const T& x)
{
	first = new Box(x, first, nullptr);
	first->next->prev = first;
}

template<typename T>
void DList<T>::reverse()
{
	if (first == nullptr) return;

	for (size_t i = 0; i < this->size() / 2; ++i)
	{
		typename DList<T>::Box* crr1 = first, * crr2 = first;

		for (size_t j = 0; j < i; ++j)
		{
			crr1 = crr1->next;
		}
		for (size_t j = 0; j < this->size() - 1 - i; ++j)
		{
			crr2 = crr2->next;
		}

		T temp = crr1->data;
		crr1->data = crr2->data;
		crr2->data = temp;
	}
}

template<typename T>
void DList<T>::pop()
{
	if (first == nullptr) return;
	if (first == last) {
		delete first;
		first = nullptr;
		return;
	}
	
	typename DList<T>::Box* save = first;
	first = first->next;
	first->prev = nullptr;
	delete save;
}

template <class T>
DList<T>::Iterator::Iterator(Box* _current)
{
	current = _current;
}

template <class T>
T& DList<T>::Iterator::operator * ()
{
	if(current == nullptr) throw std::out_of_range("NULL Iterator");
	return current->data;
}

template <class T>
typename DList<T>::Iterator& DList<T>::Iterator::operator ++ ()
{
	if(current == nullptr) throw std::out_of_range("NULL Iterator");
	
	current = current->next;
	return *this;
}

template <class T>
bool DList<T>::Iterator::operator != (const Iterator& other)
{
	return current != other.current;
}

template<class T>
typename DList<T>::Iterator DList<T>::begin()
{
	return DList<T>::Iterator{ first };
}

template<class T>
typename DList<T>::Iterator DList<T>::end()
{
	return DList<T>::Iterator{ nullptr };
}

#endif