// Create a function called amax() that returns the value of the largest element in an array.
// The arguments to the function should be the address of the arrayand its size.Make this
// function into a template so it will work with an array of any numerical type.Write a
// main() program that applies this function to arrays of various types.

#include <iostream>

template<class T>
T amax(T* arr, int size)
{
	T temp = 0;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] > temp)
		{
			temp = arr[i];
		}
	}
	return temp;
}

int main()
{
	int arr1[] = { 5, 3, 100, 101, 55 };
	long arr2[] = { 15, 23, 2100, 3101, 55 };
	float arr3[] = { 1.5, 2.3, 21.0, 310.1, 5.5 };

	std::cout << "Max value in arr1: " << amax(arr1, 5) << std::endl;
	std::cout << "Max value in arr2: " << amax(arr2, 5) << std::endl;
	std::cout << "Max value in arr3: " << amax(arr3, 5) << std::endl;

	return EXIT_SUCCESS;
}