#pragma once

template <class T>
class SharedPtr
{
	T* ptr;
	int *count;
public:
	SharedPtr();
	SharedPtr(std::nullptr_t nullp);
	SharedPtr(T* ptr);

	//Move
	SharedPtr(SharedPtr&&);

	//Tilldelning
	SharedPtr(const SharedPtr&);
	SharedPtr& operator=(SharedPtr &&);

	bool operator==(std::nullptr_t nullp) { return ptr == nullp; };
	bool operator==(SharedPtr<T> sPtr) { return ptr == sPtr.ptr; };
	bool operator<(std::nullptr_t nullp ) {return ptr < nullp};
	bool operator<(SharedPtr<T> sPtr) { return ptr < sPtr.ptr; };

	T& operator*() { return *ptr; };
	T* operator->() { return ptr; };
	operator bool() { if (ptr != nullptr) { return true; } else return false; };
	T& operator=(const SharedPtr ptr);

	
	void reset(T* = nullptr) {};
	T* get() { return ptr; };
	bool unique() { if (*count > 1) { return true; } else return false; }; //checks if the managed oject is owned by others
	
	~SharedPtr();
};

#include "SharedPtr.hpp"