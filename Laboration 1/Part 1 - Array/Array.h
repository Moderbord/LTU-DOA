#pragma once
#include <iostream>
#include <stdio.h>

template <typename T>
class Array
{
private:
	T *arr;
	int size;

public:
	~Array()
	{
		delete[] arr;
	}

	Array()
	{
		arr = new T[0];
		size = 0;
	};

	void insert(T item)
	{
		T *newArr = new T[size + 1];
		std::memcpy(newArr, arr, sizeof(T)*size);
		delete[] arr;
		arr = newArr;

		std::cout << sizeof(T);

		arr[size] = (T)item;
		size++;
		return;
	}

	void remove(int i)
	{
		size--;

		if (size != 0)
		{
			arr[i - 1] = arr[size];
		}

		T *newArr = new T[size];
		std::memcpy(newArr, arr, sizeof(T)*size);
		delete[] arr;
		arr = newArr;

		return;
	}

	void display()
	{
		if (size < 1)
		{
			std::cout << "Array contains no values" << std::endl;
			return;
		}

		for (int i = 0; i < size; i++)
		{
			std::cout << std::to_string(i + 1) << ":" << &arr[i] << std::endl;
		}
	}
};