#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include "List.h"
#include "Node.h"
#include "Link.h"
#include <assert.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

using namespace std;
class Node2 : public Link<Node2> {
public:
	float data;
	Node2(float v = 0) :data(v) {}

	virtual std::ostream& Print(std::ostream& cout) {
		return cout << data;
	}

	bool Node2::operator==(float rhs) const
	{
		return data == rhs;
	}
};


template Link<Node2>;    //Detta tvingar fram att allting i Link kompileras
template List<Node2>;    //Detta tvingar fram att allting i List kompileras

void TestDLL() {

	List<Node2> myList;
	assert(myList.Check());
	Node2 * nodeA3 = myList.InsertFirst(new Node2(3));
	assert(myList.Check());
	myList.InsertFirst(new Node2(2));
	myList.InsertFirst(new Node2(1));
	assert(myList.Check());
	myList.InsertLast(new Node2(1));
	myList.InsertLast(new Node2(2));
	myList.InsertLast(new Node2(3));
	assert(myList.Check());
	assert(myList.Last()->Next() == nullptr);
	cout << myList;    //should be 1 2 3 1 2 3

	Node2 * tempA3 = myList.FindNext(3);
	assert(tempA3 == nodeA3);
	Node2 * nodeB1 = nodeA3->FindNext(1);
	Node2 * tempB1 = tempA3->DeleteAfter();   //ta bort andra 1:an
	assert(myList.Check());
	assert(tempB1->data == 1);

	Node2 * nodeA2 = myList.FindFirst(2);
	Node2 * nodeB2 = nodeA2->FindNext(2);
	Node2 * temp = nodeB2->FindNext(2);
	assert(!temp);

	nodeA2->DeleteAfter();
	cout << myList;    //1 2 2 3

	myList.First()->Next()->InsertAfter(tempA3)->InsertAfter(tempB1);
	assert(myList.Last()->Prev()->data == 2);
	assert(myList.Check());
	std::cout << myList;    //should be 1 2 3 1 2 3
	{Node2* t = myList.PopFirst(); assert(t->data == 1); delete t; }
	{Node2* t = myList.PopFirst(); assert(t->data == 2); delete t; }
	{Node2* t = myList.PopFirst(); assert(t->data == 3); delete t; }
	{Node2* t = myList.PopFirst(); assert(t->data == 1); delete t; }
	{Node2* t = myList.PopFirst(); assert(t->data == 2); delete t; }
	{Node2* t = myList.PopFirst(); assert(t->data == 3); delete t; }
	assert(myList.PopFirst() == nullptr);
	assert(myList.PopFirst() == nullptr);
	cout << myList << "end";
	assert(myList.Check());
	cin.get();
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	List<Node<float>> list;

	Node<float>* newNode = new Node<float>(1);
	Node<float>* newNode2 = new Node<float>(2);
	Node<float>* newNode3 = new Node<float>(3);
	Node<float>* newNode4 = new Node<float>(4);


	list.InsertFirst(newNode);
	newNode->InsertBefore(newNode2);
	newNode2->InsertAfter(newNode3);

	Node<float>* f = newNode3->DeleteAfter();
	delete f;
	list.InsertLast(newNode4);
	Node<float>* temp = newNode2->FindNext(3);
	Node<float>* temp2 = list.FindFirst(2);


	Node<float>* n = list.PopFirst();
	delete n;
	cout << list;


	Node<float>* d = list.PopFirst();
	do
	{
		delete d;
		d = list.PopFirst();
	} while (d != nullptr);




	TestDLL();

	cin.get();
}