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