#include "pch.h"
#include <iostream>
#include <algorithm>

template <typename T>
void insertion_sort(T elements[], const int left_bound, const int right_bound)
{
	// Iterates after first element
	for (int i = left_bound + 1; i < right_bound; i++)						
	{
		// Current element that is being sorted
		T current = elements[i];									
		// Pivot element
		int pivot = i - 1;

		// Right-shifts elements that is larger than current
		while (pivot >= left_bound && current < elements[pivot])				
		{
			elements[pivot + 1] = elements[pivot];
			pivot--;
		}
		// Inserts target element
		elements[pivot + 1] = current;
	}
}

template <typename T>
int binary_search(T elements[], const int left_bound, const int right_bound, T target_element)
{
	int middle_index = 0;

	if (right_bound >= 1)
	{
		middle_index = (left_bound + right_bound) / 2;

		// Target element OR position for insertion found, returns index
		if (elements[middle_index] == target_element || left_bound == right_bound)
		{
			return middle_index;
		}

		// Middle element is larger than target element, searches left sublist
		if (elements[middle_index] > target_element)
		{
			return binary_search(elements, left_bound, middle_index - 1, target_element);
		}

		// Middle element is smaller than target element, searches right sublist
		if (elements[middle_index] < target_element)
		{
			return binary_search(elements, middle_index + 1, right_bound, target_element);
		}
	}

	return middle_index;
}

template <typename T>
void binary_insertion_sort(T elements[], const int num_elements)
{
	// Iterates after first element
	for (int i = 1; i < num_elements; i++)						
	{
		// Current element that is being sorted
		T current = elements[i];									
		// Pivot element
		int pivot = i - 1;

		// Using binary search to find position for insertion
		int insert_index = binary_search(elements, 0, i, current);
		// If current element is equal or larger than element at that position, it can be inserted after it
		if (current >= elements[insert_index])
		{
			insert_index++;
		}

		// Right-shifts elements right of insertion index
		while (pivot >= insert_index)				
		{
			elements[pivot + 1] = elements[pivot];
			pivot--;
		}
		// Inserts target element
		elements[pivot + 1] = current;
	}
}

template <typename T>
void merge(T elements[], const int left_bound, const int right_bound)
{
	unsigned int mid = (left_bound + right_bound) / 2;
	
}

template <typename T>
void merge_sort(T elements[], const int left_bound, const int right_bound, const int sub_size)
{
	if (right_bound - left_bound < sub_size)
	{
		unsigned int mid = (left_bound + right_bound) / 2;

		merge_sort(elements, left_bound, mid, sub_size);

		merge_sort(elements, mid + 1, right_bound, sub_size);
	}
}

int main()
{
	int values[] = { 5, 3, 5, 2, 9, 11, 7, 4};
	//merge(values, 0, 8);
	//long values[] = {7, 3, 4, 8, 1};
	//int values[] = {2, 3, 4, 7, 9, 23, 25, 36, 47, 55, 56, 58, 64, 77, 81};
	//int values[] = {77, 81, 9, 7, 4, 23, 25, 36, 47, 55, 64, 56, 3, 77, 81, 27};
	//binary_search(values, 0, 15, 100);
	insertion_sort(values, 2, 6);
	//binary_insertion_sort(values, 16);
	
}