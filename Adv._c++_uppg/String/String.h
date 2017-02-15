#pragma once
#include <cstdlib>
#include <new>
#include <iostream>
#include <iterator>

class String
{
private:
	char* sdata;
	char* last;
	int length;


public:
	String();
	String(const String& rhs);
	String(const char* cstr);
	~String();

	char& at(size_t i); //indexerar med range check (bounds checking?)
	const char* data() const; //gives a reference of the internal array holding string, it must also benull character terminated. (meaning that there must be an extra null character last in your array

	int size() const; //finns i STL, basic_string
	void reserve(size_t); //finns i STL, basic_string
	int capacity() const; //finns i STL, basic_string
	void shrink_to_fit(); //till skillnad från std så krävs här att utrymmet krymps maximalt så String tar så lite utrymme som möjligt
	void push_back(char c); // lagger till tecken sist
	void resize(size_t n); // Ändrar antalet tacken till n, om n > length så fylls det på med char()
	
	
	operator bool() {
		return sdata;
	};

	String& operator+=(const String& rhs); // tolkas som konkatenering
	String& operator+ (const char* cstr);
	String& operator=(const String& rhs);

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
			if (counter != 0)
			{
				return false;
			}
			return true;
		}
		else
		{
			return false;
		}	
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

