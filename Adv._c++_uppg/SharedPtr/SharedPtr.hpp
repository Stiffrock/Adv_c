template <typename T>
SharedPtr<T>::SharedPtr()
{
	//count = new int(1);

	count = nullptr;
	ptr = nullptr;
	Invariant();
}

template <typename T>
SharedPtr<T>::SharedPtr(std::nullptr_t nullp)
{
	//count = new int(1);
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
	ptr = rhs.ptr;
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
SharedPtr<T> &SharedPtr<T>::operator=(SharedPtr<T> &&rhs)
{	

	if (ptr == sptr.ptr)
		return *this;

	if (ptr != nullptr)
	{
		ptr = sptr.ptr;
		count = sptr.count;
	}
	if (sptr.ptr == nullptr)
	{
		ptr = sptr.ptr;
		count = nullptr;
	}
	//ptr = rhs.ptr;
	//count = rhs.count;

	if (ptr != nullptr)
		++*rhs.count;
	Invariant();

	return *this;
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& sptr) //Tilldelningsoperatorerna är fucked, måste ta hänsyn till att du kan göra tilldelning på ett redan existerande objekt. Då måste det objektet tas bort LUL.
{

	if (ptr == sptr.ptr)
		return *this;

	if (ptr != nullptr)
	{
		ptr = sptr.ptr;
		count = sptr.count;
	}
	if (sptr.ptr == nullptr)
	{
		ptr = sptr.ptr;
		count = nullptr;
	}
		


	
	

	if (ptr != nullptr)
		++*sptr.count;
	Invariant();
	return *this;
}




