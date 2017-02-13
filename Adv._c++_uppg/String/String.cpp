#include "String.h"
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <new>

//S�tter l�ngden till 1 och initierar char array
String::String() 
{
	last = nullptr;
	length = 1;
	data = new char[length];
	data[length - 1] = '\0'; //inte s�ker p� detta, den ska vara null terminated men �r inte length +1 redan null..?
}

//Tar en str�ng input och skapar en String utav det.
String::String(const char* cstr)
{
	length = strlen(cstr) + 1;
	data = new char[length];

	for (int i = 0; i < length; i++)
	{
		data[i] = cstr[i];
	}
	data[length - 1] = '\0';
}

//Copy constructor, skapar en ny char array med samma l�ngd som f�rra
//kopierar �ver v�rdena
String::String(const String& rhs)
{
	length = rhs.length;
	data = new char[length];
	for (int i = 0; i < length - 1; i++)
	{
		data[i] = rhs.data[i];
	}
	data[length - 1] = '\0';
}

String::~String()
{
	delete[] data;
}



int String::size() const
{
	int i = 0;
	
	while (data[i] != '\0') //Har f�r mig han kommenterade detta, och att det inte var r�tt s�tt, kanske anv�nda begin och end ist�llet, men hur?
	{
		i++;
	}
	return i;
}

char& String::at(size_t i) //indexerar med range check
{
	try
	{		
		if (i - 1 < length)
		{
			return data[i - 1];
		}
	}
	catch (const std::exception&) // index out of range
	{
		return data[0];
	}
	

}

const char* String::Data() const 
{
	return data;
}

int String::capacity() const
{
	return length;
}
void String::reserve(size_t n) //finns i STL, basic_string
{
	size_t newCapacity = length + n;
	//if (newCapacity > length)
	{
		char* ptr = new char[newCapacity];

		for (int i = 0; i < newCapacity; i++)
		{
			ptr[i] = data[i];
		}
		//ptr[newCapacity - 1] = '\0';
		delete[] data;
		length = newCapacity;
		data = ptr;
	}
}


