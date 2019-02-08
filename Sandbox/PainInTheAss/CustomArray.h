#pragma once
#include <iostream>
#include <stdio.h>
#include <array>

template <typename T>
class CustomArray
{
public:
	T *data;
	int size;

	CustomArray()
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

//#pragma once
//#include "Student.h"
//#include <iostream>
//#include <stdio.h>
//
//class Array
//{
//public:
//	Student *arr;
//	int size;
//
//	Array()
//	{
//		arr = new Student[0];
//		size = 0;
//	};
//
//	void insert(Student s)
//	{
//		Student *newArr = new Student[size + 1];
//		std::memcpy(newArr, arr, sizeof(Student)*size);
//		delete[] arr;
//		arr = newArr;
//
//		arr[size] = s;					// Inserts value
//		size++;
//		return;
//	}
//
//	void remove(int i)
//	{
//		size--;
//
//		if (size != 0)
//		{
//			arr[i - 1] = arr[size];
//		}
//
//		Student *newArr = new Student[size];
//		std::memcpy(newArr, arr, sizeof(Student)*size);
//		delete[] arr;
//		arr = newArr;
//	}
//
//	void display()
//	{
//		if (size < 1)
//		{
//			std::cout << "Array contains no values" << std::endl;
//			return;
//		}
//
//		for (int i = 0; i < size; i++)
//		{
//			std::cout << arr[i] << std::endl;
//		}
//	}
//};