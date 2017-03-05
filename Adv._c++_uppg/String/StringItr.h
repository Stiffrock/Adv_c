#pragma once
#include <iterator>
//template <typename T>
class StringItr : public std::iterator<std::forward_iterator_tag, char>
{
	char* ptr;
public:
	StringItr() {};

	StringItr(char* p) : ptr(p) {};
	StringItr(const StringItr& rhs) { ptr = rhs.ptr; };
	~StringItr() {};
	
	bool operator==(const StringItr& rhs){return this->ptr == rhs.ptr; }
	bool operator!=(const StringItr& rhs) { return this->ptr != rhs.ptr; }
	char& operator*() { return *ptr; }



	/*i++ will increment the value of i, but return the original value that i held before being incremented.*/
	StringItr& operator++() { ++ptr; return *this; }
	//"will increment the value of i, and then return the incremented value."
	StringItr operator++(int) { StringItr tmp(*this); operator++(); return tmp; }




	StringItr operator--(int) { StringItr tmp(*this); operator--(); return tmp; }
	StringItr operator--() { --ptr; return *this; }
	StringItr operator+(int x)
	{
		for (int i = 0; i < x; i++)
		{
			ptr++;
		}
		return ptr;
	}

	StringItr operator-(StringItr rhs) // ???? 
	{
		//rhs.ptr = ptr;
		//return ptr;
	}

	bool operator<(StringItr rhs) { return rhs.ptr < ptr; }; // ????

	char& operator[](int i)
	{
		return *(ptr + i);
	};

};

class ReverseStringItr : public std::iterator<std::forward_iterator_tag, char>
{
	char* ptr;
public:

	ReverseStringItr() {};
	ReverseStringItr(char* p) : ptr(p) {};
	ReverseStringItr(const ReverseStringItr& rhs) { ptr = rhs.ptr; };

	~ReverseStringItr() {};

	bool operator==(const ReverseStringItr& rhs) { return this->ptr == rhs.ptr; }
	bool operator!=(const ReverseStringItr& rhs) { return this->ptr != rhs.ptr; }
	char& operator*() { return *ptr; }


	ReverseStringItr& operator++() { --ptr; return *this; }
	ReverseStringItr operator++(int) { ReverseStringItr tmp(*this); operator--(); return tmp; }
	ReverseStringItr operator--() { --ptr; return *this; }
	ReverseStringItr operator+(int x) 
	{ 
		for (int i = 0; i < x; i++)
		{
			ptr--;
		}
		return ptr;
	}
};

