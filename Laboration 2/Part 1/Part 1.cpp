#include "pch.h"
#include <iostream>


template <typename T>
void insertion_sort(T elements[], const int num_elements)
{
	// Iterates after first element
	for (int i = 1; i < num_elements; i++)						
	{
		// Current element that is being sorted
		T current = elements[i];									
		// Element being compared
		int pivot = i - 1;

		// Right-shifts elements that is less than current
		while (pivot >= 0 && current < elements[pivot])				
		{
			elements[pivot + 1] = elements[pivot];
			pivot--;
		}
		// Inserts target element
		elements[pivot + 1] = current;
	}
}

int main()
{
	long values[] = {7, 3, 4, 8, 1};
	insertion_sort(values, 5);
	
}