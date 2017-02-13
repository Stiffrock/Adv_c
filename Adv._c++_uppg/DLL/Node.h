#pragma once
#include "Link.h"


template <class T>
class Node : public Link<Node<T>>
{
	T data;
public:
	Node(T  data) : data(data){};

	virtual std::ostream& Print(std::ostream& cout){
		return cout << data;
	}
	~Node() {}

	bool Node::operator==(T rhs) const
	{
		return data == rhs;
	}
};

