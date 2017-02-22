#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG
#include <stdlib.h>
#include <crtdbg.h>

#define VG

#include "String.h"

//#include <string>

#include <iostream>
using std::cout;
using std::cin;

#include <cassert>

//#include <utility

void TestPushBackReallocation() {
	String str("hej");
	assert(str.size() <= str.capacity());
	auto internalBuf = str.data();
	auto cap = str.capacity();
	auto siz = str.size();
	int i;
	for (i = siz + 1; i <= cap; ++i) {
		str.push_back(char(i) + 'a'); // ska inte kalla p� reserve		
		assert(internalBuf == str.data());
		assert(cap == str.capacity());
		assert(i == str.size());	
	}

	str.push_back(char(i)); // denna ska kalla p� reserve 
	assert(internalBuf != str.data());
	assert(cap < str.capacity());
	assert(i == str.size());

	assert(str.size() != str.capacity());
	internalBuf = str.data();
	cap = str.capacity();
	siz = str.size();
	str.shrink_to_fit();
	assert(internalBuf != str.data());
	assert(str.size() == str.capacity());
	assert(i == str.size());
}

void TestF�rGodk�ntString() {

	//-	String()
	String str0;
	String str00("");
	assert(str0 == str00);
	str0 != str00;
	//-	String(Str�ng str�ng)
	String s1("foo"); assert(s1 == "foo");
	String str(s1); assert(str == "foo");
	String s3("bar");  assert(s3 == "bar");

	~String(); //Kom ih�g destruktorn!
	delete new String("hej");

	//	-	operator =(Str�ng str�ng)
	assert((str = s3) == s3);
	assert((str = str) == s3);	//self assignment


	String str1("foo"), str2("bar"), str3("hej");
	str3 = str = str1;
	assert(str3 == str);
	assert(str1 == str);

	// operator bool

	assert(String("huj"));
	assert(!String(""));

	//-	operator== 
	//testas �verallt!


	//-	operator[](int i) som indexerar utan range check.
	str = "bar";
	str[-1]; str[1000];	//No error
	assert(str[1] == 'a');
	str[1] = 'y';
	assert(str[1] == 'y');

	const String sc(str);
	assert(sc[1] == 'y');
	assert(std::is_const<std::remove_reference< decltype(sc[1])>::type>::value); //Kolla att det blir en const resultat av indexering

																				 //-	push_back(char c) l�gger till ett tecken sist.
	str = "bar";
	str.push_back('a');
	assert(str == "bara");

	//-	size(), capacity() and reloccation test;
	TestPushBackReallocation();
	int x = 0;
	cout << String("hej\n");
	cout << "Om det st�r hej p� f�reg�ende rad s� �r TestF�rGodk�nt klar\n";
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::locale::global(std::locale("swedish"));

	
	//TestUnsigned();
	TestF�rGodk�ntString();
	std::cin.get();

}