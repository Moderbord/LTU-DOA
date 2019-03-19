#include "pch.h"
#include <iostream>
#include <chrono>
#include <random>

namespace {
	using std::cout;
	using std::endl;
	using std::chrono::high_resolution_clock;
	using std::chrono::duration;
}

void maximized_indices(int arr[], int left_bound, int right_bound, int &min, int &max)
{

	if (right_bound - left_bound > 0)
	{
		int mid = (right_bound + left_bound) / 2;

		maximized_indices(arr, left_bound, mid, min, max);

		maximized_indices(arr, mid + 1, right_bound, min, max);

	}

	min = min < arr[left_bound] ? min : arr[left_bound];
	max = max > arr[left_bound] ? max : arr[left_bound];
}

int main()
{
	const unsigned int num_elements = 100000;

	int min = 5000;
	int max = 0;

	int indices[num_elements] = {};
	std::random_device rand;

	for (int i = 0; i < num_elements; i++)
	{
		int num = rand() % 300;
		indices[i] = num;
	}

	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;

	t1 = high_resolution_clock::now();
	maximized_indices(indices, 0, num_elements - 1, min, max);
	t2 = high_resolution_clock::now();
	cout << std::chrono::duration_cast<duration<double>>(t2 - t1).count() << " micro seconds\n";

}