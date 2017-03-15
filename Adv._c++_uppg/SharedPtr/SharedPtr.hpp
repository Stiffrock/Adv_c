template <typename T>
SharedPtr<T>::SharedPtr()
{
	ptr = nullptr;
	count = new int(1);
}

template <typename T>
SharedPtr<T>::SharedPtr(std::nullptr_t nullp)
{
	ptr = nullptr;
	count = 0;
}

template<typename T>
SharedPtr<T>::SharedPtr(T* p)
{
	ptr = ptr;
	count = new int(1);
}

template<typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T> &&rhs)
{
	ptr = rhs.ptr;
	count = rhs.count;

	rhs.ptr = nullptr;
	*rhs.count = 0;
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T> &rhs)
{
	ptr = rhs.ptr;
	count = rhs.count;
	++*count;
}




template <typename T>
SharedPtr<T>::~SharedPtr()
{
	if (--*count == 0)
	{
		delete ptr;
		delete count;
	}
}

template <typename T>
SharedPtr<T> &SharedPtr<T>::operator=(SharedPtr<T> &&rhs)
{
	++*rhs.count;
	ptr = rhs.ptr;
	count = rhs.count;
	return *this;
}

template <typename T>
T& SharedPtr<T>::operator=(const SharedPtr sptr)
{
	this->ptr = sptr.ptr;
	++*sptr.count;
	this->count = sptr.count;
	return *this;
}s




