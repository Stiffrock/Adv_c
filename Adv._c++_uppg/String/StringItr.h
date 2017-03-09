#pragma once
#include <iterator>
//template <typename T>
class StringItr : public std::iterator<std::bidirectional_iterator_tag, char>
{
	char* ptr;
public:
	StringItr() {};

	StringItr(char* p) : ptr(p) {};
	StringItr(const StringItr& rhs) { ptr = rhs.ptr; };
	~StringItr() { /*ptr = nullptr*/ };

	bool operator==(const StringItr& rhs){return this->ptr == rhs.ptr; }
	bool operator!=(const StringItr& rhs) { return this->ptr != rhs.ptr; }
	char& operator*() { return *ptr; }
	StringItr& operator++() { ++ptr; return *this; }
	StringItr operator++(int) { StringItr tmp(*this); operator++(); return tmp; }
	StringItr& operator--(int) { StringItr tmp(*this); operator--(); return tmp; }
	StringItr operator--() { --ptr; return *this; }

	bool operator<(const StringItr& rhs) { return ptr < rhs.ptr; }

	StringItr operator+(int x)
	{ 
		StringItr p = ptr;
		for (int i = 0; i < x; i++)
		{ 
			p++; 
		} 
		return p;
	}
	
	void operator=(const StringItr& rhs) { ptr = rhs.ptr; }
	int operator-(const StringItr& rhs) 
	{
		int res = 0;
		for (StringItr begin = rhs.ptr; begin != ptr; begin++)
			res++;
		return res;
	}

	char& operator[](int x)
	{
		StringItr p = ptr;
		for (int i = 0; i < x; i++)
		{
			p++;
		}
		return *p;
	};
};

class ReverseStringItr : public std::iterator<std::bidirectional_iterator_tag, char>
{
	char* ptr;
public:

	ReverseStringItr() {};

	ReverseStringItr(char* p) : ptr(p) { p++; };
	ReverseStringItr(const ReverseStringItr& rhs) { ptr = rhs.ptr; };
	~ReverseStringItr() {};

	bool operator==(const ReverseStringItr& rhs) { return this->ptr == rhs.ptr; }
	bool operator!=(const ReverseStringItr& rhs) { return this->ptr != rhs.ptr; }
	char& operator*() { return *ptr; }

	ReverseStringItr& operator++() { --ptr; return *this; }
	ReverseStringItr operator++(int) {ReverseStringItr tmp(*this); operator--(); return tmp; }
	ReverseStringItr& operator--() { --ptr; return *this; }
	//ReverseStringItr operator--(int) { ReverseStringItr tmp(*this); operator--(); return tmp; }


	bool operator<(ReverseStringItr rhs) { return ptr < rhs.ptr; }; // ????
	void operator=(const ReverseStringItr& rhs) { ptr = rhs.ptr; }

	int operator-(const ReverseStringItr& rhs)
	{
		int res = 0;
		for (ReverseStringItr begin = rhs.ptr; begin != ptr; --begin)
			res++;
		return res;
	}

	ReverseStringItr operator+(const int x) 
	{ 
		ReverseStringItr p = ptr;
		for (int i = 0; i < x; i++)
		{
			--p;
		}
		return p;
	}
	char& operator[](const int x)
	{
		StringItr p = ptr;
		for (int i = 0; i < x; i++)
		{
			--p;
		}
		return *p;
	};
};

