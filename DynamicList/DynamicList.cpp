#include <iostream>
#include <cstdlib>


template <class T>
class Node
{
	T value;
	Node* nextNode;
public:
	Node(T val = NULL)
	{
		this->value = val;
	}

	T getValue()
	{
		return value;
	}
	void setValue(T val)
	{
		value = val;
	}

	Node getNextNode()
	{
		return *nextNode;
	}
	void setNextNode(Node* nex)
	{
		nextNode = nex;
	}
};

template <class T>
class DynamicList
{
	Node<T>* headptr;
	Node<T>* tailptr;
	int numElements = 0;
public:
	DynamicList() {}
	void addEnd(T val)
	{
		Node<T>* node = new Node<T>(val);
		if (headptr == nullptr)
		{
			headptr = node;
			tailptr = node;
		}
		else
		{
			tailptr->setNextNode(node);
			tailptr = node;
		}
		numElements += 1;
	}
	Node<T> getHeadNode()
	{
		return *(this->headptr);
	}
};

int main() {
	DynamicList<int> list;
	list.addEnd(10);
	list.addEnd(20);
	list.addEnd(30);
	list.addEnd(40);
	list.addEnd(50);
	list.addEnd(60);
	list.addEnd(70);
	std::cout << list.getHeadNode().getNextNode().getValue() << std::endl;
}


