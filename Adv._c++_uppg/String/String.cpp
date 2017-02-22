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
	sdata = new char[1];
	length = 1;
	sdata[length - 1] = '\0'; //inte säker på detta, den ska vara null terminated men är inte length +1 redan null..?
	Size = 0;
	Invariant();
}


//if string is full length is equal to capacity


//Tar en sträng input och skapar en String utav det.
String::String(const char* cstr)
{
	int newLength = strlen(cstr) + 1;
	sdata = new char[newLength];
	length = newLength;
	Size = newLength - 1; 

	for (int i = 0; i < length; i++)
	{
		sdata[i] = cstr[i];

	}
	sdata[length - 1] = '\0';
	
	Invariant();
}

//Copy constructor, skapar en ny char array med samma längd som förra
//kopierar över värdena
String::String(const String& rhs)
{
	int newLength = rhs.length;
	sdata = new char[newLength];
	length = newLength;
	Size = newLength - 1;

	for (int i = 0; i < length - 1; i++)
	{
		sdata[i] = rhs.sdata[i];
	}
	sdata[length - 1] = '\0';
	last = &sdata[length - 1];
	Invariant();

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
	return i + 1;
}

char& String::at(size_t i) //indexerar med range check
{		

	if ((int)i - 1 <= Size)
	{
		return sdata[i - 1];
	}
	
	throw std::out_of_range("Error");

//	return sdata[0]
	
}


String& String::operator+=(const String& rhs)
{
	int oldLength = length;
	int addLength = rhs.length - 1;

	reserve(oldLength + addLength);

	for (int i = 0; i < rhs.length - 1; i++)
	{
		sdata[(oldLength - 1) + i] = rhs[i];
	}
	sdata[length - 1] = '\0';

	Size += rhs.Size;
	length = oldLength + addLength;
	Invariant();
	return *this;
}
String String::operator+ (const String& rhs)
{
	String newString = String();

	newString += *this;
	newString += String(rhs.sdata);

	return newString;
}

String String::operator+ (const char* cstr)
{
	String newString = String();
	
	newString += *this;
	newString += String(cstr);

	return newString;
}

String& String::operator=(const String& rhs)
{
	int newLength = rhs.length;
	char* ptr = new char[newLength];
	length = newLength;

	for (int i = 0; i < length; i++)
	{
		ptr[i] = rhs.sdata[i];
	}
	Size = rhs.Size;
	delete[] sdata;
	sdata = ptr;

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
	Invariant();
}

void String::push_back(char c)
{
//	int currentSize = size(); // storleken på strängen
	int currentSize = Size + 1;
	int cap = capacity(); // mängen allokerat minne

	if (currentSize == cap) 
	{
		reserve((cap*2) + 1);
	}

	sdata[currentSize - 1] = c; //dennna är sista 
	Size++;
	sdata[currentSize] = '\0';
	Invariant();

}

//när du allokerar nytt minne kör dubbelt bara

void String::reserve(size_t n) //finns i STL, basic_string
{
	//size_t newCapacity = (length * 2) + sizeof(n); // dubblera den nya containern

	int newCap = n;
	char* ptr = new char[newCap]; // gör en pekare som pekar på den nya utökade containern
	ptr[newCap - 1] = '\0'; // nullterminera slutet på containern

	for (int i = 0; i < length; i++) // för över all nuvarande data
	{
		ptr[i] = sdata[i];
	}

	length = newCap; // nya längden
	delete[] sdata; // ta bort den gammla datan
	sdata = ptr; 	
	Invariant();

}






