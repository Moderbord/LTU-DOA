#pragma once
#include "Node.h"
#include <iostream>
#include <time.h>

namespace {
	using std::cout;
	using std::endl;
}

template <typename T>
class LinkedList									// A "One Way" Linked List class
{
private:
	Node<T> *head;

public:
	// When a student is removed all corresponding courses must also be removed.
	// This deconstructor loops through and deletes every *Node<Course> attached
	// to the student.
	// Due to the linear operation it requires O(n) operations with 'Big Oh' 
	// notation, where n is the number of *Node<Course> objects.
	~LinkedList()									
	{
		Node<T> *current = head;					
		while (head != nullptr)						
		{											
			current = current->getNext();
			delete head;
			head = current;
		}
	}

	LinkedList()
	{
		head = nullptr;
	};

	// Inserting a *Node<T> to the head of the LinkedList is quick and
	// corresponds to O(1) operations in 'Big Oh' notation.
	void insert(Node<T> *node)						
	{										
		clock_t begin = clock();																	// Time start

		if (head != nullptr)
		{
			node->setNext(head);
		}
		head = node;

		clock_t end = clock();																		// Time end
		cout << "Operation time: " << (double)((end - begin) * 1000) / CLOCKS_PER_SEC << " ms\n";	// Prints time difference between measures in ms
	}

	// Same as above except used for initalization and skips the measured operation time
	void insertSkipMeasure(Node<T> *node)
	{
		if (head != nullptr)
		{
			node->setNext(head);
		}
		head = node;
	}

	// Retrieving a *Node<T> from the LinkedList may require us to traverse
	// the whole list. This makes this equal to O(n) number of operations
	// in 'Big Oh' notation.
	Node<T>* get(int i)								
	{												
		clock_t begin = clock();																	// Time start

		Node<T> *current = head;					

		while (current->getNext() != nullptr && i > 1)
		{
			current = current->getNext();
			i--;
		}

		clock_t end = clock();																		// Time end
		cout << "Operation time: " << (double)((end - begin) * 1000) / CLOCKS_PER_SEC << " ms\n";	// Prints time difference between measures in ms

		return current;
	}

	// Removing a *Node<T> from the LinkedList requires as many operations 'T' as
	// the index 'i' specifies, T(i). This is the operations in the while-loop. The
	// rest of the code can be summarized as T(x) operations, making it a total of 
	// T(i + x) operations. As worst case scenario, and with 'Big Oh' notation, this
	// can be written as O(n) when 'i' points to the last object 'n' in the LinkedList
	void remove(int i)								
	{						
		clock_t begin = clock();																		// Time start
		
		Node<T> *bridge = head;						
		Node<T> *toRemove = new Node<T>();			
		toRemove = head;
							
		if (i == 1)
		{
			head = head->getNext();
			delete toRemove;

			clock_t end = clock();																		// Time end
			cout << "Operation time: " << (double)((end - begin) * 1000) / CLOCKS_PER_SEC << " ms\n";	// Prints time difference between measures in ms
			return;
		}

		while (toRemove->getNext() != nullptr && i > 1)
		{
			bridge = toRemove;
			toRemove = toRemove->getNext();
			i--;
		}

		bridge->setNext(toRemove->getNext());
		delete toRemove;

		clock_t end = clock();																		// Time end
		cout << "Operation time: " << (double)((end - begin) * 1000) / CLOCKS_PER_SEC << " ms\n";	// Prints time difference between measures in ms
	}

	void display()
	{
		Node<T> *current = this->head;

		int i = 1;
		while (current != nullptr) {
			cout << i << ":" << current->getData() << endl;
			current = current->getNext();
			i++;
		}
	}

	bool isEmpty()
	{
		return this->head == nullptr ? true : false;
	}

};