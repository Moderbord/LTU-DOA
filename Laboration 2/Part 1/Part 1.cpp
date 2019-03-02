#include "pch.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>

namespace
{
	using std::cout;
	using std::endl;
	using std::chrono::high_resolution_clock;
	using std::chrono::duration;
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
			return binary_search(elements, left_bound, middle_index, target_element);
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
void merge(T elements[], const int left_bound, const int mid, const int right_bound, bool sort_mode)
{
	// Uses either insertion sort or binary insertion sort on both sublists
	if (sort_mode)
	{
		insertion_sort(elements, left_bound, mid);
		insertion_sort(elements, mid, right_bound);
	}
	else
	{
		binary_insertion_sort(elements, left_bound, mid);
		binary_insertion_sort(elements, mid, right_bound);
	}
	// Merges the two sublist. Takes up to 2(N * log(N)) comparison and element swaps
	std::inplace_merge(&elements[left_bound], &elements[mid], &elements[right_bound]);
}

template <typename T>
void merge_sort(T elements[], const int left_bound, const int right_bound, const int sub_size, bool sort_mode)
{
	// If the list contains more elements than the specified sub size
	if (right_bound - left_bound > sub_size)
	{
		// Middle index divider
		unsigned int mid = (left_bound + right_bound) / 2;
		// Recursively calls function on both sides on the list using middle divider, thus creating sublists
		merge_sort(elements, left_bound, mid, sub_size, sort_mode);
		merge_sort(elements, mid, right_bound, sub_size, sort_mode);
		// Sorts and merges sublists
		merge(elements, left_bound, mid, right_bound, sort_mode);
	}
}

// Class for measureing average operation time
class Counter
{
private:
	double sum = 0;
	double num = 0;
public:
	void add(double d)
	{
		sum += d;
		num++;
	}
	double get_average_ms()
	{
		return sum * 1000 / num;
	}
};

template <typename T>
void dual_merge_sort(T elements[], const int left_bound, const int right_bound, const int sub_size, Counter &aSort, Counter &bSort)
{
	bool mode_insertion_sort = true;
	bool mode_binary_insertion_sort = false;

	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;

	unsigned int mid = (left_bound + right_bound) / 2;

	// Left block of the merge sort function, uses insertion sort 
	t1 = high_resolution_clock::now();
	merge_sort(elements, left_bound, mid, sub_size, mode_insertion_sort);
	t2 = high_resolution_clock::now();
	aSort.add(std::chrono::duration_cast<duration<double>>(t2 - t1).count());

	// Right block of the merge sort function, uses binary insertion sort
	t1 = high_resolution_clock::now();
	merge_sort(elements, mid, right_bound, sub_size, mode_binary_insertion_sort);
	t2 = high_resolution_clock::now();
	bSort.add(std::chrono::duration_cast<duration<double>>(t2 - t1).count());

	// Final merge
	merge(elements, left_bound, mid, right_bound, mode_insertion_sort);
}

int main()
{
	/// Test variables
	const unsigned int num_elements = 10000;
	const unsigned int num_generations = 1;
	//const unsigned int split_values[] = { 2, 4, 8, 16, 32, 64, 128, 254, 3, 5, 10, 15, 20, 30, 40, 50};
	const unsigned int split_values[] = { 500 };
	const unsigned int num_tests = 5;

	int values[num_elements] = {};
	std::random_device rand;
	
	for (const int split_size : split_values)
	{
		for (int k = 0; k < num_tests; k++)
		{ 
			Counter aSort;
			Counter bSort;
			// Number of times a list is generated and sorted
			for (int j = 0; j < num_generations; j++)
			{	// Generates a number of elements to the list
				for (int i = 0; i < num_elements; i++)
				{
					int num = rand() % 5000;
					values[i] = num;
				}
				// Sorts list
				dual_merge_sort(values, 0, num_elements, split_size, aSort, bSort);
			}
			cout << "Split size: " << split_size << "\t" << "Insertion sort: " << aSort.get_average_ms() << " ms. \tBinary Insertion Sort: " << bSort.get_average_ms() << endl;
		}
		cout << endl;
	}
}