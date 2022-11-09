// Suppose you have a main() with three local arrays, all the same sizeand type(say
// float).The first two are already initialized to values.Write a function called
// addarrays() that accepts the addresses of the three arrays as arguments; 
// adds the contents of the first two arrays together, element by element;and places the results in the
// third array before returning.A fourth argument to this function can carry the size of the
// arrays.Use pointer notation throughout; the only place you need brackets is in defining
// the arrays.

#include <iostream>

void addarrays(float*, float*, float*, int);
void showdata(float*, int size);

int main()
{
	const int size = 4;
	float arr1[size] = { 2.6, 3.7 , 4.8, 5.9 };
	float arr2[size] = { 7.5, 6.5 , 5.5, 4.5 };
	float arr3[size]{};

	addarrays(arr1, arr2, arr3, size);
	showdata(arr3, size);

	return EXIT_SUCCESS;
}

void addarrays(float* arr1, float* arr2, float* arr3, int size)
{
	for (int i = 0; i < size; i++)
		*arr3++ = *arr1++ + *arr2++;
}

void showdata(float* arr3, int size)
{
	for (int i = 0; i < size; ++i)
		std::cout << *arr3++ << std::endl;
}