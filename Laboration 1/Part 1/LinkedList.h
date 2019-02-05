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

	void insert(Node<T> *node)
	{
		if (head != nullptr)						// If list has Node
		{
			node->setNext(head);					// New Node references previous head
		}
		head = node;								// Updates head to new Node
	}

	Node<T>* get(int i)
	{
		Node<T> *current = head;

		while (current->getNext() != nullptr && i > 1)
		{
			current = current->getNext();
			i--;
		}
		return current;
	}

	void remove(int i)
	{
		Node<T> *bridge = head;
		Node<T> *toRemove = new Node<T>();
		toRemove = head;

		if (i == 1)
		{
			head = head->getNext();
			delete toRemove;
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