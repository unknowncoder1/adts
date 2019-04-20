#include "List.h"
#include <iostream>
#include <stdexcept>//used to be able to "throw" exceptions

using namespace std;


class List::Node //self-referential Node class
{
public:
	int data = 0;
	Node* link = nullptr;
	//link is a data member which is a pointer 
	//to an object of the same type (i.e. Node)

};//end Node class definition (can only be seen by the List class)


List::~List()
{
	while (num_elements > 0)
		remove(1);
}

int List::size()
{
	return num_elements;
}

void List::insert(int val, int k)
{
	if (k < 1 or k > num_elements + 1) //if the location is invalid
		throw out_of_range("List::insertAt(...)");//throw an "out_of_range" exception


	Node* newPtr = new Node{ val };

	if (k == 1)
	{
		newPtr->link = frontPtr;
		frontPtr = newPtr;
	}
	else
	{

		Node* tmpPtr = frontPtr;
		int loc = 1;

		while (loc != k - 1) //get pointer to (k-1)th node
		{
			tmpPtr = tmpPtr->link;
			loc++;
		}

		newPtr->link = tmpPtr->link;
		tmpPtr->link = newPtr;
	}//end else

	num_elements++;
}

int List::remove(int k)
{
	if (k < 1 or k > num_elements)//if the location is invalid 
		throw out_of_range("List::removeAt(...)");//throw an "out_of_range" exception

	Node* delPtr;

	if (k == 1)
	{
		delPtr = frontPtr;
		frontPtr = frontPtr->link;
	}
	else
	{
		Node* tmpPtr = frontPtr;

		int loc = 1;

		while (loc != k - 1)//get pointer to (k-1)th node
		{
			tmpPtr = tmpPtr->link;
			loc++;
		}

		delPtr = tmpPtr->link;
		tmpPtr->link = delPtr->link;
	}

	delete delPtr;
	return --num_elements;
}

int List::getAt(int k)
{
	Node* tmpPtr = frontPtr;
	for (int loc = 1; loc != k; loc++)
	{
		tmpPtr = tmpPtr->link;
	}
	return tmpPtr->data;
}

void List::clear()
{
	while (size() != 0)
	{
		remove(1);
	}
}

void List::display()
{
	for (Node* tmpPtr = frontPtr; tmpPtr != nullptr; tmpPtr = tmpPtr->link)
	{
		cout << tmpPtr->data << " ";
	}
}
//Implementations of missing operations