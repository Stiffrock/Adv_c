#pragma once

template <class T>
class SharedPtr
{
	T* ptr;
public:
	SharedPtr();
	SharedPtr(nullptr nPtr) {};
	SharedPtr(T* ptr) {};
	SharedPtr(SharedPtr& sPtr) {};
	SharedPtr(SharedPtr&& sPtr) {};

	//Tilldelning
	SharedPtr(SharedPtr& sPtr) {};

	operator==(nullptr nPtr) {};
	operator==(SharedPtr sPtr) {};
	operator<(nullptr nPtr) {};
	operator<(SharedPtr sPtr) {};

	operator*() {};
	operator->() {};
	operator bool() {};
	
	reset(T* = nullptr) {};
	T* get() {};
	void unique() {};
	
	~SharedPtr();
};

