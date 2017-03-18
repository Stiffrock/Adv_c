template <typename T>
SharedPtr<T>::SharedPtr()
{
	count = nullptr;
	ptr = nullptr;
	Invariant();
}

template <typename T>
SharedPtr<T>::SharedPtr(std::nullptr_t nullp)
{
	count = nullptr;
	ptr = nullptr;
	Invariant();
}

template<typename T>
SharedPtr<T>::SharedPtr(T* p)
{
	if (p != nullptr)
		count = new int(1);
	else
		count = nullptr;

	ptr = p;
	Invariant();
}

template<typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T> &&rhs)
{
	ptr = rhs.ptr;
	count = rhs.count;

	rhs.ptr = nullptr;
	rhs.count = nullptr;

	Invariant();
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T> &rhs)
{
	ptr = rhs.ptr; // tror jag måste förstöra ptr
	count = rhs.count;

	if (ptr != nullptr)
	++*count;

	Invariant();

}

template <typename T>
SharedPtr<T>::~SharedPtr()
{
	if (count == nullptr)
	{
		return;
	}
	if (--*count == 0)
	{
		delete ptr;
		delete count;
	}

}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& rhs) 
{

	if (ptr == rhs.ptr)
		return *this;


	//om det redan finns något i ptr måste det raderas och ersättas 
	if (ptr != nullptr)
	{
		delete ptr;
		--*count;

		ptr = rhs.ptr;
		count = rhs.count;
		
		if (ptr != nullptr)
			++*count;

		return *this;
	}	
}




