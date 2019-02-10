#pragma once
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <typeinfo>

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
		clock_t begin = clock();																	// Time start

		T *newData = new T[size + 1];																// Allocates new memory for larger array
		std::copy_n(data, size, newData);															// Copies the existing data to the new array
		delete[] data;																				// Deletes values in old array						
		data = newData;																				// point the old array to the new one
		data[size] = (T)s;																			// Inserts the new element to the last position
		size++;

		clock_t end = clock();																		// Time end
		std::cout << "Operation time: " << (double)((end - begin) * 1000) / CLOCKS_PER_SEC << " ms\n";	// Prints time difference between measures in ms
	}

	void insertSkipMeasure(T &s)
	{
		T *newData = new T[size + 1];																// Same as above except no time measurements
		std::copy_n(data, size, newData);															
		delete[] data;
		data = newData;
		data[size] = (T)s;
		size++;
	}

	T& get(int i)
	{
		clock_t begin = clock();																	// Time start

		return data[i - 1];																			// Return item från array

		clock_t end = clock();																		// Time end
		std::cout << "Operation time: " << (double)((end - begin) * 1000) / CLOCKS_PER_SEC << " ms\n";	// Prints time difference between measures in ms
	}

	void remove(int i)
	{
		clock_t begin = clock();																	// Time start

		size--;																						// Recrements size
		data[i - 1] = data[size];																	// Changes the removable value to the one in the last pos. 

		T *newData = new T[size];																	// Creates new memory with a smaller size then last array
		std::copy_n(data, size, newData);															// Copies all data from old to new array except last item
		delete[] data;																				// Deletes old values
		data = newData;																				// Points old array to new array

		clock_t end = clock();																		// Time end
		std::cout << "Operation time: " << (double)((end - begin) * 1000) / CLOCKS_PER_SEC << " ms\n";	// Prints time difference between measures in ms
	}

	void display()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << std::to_string(i + 1) << ":" << (T)data[i] << std::endl;
		}
	}

	bool isEmpty()
	{
		return size == 0 ? true : false;
	}

};