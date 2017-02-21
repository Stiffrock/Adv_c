#include "String.h"
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <new>
#include <exception>

//Sätter längden till 1 och initierar char array
String::String() 
{
	last = nullptr;
	length = 1;

	try
	{
		sdata = new char[length];
		sdata[length - 1] = '\0';
	}
	catch (const std::bad_alloc)
	{
		
	}
	
	Invariant();
}


//if string is full length is equal to capacity


//Tar en sträng input och skapar en String utav det.
String::String(const char* cstr)
{
	length = strlen(cstr) + 1; // *2

	try
	{
		sdata = new char[length];
		for (int i = 0; i < length; i++)
		{
			sdata[i] = cstr[i];
		}
		sdata[length - 1] = '\0';

	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	Invariant();
}

//Copy constructor, skapar en ny char array med samma längd som förra
//kopierar över värdena
String::String(const String& rhs)
{
	length = rhs.length;
	try
	{
		sdata = new char[length];
		for (int i = 0; i < length - 1; i++)
		{
			sdata[i] = rhs.sdata[i];
		}
		sdata[length - 1] = '\0';
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}	
	Invariant();
}

String::~String()
{
	delete[] sdata;
}


int String::size() const
{
	int i = 0;
	
	while (sdata[i] != '\0')
	{
		i++;
	}
	return i + 1;
}

char& String::at(size_t i) //indexerar med range check
{
	try
	{		
		if ((int)i - 1 < length)
		{
			return sdata[i - 1];
		}
	}
	catch (const std::exception& e) // index out of range?
	{
		std::cout << e.what();
		return sdata[0];
	}
}


String& String::operator+=(const String& rhs)
{
	int oldLength = length;
	int addLength = rhs.length + 1;

	reserve(addLength);
	for (int i = 0; i < rhs.length + 1; i++)
	{
		sdata[(oldLength - 1) + i] = rhs[i];
	}
	sdata[length - 1] = '\0';
	Invariant();
	return *this;
}

String& String::operator+ (const char* cstr)
{
	int oldLength = length;
	int addLength = strlen(cstr) + 1;

	reserve(addLength);

	for (int i = 0; i < strlen(cstr) + 1; i++)
	{
		sdata[(oldLength - 1) + i] = cstr[i];
	}
	sdata[length - 1] = '\0';
	Invariant();
	return *this;
}

String& String::operator=(const String& rhs)
{
	length = rhs.length;

	try
	{
		char* ptr = new char[length];
		for (int i = 0; i < length; i++)
		{
			ptr[i] = rhs.sdata[i];
		}

		delete[] sdata;
		sdata = ptr;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	Invariant();
	return *this;
}


const char* String::data() const 
{
	return sdata;
}

int String::capacity() const
{
	return length;

}

void String::resize(size_t n)
{
	int newLength = 0;
	newLength = n;

	try
	{
		if (length > newLength) //Gör arrayn mindre och ta bort de som är över
		{
			char* ptr = new char[newLength];

			for (int i = 0; i < newLength; i++)
			{
				ptr[i] = sdata[i]; //flyttar de object som får plats i den mindre listan från den gammla listan
			}
			delete[] sdata;
			length = newLength;
			ptr[newLength - 1] = '\0';
			sdata = ptr;
		}

		if (length < newLength)
		{
			int diff = newLength - length;
			reserve(diff);
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}


}

void String::shrink_to_fit()
{
	int minLength = 0;
	for (int i = 0; i < length; i++)
	{
		if (sdata[i] == '\0')
		{
			break; 
		}
		else
		{
			minLength++;
		}
	}
	minLength++;

	try
	{
		char* ptr = new char[minLength];
		for (int i = 0; i < minLength; i++)
		{
			ptr[i] = sdata[i];
		}

		delete[] sdata;
		ptr[minLength - 1] = '\0';
		length = minLength;
		sdata = ptr;
	}

	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	Invariant();
}

void String::push_back(char c)
{
	int currentSize = size(); // storleken på strängen
	int cap = capacity(); // mängen allokerat minne

	if (currentSize == cap) 
	{
		reserve(c);
	}

	sdata[currentSize - 1] = c; //dennna är sista 	
	sdata[currentSize] = '\0';
	Invariant();

}

//när du allokerar nytt minne kör dubbelt bara

void String::reserve(size_t n) //finns i STL, basic_string
{
	size_t newCapacity = (length * 2) + sizeof(n); // dubblera den nya containern
	
	try
	{
		char* ptr = new char[newCapacity]; // gör en pekare som pekar på den nya utökade containern
		ptr[newCapacity - 1] = '\0'; // nullterminera slutet på containern

		for (int i = 0; i < length; i++) // för över all nuvarande data
		{
			ptr[i] = sdata[i];
		}
		//ptr[length] = '\0'; // nullterminera slutet på containern
		length = newCapacity; // nya längden
		delete[] sdata; // ta bort den gammla datan
		sdata = ptr;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	
	Invariant();
}






