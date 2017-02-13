#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <iterator>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

using namespace std;

//int nrOfChars = 0;
//char* newArray;

int Count(const char* str, const char* searchFor)
{
	const char * strPtr = str;
	const char * sfPtr = searchFor;
	int nrToReplace = 0;
	int sfCount = 0;

	if (strlen(searchFor) > 0)
	{
		for (; sizeof(sfPtr) < *sfPtr; sfPtr++)
			sfCount++;

		for (; sizeof(strPtr) < *strPtr;)
		{
			int hitCounter = 0;
			sfPtr = searchFor;

			for (; sizeof(sfPtr) < *sfPtr;)
			{
				if (*sfPtr == *strPtr)
					hitCounter++;

				strPtr++;
				sfPtr++;

				if (hitCounter == sfCount)
				{
					nrToReplace++;
					hitCounter = 0;
					sfPtr = searchFor;
				}

			}
		}
	}
	else
	{
		return 0;
	}

	/*for (; sizeof(sfPtr) < *sfPtr; sfPtr++)
	sfCount++;

	for (; sizeof(strPtr) < *strPtr;)
	{
	int hitCounter = 0;
	sfPtr = searchFor;

	for (; sizeof(sfPtr) < *sfPtr; )
	{
	if (*sfPtr == *strPtr)
	hitCounter++;

	strPtr++;
	sfPtr++;

	if (hitCounter == sfCount)
	{
	nrToReplace++;
	hitCounter = 0;
	sfPtr = searchFor;
	}

	}
	}*/
	return nrToReplace;

}

char* Replace(const char* str, const char* searchFor, const char* changeTo)
{
	int counter = Count(str, searchFor);

	int lengthOfChange = strlen(changeTo);
	int lengthOfRemove = strlen(searchFor);
	int lengthOfStr = strlen(str);
	int charsToBeAllocated = (lengthOfStr - (lengthOfRemove * counter)) + lengthOfChange * counter;

	const char * changeToPtr = changeTo;
	const char * searchForPtr = searchFor;
	const char * strPtr = str;

	char* newArray = new char[charsToBeAllocated + 1];
	newArray[charsToBeAllocated] = NULL;
	const char* strItr = str;

	char* newArrayPtr = newArray;

	for (; sizeof(strItr) < *strItr;)									//G� igenom alla chars i str�ngen
	{
		searchForPtr = searchFor;
		changeToPtr = changeTo;

		if (*searchForPtr == *strItr)									//Tr�ff - kolla om det �r fullst�ndig searchFor
		{
			const char* tempSfPtr = searchFor;
			const char* tempStrPtr = strItr;
			int targetCount = strlen(searchFor);
			int hitCounter = 0;

			for (; sizeof(tempSfPtr) < *tempSfPtr;)
			{
				if (*tempSfPtr == *tempStrPtr)
				{
					hitCounter++;
				}
				tempSfPtr++;
				tempStrPtr++;
			}

			if (hitCounter == targetCount)
			{
				for (; sizeof(changeToPtr) < *changeToPtr;)					//N�r en det �r en tr�ff l�gg in de chars som finns i changeTo
					*newArrayPtr++ = *changeToPtr++;

				for (; sizeof(searchForPtr) < *searchForPtr; searchForPtr++) // D�refter hoppa �ver chars (searchFor) i den originella str�ngen
					*strItr++;
			}
			else
				*newArrayPtr++ = *strItr++;
		}
		else
			*newArrayPtr++ = *strItr++;										//Utan tr�ff l�gg bara till den nuvarande char fr�n str
	}

	/*const char* newStrPtr = newArray;
	const char* endPtr = newArray;*/

	//	cout << *endPtr;

	return newArray;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//char* result = Replace("Hej p� dej", "ej", "ig");
	//	char* result = Replace("abcabcbc", "abc", "ya");
	char* result = Replace("abcabcbc", "", "ya");
	char* resPtr = result;
	string output = "";

	for (; sizeof(resPtr) < *resPtr; resPtr++)
		output += *resPtr;

	cout << output;

	delete[] result;


	cin.get();

	int c_array[5] = {};
	auto c_array_begin = std::begin(c_array);



}

