#include <iostream>
#include <cstdlib>


template <class T>
struct Node
{
private:
	T value;

public:
	Node* nextNode;

	Node(const T& val = NULL)
	{
		value = val;
	}

	T getValue()
	{
		return value;
	}
	void setValue(T& val)
	{
		value = *val;
	}

	Node* getNextNode()
	{
		return nextNode;
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

	void addStart(const T & val)
	{
		Node<T>* newnode = new Node<T>(val);
		if (headptr == nullptr)
		{
			headptr = newnode;
			tailptr = newnode;
		}
		else
		{
			newnode->setNextNode(headptr);
			headptr = newnode;
		}
		numElements += 1;
	}


	Node<T>* nodeat(int i)
	{
		if (i == 0)
		{
			return (headptr);
		}
		Node<T>* temp = headptr;
		int r = 0;
		if (i > 0 && i < numElements)
		{
			while (r < i)
			{
				temp = (temp->getNextNode());
				r++;
			}
			return temp;
		}
		else if (i < 0 && i >= -numElements)
		{
			i = numElements + i;
			while (r < i)
			{
				temp = (temp->getNextNode());
				r++;
			}
			return temp;
		}
		else
		{
			std::cerr << "Invalid Index" << std::endl;
			return NULL;
		}
	}


	T at(int i)
	{
		if (i == 0)
		{
			return (headptr->getValue());
		}
		Node<T>* temp = headptr;
		int r = 0;
		if (i > 0 && i < numElements)
		{
			while (r < i)
			{
				temp = (temp->getNextNode());
				r++;
			}
			return temp->getValue();
		}
		else if (i < 0 && i >= -numElements)
		{
			i = numElements + i;
			while (r < i)
			{
				temp = (temp->getNextNode());
				r++;
			}
			return temp->getValue();
		}
		else
		{
			std::cerr << "Invalid Index" << std::endl;
			return NULL;
		}
	}
	void removeStart()
	{
		if (headptr != nullptr)
		{
			Node<T> temp = *headptr;
			delete headptr;
			headptr = temp.getNextNode();
			numElements -= 1;
		}
		else
			std::cerr << "No value to remove" << std::endl;
	}
	void removeEnd()
	{
		if (tailptr != nullptr)
		{
			tailptr = (this->nodeat(-2));
			delete tailptr->getNextNode();
			tailptr->setNextNode(nullptr);
		}
		numElements -= 1;
	}

	int length()
	{
		return numElements;
	}

	void removeat(int p)
	{
		this->nodeat(p - 1)->setNextNode(this->nodeat(p + 1));
		delete this->nodeat(p);
		numElements -= 1;
	}

	~DynamicList()
	{
		if (headptr != nullptr)
		{
			Node<T>* del = headptr;
			Node<T>* temp = del->getNextNode();
			int i = 1;
			while (i < numElements)
			{
				delete del;
				del = temp;
				temp = temp->getNextNode();
				i++;
			}
			delete tailptr;
		}
	}
};
