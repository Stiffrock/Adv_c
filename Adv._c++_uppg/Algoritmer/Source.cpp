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
bool Compare(ForwardIterator cmp1, ForwardIterator cmp2)
{
	return *cmp1 > *cmp2;
}


template <class ForwardIterator>
void ForwardSort(ForwardIterator begin, ForwardIterator end)
{
	ForwardIterator itr;
	ForwardIterator itr2;

	for (itr = begin; itr != end; itr++)
	{
		for (itr2 = begin; itr2 != end; itr2++)
		{
			ForwardIterator next = itr2++;
			Compare(itr2, next);
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

void Bubblesort()
{
	

	forward_list<int> list;
	srand((unsigned)time(NULL));
	int r = rand();
	for (int i = 0; i < 10; i++)
	{
		list.push_front(r);
	}

	ForwardSort(begin(list), end(list));


	int x = 0;
	
}



int main()
{
	//VectorSort();
	//ArraySort();
	//removeif();
	Bubblesort();
	std::cin.get();
	return 0;
}