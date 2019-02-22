#include "pch.h"
#include <iostream>
#include <algorithm>
#include <chrono>

namespace
{
	using std::cout;
	using std::endl;
	using std::chrono::high_resolution_clock;
}

template <typename T>
void insertion_sort(T elements[], const int left_bound, const int right_bound)
{
	// Iterates after left bound element
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
void binary_insertion_sort(T elements[], const int left_bound, const int right_bound)
{
	// Iterates after left bound element
	for (int i = left_bound + 1; i < right_bound; i++)						
	{
		// Current element that is being sorted
		T current = elements[i];									
		// Pivot element
		int pivot = i - 1;

		// Using binary search to find position for insertion
		int insert_index = binary_search(elements, left_bound, i, current);
		// If current element is equal or larger than element at that position, it can be inserted after it
		if (current >= elements[insert_index])
		{
			insert_index++;
		}

		// Right-shifts elements right of insertion index
		while (pivot >= left_bound && pivot >= insert_index)				
		{
			elements[pivot + 1] = elements[pivot];
			pivot--;
		}
		// Inserts target element
		elements[pivot + 1] = current;
	}
}

template <typename T>
void merge(T elements[], const int left_bound, const int mid, const int right_bound, bool switch_sort)
{

	if (switch_sort)
	{
		insertion_sort(elements, left_bound, mid);
		insertion_sort(elements, mid, right_bound);
	}
	else
	{
		binary_insertion_sort(elements, left_bound, mid);
		binary_insertion_sort(elements, mid, right_bound);
	}

	std::inplace_merge(&elements[left_bound], &elements[mid], &elements[right_bound]);
}

template <typename T>
void merge_sort(T elements[], const int left_bound, const int right_bound, const int sub_size, bool switch_sort)
{
	if (right_bound - left_bound > sub_size)
	{
		unsigned int mid = (left_bound + right_bound) / 2;

		merge_sort(elements, left_bound, mid, sub_size, switch_sort);

		merge_sort(elements, mid, right_bound, sub_size, switch_sort);

		merge(elements, left_bound, mid, right_bound, switch_sort);
	}
}

template <typename T>
void dual_merge_sort(T elements[], const int left_bound, const int right_bound, const int sub_size)
{
	unsigned int mid = (left_bound + right_bound) / 2;

	merge_sort(elements, left_bound, mid, sub_size, false);

	merge_sort(elements, mid, right_bound, sub_size, true);

	merge(elements, left_bound, mid, right_bound, false);
}

int main()
{
	int values[] = { 5, 3, 9, 2, 5, 11, 7, 4};
	dual_merge_sort(values, 0, 8, 1);
	//long values[] = {7, 3, 4, 8, 1};
	//int values[] = {2, 3, 4, 7, 9, 23, 25, 36, 47, 55, 56, 58, 64, 77, 81};
	//int values[] = {77, 81, 9, 7, 4, 23, 25, 36, 47, 55, 64, 56, 3, 77, 81, 27};
	//binary_search(values, 0, 15, 100);
	//insertion_sort(values, 2, 6);
	//binary_insertion_sort(values, 2,6);
	
}