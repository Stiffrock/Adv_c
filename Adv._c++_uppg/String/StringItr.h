#pragma once
#include <iterator>

class StringItr : public std::iterator<std::bidirectional_iterator_tag, char>
{
	char* ptr;
public:
	StringItr() {};

	StringItr(char* p) : ptr(p) {};
	StringItr(const StringItr& rhs) { ptr = rhs.ptr; };
	~StringItr() {};
	
	StringItr& operator++() { ++ptr; return *this; }
	StringItr operator++(int) { StringItr tmp(*this); operator++(); return tmp; }
	StringItr& operator--(int) { StringItr tmp(*this); operator--(); return tmp; }
	StringItr operator--() { --ptr; return *this; }
	StringItr operator+(int x) { return ptr + x; }
	bool operator==(const StringItr& rhs) { return this->ptr == rhs.ptr; }
	bool operator!=(const StringItr& rhs) { return this->ptr != rhs.ptr; }
	char& operator*() { return *ptr; }
	bool operator<(const StringItr& rhs) { return ptr < rhs.ptr; }
	void operator=(const StringItr& rhs) { ptr = rhs.ptr; }
	int operator-(const StringItr& rhs) {	return ptr - rhs.ptr;}
	char& operator[](int x){return *(ptr+x);};
};

class ReverseStringItr : public std::iterator<std::bidirectional_iterator_tag, char>
{
	char* ptr;
public:

	ReverseStringItr() {};
	ReverseStringItr(char* p) : ptr(p) { };
	ReverseStringItr(const ReverseStringItr& rhs) { ptr = rhs.ptr; };
	~ReverseStringItr() {};
	ReverseStringItr& operator++() { --ptr; return *this; }
	ReverseStringItr operator++(int) { ReverseStringItr tmp(*this); operator++(); return tmp; }
	ReverseStringItr& operator--() { ++ptr; return *this; }
	ReverseStringItr operator+(const int x) { return ReverseStringItr(ptr + -x); }

	bool operator==(const ReverseStringItr& rhs) { return this->ptr == rhs.ptr; }
	bool operator!=(const ReverseStringItr& rhs) { return this->ptr != rhs.ptr; }
	char& operator*() { return *ptr; }
	bool operator<(ReverseStringItr rhs) { return ptr < rhs.ptr; }; // ????
	void operator=(const ReverseStringItr& rhs) { ptr = rhs.ptr; }
	int operator-(const ReverseStringItr& rhs){return -(ptr-rhs.ptr);}
	char& operator[](const int x){return *(ptr-x);};
};

