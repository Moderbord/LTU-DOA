#pragma once
#include "Node.h"
#include <iostream>

namespace {
	using std::cout;
	using std::endl;
}

template <typename T>
class LinkedList
{
private:
	Node<T> *head;

public:
	LinkedList()
	{
		head = nullptr;
	};

	void insert(Node<T> *node)
	{
		if (head != nullptr)						// If list has Node
		{
			node->setNext(head);					// New Node references previous head
		}
		head = node;								// Updates head to new Node
	}

	Node<T>* search(T value)
	{
		Node<T> *current = head;

		while (current != nullptr) {

			if (current->getData() == value)		// Node data matches search value
			{
				return current;						// Returns Node
			}
			current = current->getNext();
		}
		// Returns NULL 
	}

	void remove(int i)
	{
		Node<T> *shiftNode = new Node<T>();
		this->insert(shiftNode);					// Inserts temporary Node at head

		Node<T> *current = head;					// 'current' starts at head (shiftNode)

		for (int j = 1; j < i; j++)					// Traverses LinkedList prior to Node 'i'
		{
			if (current->getNext() == nullptr)		// Node out of range
			{
				return;
			}
			current = current->getNext();			// 'current' becomes Node prior to the Node beeing removed
		}

		head = shiftNode->getNext();				// Cuts the temporary head from Linkedlist

		shiftNode->setNext(current->getNext());		// Temp Node stores reference to Node that's beeing removed

		current->setNext(current->getNext()->getNext());	// Bridges current Node over the one beeing removed

		delete shiftNode->getNext();				// Deletes Node
		delete shiftNode;							// Deletes temporary Node
	}

	void display()
	{
		Node<T> *current = head;

		while (current != nullptr) {				// Traverses Nodes in LinkedList up to nullptr
			cout << current->getData() << " ";
			current = current->getNext();
		}
		cout << endl;
	}

};