#pragma once
#include "Link.h"


template <class T>
class Node : public Link<Node<T>>
{
	T data;
public:
	Node(T  data) : data(data){};

	virtual std::ostream& Print(std::ostream& cout) const {
		return cout << data;
	}
	~Node() {}

	friend std::ostream& operator<<(std::ostream& cout, const Node<T>& node){
		return cout << node.data;

	}


	bool Node::operator==(T rhs) const
	{
		return data == rhs;
	}
};

