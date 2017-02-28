#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <iterator>
#include <vector>
#include <iostream>
#include <random>
#include <numeric>
#include <forward_list>


using namespace std;

template <class ForwardIterator>
void ForwardSort(ForwardIterator begin, ForwardIterator end)
{

	for (ForwardIterator i = begin; i != end; i++)
	{
		for (ForwardIterator j = begin; j != end; j++)
		{
			if (*i > *j)
			{
				iter_swap(i, j);
			}				
		}
	}
};


void VectorSort()
{
	vector<int> v(20);
	vector<int>::iterator itr;

	srand((unsigned)time(NULL));
	int r = rand();
	iota(begin(v), end(v), r);
	random_shuffle(begin(v), end(v));

	cout << "\nRandom Shuffle" << endl;
	for (itr = begin(v); itr != end(v); itr++)
	{
		cout << *itr << endl;
	}

	sort(begin(v), end(v));
	cout << "\nSorted" << endl;
	for (itr = begin(v); itr != end(v); itr++)
	{
		cout << *itr << endl;
	}

	sort(rbegin(v), rend(v));

	cout << "\nReverse Order" << endl;
	for (itr = begin(v); itr != end(v); itr++)
	{
		cout << *itr << endl;
	}
}

void ArraySort()
{
	int a[20]{ 0 };
	int* ptr;

	srand((unsigned)time(NULL));
	int r = rand();
	iota(begin(a), end(a), r);
	random_shuffle(begin(a), end(a));

	cout << "\nRandom Shuffle" << endl;
	for (ptr = begin(a); ptr != end(a); ptr++)
	{
		cout << *ptr << endl;
	}

	sort(begin(a), end(a));
	cout << "\nSorted" << endl;
	for (ptr = begin(a); ptr != end(a); ptr++)
	{
		cout << *ptr << endl;
	}

	sort(rbegin(a), rend(a), [](int x, int y) {return x < y; });
	cout << "\nReverse Order" << endl;
	for (ptr = begin(a); ptr != end(a); ptr++)
	{
		cout << *ptr << endl;
	}
}

void removeif()
{
	vector<int> v(20);
	vector<int>::iterator itr;

	srand((unsigned)time(NULL));
	int r = rand();
	iota(begin(v), end(v), r);
	random_shuffle(begin(v), end(v));

	for (itr = begin(v); itr != end(v); itr++)
	{
		cout << *itr << endl;
	}

	v.erase(remove_if(begin(v), end(v), [](int x) {return (x % 2) == 0; }), end(v));

	cout << "\nOdd numbers only" << endl;
	for (itr = begin(v); itr != end(v); itr++)
	{
		cout << *itr << endl;
	}	
}

void fsort()
{
	forward_list<int> list;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{		
		int r = rand();
		list.push_front(r);
	}

	forward_list<int>::iterator itr;
	cout << "\nUnsorted" << endl;
	for (itr = begin(list); itr != end(list); itr++)
	{
		cout << *itr << endl;
	}

	ForwardSort(begin(list), end(list));

	cout << "\nSorted with ForwardSort" << endl;
	for (itr = begin(list); itr != end(list); itr++)
	{
		cout << *itr << endl;
	}

	int x = 0;	
}



int main()
{
	//VectorSort();
	//ArraySort();
	//removeif();
	fsort();
	std::cin.get();
	return 0;
}