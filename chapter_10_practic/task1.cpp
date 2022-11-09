// Write a program that reads a group of numbers from the userand places them in an array
// of type float.Once the numbers are stored in the array, the program should average
// themand print the result.Use pointer notation wherever possible.

#include <iostream>

int main()
{
	float input_number = 0;
	int index = 0;
	char ch ='y';
	float average = 0;
	float arr[100]{};

	char* ptr_ch = &ch;
	float* ptr_input_number = &input_number;
	int* ptr_index = &index;
	float* ptr_average = &average;
	float* ptr_arr = arr;

	do
	{
		std::cout << "Enter float number:" << std::endl;
		std::cin >> *ptr_input_number;
		arr[*ptr_index] = *ptr_input_number;
		++*ptr_index;
		std::cout << "Would you like to enter another number? y/n:" << std::endl;
		std::cin >> *ptr_ch;
	} while ('y' == *ptr_ch);
	
	for (int i = 0; i <= *ptr_index; ++i)
	{
		*ptr_average += *ptr_arr++;
	}

	std::cout << "Average = " << *ptr_average / *ptr_index << std::endl;

	return EXIT_SUCCESS;
}