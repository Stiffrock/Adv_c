#include "String.h"
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <new>

//Sätter längden till 1 och initierar char array
String::String() 
{
	last = nullptr;
	length = 1;
	sdata = new char[length];
	sdata[length - 1] = '\0'; //inte säker på detta, den ska vara null terminated men är inte length +1 redan null..?
}


//if string is full length is equal to capacity


//Tar en sträng input och skapar en String utav det.
String::String(const char* cstr)
{
	length = strlen(cstr) + 1;
	sdata = new char[length];

	for (int i = 0; i < length; i++)
	{
		sdata[i] = cstr[i];
	}
	sdata[length - 1] = '\0';
}

//Copy constructor, skapar en ny char array med samma längd som förra
//kopierar över värdena
String::String(const String& rhs)
{
	length = rhs.length;
	sdata = new char[length];
	for (int i = 0; i < length - 1; i++)
	{
		sdata[i] = rhs.sdata[i];
	}
	sdata[length - 1] = '\0';
}

String::~String()
{
	delete[] sdata;
}


int String::size() const
{
	int i = 0;
	
	while (sdata[i] != '\0') //Har för mig han kommenterade detta, och att det inte var rätt sätt, kanske använda begin och end istället, men hur?
	{
		i++;
	}
	return i;
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
	catch (const std::exception&) // index out of range
	{
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
	return *this;
}

String& String::operator=(const String& rhs)
{
	length = rhs.length;
	char* ptr = new char[length];
	//sdata = new char[length];
	for (int i = 0; i < length; i++)
	{
		ptr[i] = rhs.sdata[i];
	}
	delete[] sdata;
	sdata = ptr;
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

//när du allokerar nytt minne kör dubbelt bara

void String::reserve(size_t n) //finns i STL, basic_string
{
	size_t newCapacity = length + n;
	//if (newCapacity > length)
	{
		char* ptr = new char[newCapacity];

		for (int i = 0; i < newCapacity; i++)
		{
			ptr[i] = sdata[i];
		}
		delete[] sdata;
		ptr[newCapacity - 1] = '\0';
		length = newCapacity;
		sdata = ptr;
	}
}

void String::resize(size_t n)
{
	int newLength = 0;
	newLength = n;

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

void String::push_back(char c)
{
	int tempLength = length;
	reserve(sizeof(char));

	sdata[tempLength - 1] = c;

}






