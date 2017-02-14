#pragma once
#include <cstdlib>
#include <new>
#include <iostream>
#include <iterator>

class String
{
private:
	char* data;
	char* last;
	int length;


public:
	String();
	String(const String& rhs);
	String(const char* cstr);
	~String();

	char& at(size_t i); //indexerar med range check (bounds checking?)
	const char* Data() const; //gives a reference of the internal array holding string, it must also benull character terminated. (meaning that there must be an extra null character last in your array

	int size() const; //finns i STL, basic_string
	void reserve(size_t); //finns i STL, basic_string
	int capacity() const; //finns i STL, basic_string
	void shrink_to_fit(); //till skillnad från std så krävs här att utrymmet krymps maximalt så String tar så lite utrymme som möjligt
	void push_back(char c); // lagger till tecken sist
	void resize(size_t n); // Ändrar antalet tacken till n, om n > length så fylls det på med char()
	
	

	String& operator+=(const String& rhs); // tolkas som konkatenering
	//{
	//	int oldLength = length;
	//	int addLength = rhs.length + 1;

	//	reserve(addLength);
	//	for (int i = 0; i < rhs.length + 1; i++)
	//	{
	//		data[(oldLength - 1) + i] = rhs[i];
	//	}
	//	data[length - 1] = '\0';

	//	return *this;

	//}

	String& operator+ (const char* cstr)
	{
		int oldLength = length;
		int addLength =  strlen(cstr) + 1 ;
		
		reserve(addLength);
		for (int i = 0; i < strlen(cstr) + 1; i++)
		{
			data[(oldLength - 1) + i] = cstr[i];
		}
		data[length - 1] = '\0';


		/*int oldLength = length;
		int newLength = length + cstr;
		reserve(newLength);

		for (int i = 1; i <  - 1; i++)
		{
			data[oldLength + i] = rhs.data[i];
		}
		data[length - 1] = '\0';*/
		
		return *this;
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
				if (lhs.data[i] != rhs.data[i])
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
				if (lhs.data[i] != rhs.data[i])
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

	char& String::operator[](size_t i)
	{
		return *(data + i);
	}
	const char& String::operator[](size_t i) const
	{
		return *(data + i);
	}
	String& String::operator=(const String& rhs)
	{
		length = rhs.length;
		delete[] data;
		//data = new char[length];
		for (int i = 0; i < length; i++)
		{
			data[i] = rhs.data[i];
		}
		return *this;
	
	}
};

