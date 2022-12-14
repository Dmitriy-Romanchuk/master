// Write a template function that returns the average of all the elements of an array.The
// arguments to the function should be the array nameand the size of the array(type int).
// In main(), exercise the function with arrays of type int, long, double, and char.

#include <iostream>

template <class T>
T average(T * arr, int size)
{
	T results = 0;
	for (int i = 0; i < size; ++i)
	{
		results += arr[i];
	}
	results = results / size;
	return results;
}

int main()
{
	const int MAX = 5;
	int iArr[] = { 5, 6, 7, 2, 1 };
	long lArr[] = { 3, 2, 8, 2, 1 };
	double dArr[] = { 3.0, 2.5, 8.3, 2.9, 1.0 };
	char cArr[] = { 3, 2, 5, 9, 0 };

	std::cout << average(iArr, MAX) << std::endl;
	std::cout << average(lArr, MAX) << std::endl;
	std::cout << average(dArr, MAX) << std::endl;
	std::cout << static_cast<int>(average(cArr, MAX)) << std::endl;

	return EXIT_SUCCESS;
}