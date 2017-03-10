#pragma once
#include <cstdlib>
#include <new>
#include <iostream>
#include <iterator>
#include "StringItr.h"

class String
{
private:
	char* sdata;
	char* last;
	int length;
	int Size;

public:
	String();
	String(const String& rhs);
	String(const char* cstr);
	~String();

	typedef StringItr iterator;
	typedef ReverseStringItr reverse_iterator;
	typedef char value_type;
	typedef char& reference;
	typedef char* pointer;


	bool Invariant()
	{
		return sdata == nullptr || *sdata == *sdata;
	}

	char& at(size_t i);
	const char* data() const;

	iterator begin() { return sdata; }
	iterator end() { return sdata + Size; }

	///Enligt cpp reference st�r det att dom ska peka p� ligga en f�re men peka p� den efter
	///Hur g�r jag detta utan att �ndra i sj�lva containern d� jag har /0 i slutet
	///Jag t�nker mig att det �r den som f�rst�r f�r mig och att jag hade beh�vt flytta den i rbegin

	reverse_iterator rbegin() {
	 return sdata - 1 + Size; }
	reverse_iterator rend() { 
	return sdata - 1; }



	int size() const; 
	void reserve(size_t);
	int capacity() const;
	void shrink_to_fit();
	void push_back(char c);
	void resize(size_t n);

	friend std::ostream& operator<<(std::ostream& cout, const String& rhs)
	{
		for (size_t i = 0; i < rhs.Size; ++i)
			cout << rhs.sdata[i];
		return cout;
	}

	operator bool() {
		if (length == 1)
		{
			return false;
		}
		else
		{
			return sdata;
		}
	};

	String& operator+=(const String& rhs);
	String operator+ (const char* cstr);
	String& operator=(const String& rhs);
	String operator+ (const String& rhs);


	char& String::operator[](size_t i)
	{
		return *(sdata + i);
	}
	const char& String::operator[](size_t i) const
	{
		return *(sdata + i);
	}

	friend bool operator==(const String& lhs, const String& rhs)
	{

		int max_count = lhs.size();
		int counter = 0;
		int i = 0;
		while (i != max_count)
		{
			if (lhs.sdata[i] != rhs.sdata[i])
			{
				counter++;
			}
			i++;
		}
		if (counter != 0)
		{
			return false;
		}
		return true;

	}
	friend bool operator!=(const String& lhs, const String& rhs)
	{
		if (lhs.length == rhs.length)
		{
			int max_count = lhs.length;
			int counter = 0;
			int i = 0;
			while (i != max_count)
			{
				if (lhs.sdata[i] != rhs.sdata[i])
				{
					counter++;
				}
				i++;
			}
			if (counter > 0)
			{
				return true;
			}
			return false;
		}
		else
		{
			return true;
		}
	}
};

