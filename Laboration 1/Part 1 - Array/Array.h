#pragma once
#include <iostream>
#include <stdio.h>

template <typename T>
class Array
{
public:
	T *data;
	int size;

	Array()
	{
		data = new T[0];
		size = 0;
	}

	void insert(T &s)
	{
		T *newData = new T[size + 1];
		std::copy_n(data, size, newData);
		delete[] data;
		data = newData;
		data[size] = (T)s;
		size++;
	}

	T& get(int i)
	{
		return data[i - 1];
	}

	void remove(int i)
	{
		size--;
		data[i - 1] = data[size];

		T *newData = new T[size];
		std::copy_n(data, size, newData);
		delete[] data;
		data = newData;
	}

	void display()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << (T)data[i] << std::endl;
		}
	}

	bool isEmpty()
	{
		return size == 0 ? true : false;
	}

};