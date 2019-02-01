#pragma once

template <typename T>
class Node
{

private:
	T data;
	Node* next;

public:
	Node()
	{
		next = nullptr;
	};

	T getData()
	{
		return this->data;
	};

	void setData(T data)
	{
		this->data = data;
	};

	Node* getNext()
	{
		return this->next;
	};

	void setNext(Node* next)
	{
		this->next = next;
	};
};