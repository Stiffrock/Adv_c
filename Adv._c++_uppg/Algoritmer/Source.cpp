#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <random>
#include <numeric>


using namespace std;


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



int main()
{
	//VectorSort();
	ArraySort();
	std::cin.get();
	return 0;
}