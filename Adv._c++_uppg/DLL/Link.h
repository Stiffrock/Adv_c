#pragma once
#include "List.h"

// När jag kör en insertbefore första noden så sätts aldrig den noden som first

template <class T>
class List;

template <class T>
class Link
{
	Link* next; Link* prev;
	friend class List<T>;

public:
	Link() : next(nullptr), prev(nullptr) {}
	virtual ~Link() = default;

	void Check();
	virtual std::ostream& Print(std::ostream& cout) const { return cout; }

	T* Next();
	const T* Next() const;

	T* Prev();
	const T* Prev() const;	

	template<class X>
	T* FindNext(X searchFor);

	template<class X>
	const T* FindNext(const X &searchFor) const;

	T* InsertAfter(T* item);
	T* InsertBefore(T* item);
	T* DeleteAfter();
};

template <class T>
T* Link<T>::DeleteAfter()
{
	T* deleted = Next();
	if (deleted == nullptr)
	{
		return nullptr;
	}

	this->next = deleted->next;
	deleted->next->prev = this;

	Check();
	return deleted;
}

template <class T>
T* Link<T>::InsertBefore(T* item)
{
	item->next = this;
	item->prev = prev;
	prev->next= item;
	prev = item;

	Check();
	return item;
}

template <class T>
T* Link<T>::InsertAfter(T* item)
{		
	item->next = next;
	item->prev = this;
	next->prev = item;
	next = item;

	Check();
	return item;
}

template <class T>
template <class X>
T* Link<T>::FindNext(X searchFor)
{
	return const_cast <T*> (const_cast<const Link<T>*>(this)->FindNext(searchFor));
}

template <class T>
template <class X>
const T* Link<T>::FindNext(const X& searchFor) const
{	
	for (const T* itr = Next(); itr != nullptr; itr = itr->Next())
	{	
		if (*itr == searchFor)
		{
			return itr;
		}	
	}
	return nullptr;
}

template <class T>
const T* Link<T>::Next() const 
{
	return dynamic_cast<T*>(next);
}

template <class T>
T* Link<T>::Next()
{
	return dynamic_cast<T*>(next);
}

template <class T>
const T* Link<T>::Prev() const
{
	return dynamic_cast<T*>(prev);
}

template <class T>
T* Link<T>::Prev()
{
	return dynamic_cast<T*>(prev);
}


template <class T>
void Link<T>::Check()
{
	assert(next->prev == this && prev->next == this);
}

