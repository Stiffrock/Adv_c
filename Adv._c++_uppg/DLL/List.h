#pragma once
#include <assert.h>
#include <iostream>
#include "Link.h"

template <class T>
class Link;

template <class T>
class List : public Link<T>
{
	//friend class Link<T>;
	
#define first this->next
#define last this->prev
public:
	List();
	~List() {};

	T* First();
	const T* First() const;

	T* Last();
	const T* Last() const;

	T* InsertFirst(T* item);
	T* InsertLast(T* item);

	T* PopFirst();
	const bool Check();

	template<class X>
	T * FindFirst(const X& searchFor) { return FindNext(searchFor); }

	friend std::ostream& operator<<(std::ostream& cout, List& list) {
		return list.Print(cout);
		
	}
private:
	std::ostream& Print(std::ostream& cout);
};

template <class T> 
List<T>::List() :Link() {
	first = last = this; 
}

template <class T>
T* List<T>::PopFirst()
{
	T* firstPtr = First();
	if (firstPtr == nullptr)
	{
		return nullptr;
	}

	first = first->next;
	first->prev = this;
	last->next = this;

	return firstPtr;
}

template <class T>
const T* List<T>::First() const
{
	return dynamic_cast<T*>(first);
}

template <class T>
T* List<T>::First()
{
	return dynamic_cast<T*>(first);
}

template <class T>
const T* List<T>::Last() const
{
	return dynamic_cast<T*>(last);
}

template <class T>
T* List<T>::Last()
{
	return dynamic_cast<T*>(last);
}

template <class T>
T* List<T>::InsertFirst(T* item)
{
	return InsertAfter(item);
}

template <class T>
T* List<T>::InsertLast(T* item)
{
	return InsertBefore(item);
}


template<class T>
const bool List<T>::Check() {

	const Link<T>* node = this, *nextNode = this->next;
	do {		
		assert(node->next == nextNode && nextNode->prev == node);
		node = nextNode;
		nextNode = nextNode->next;
	} while (node != this);

	return true;
}


template <class T>
std::ostream& List<T>::Print(std::ostream& cout) {
	for (Link<T>* item = First(); item; item = item->Next()) {
		item->Print(cout) << ' ';
	}
	cout << '\n';
	return cout;
}