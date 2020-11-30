#include <iostream>
#include "DList.h"
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"


template <class T>
int count(const DList<T>& list, const T& x)
{
	int counter = 0;

	for (size_t i = 0; i < list.size(); ++i)
	{
		if (list[i] == x) counter++;
	}

	return counter;
}

template <class T>
void append(DList<T>& l1, const DList<T>& l2)
{
	for (size_t i = 0; i < l2.size(); ++i)
	{
		l1.push_back(l2[i]);
	}
}

TEST_CASE("Operators and push method")
{
	DList<int> l, l1;
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	l.push(3);
	l.push(2);
	l.push(1);

	CHECK(l[0] == 1);
	l[0] = 2;
	CHECK(l[0] == 2);
	l[0] = 1;

	l1.push_back(7);
	l1.push_back(8);
	l1.push_back(9);

	l += l1;
	for (int i = 0; i < 9; ++i)
	{
		CHECK(l[i] == i + 1);
	}
}

TEST_CASE("Count and Append")
{
	DList<int> l, l1;

	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	l.push(3);
	l.push(2);
	l.push(1);

	l1.push_back(7);
	l1.push_back(8);
	l1.push_back(9);

	CHECK(count<int>(l, 4) == 1);

	append<int>(l, l1);
	CHECK(l[0] == 1);
	CHECK(l[8] == 9);
}

TEST_CASE("Test Iterator")
{
	DList<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	DList<int>::Iterator it = l.begin();

	int i = 1;
	while (it != l.end())
	{
		CHECK(*it == i);
		++i;
		++it;
	}
	std::cout << std::endl;
	i = 1;

	for (int x : l)
	{
		CHECK(x == i);
		++i;
	}
	std::cout << std::endl;
}

int main()
{
	doctest::Context().run();



	return 0;
}