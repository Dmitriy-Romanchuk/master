// Start with a program that allows the user to input a number of integers, and then stores
// them in an int array.Write a function called maxint() that goes through the array,
// element by element, looking for the largest one.The function should take as arguments
// the address of the arrayand the number of elements in it, and return the index number of
// the largest element.The program should call this function and then display the largest
// element and its index number. (See the SALES program in this chapter.)

#include <iostream>

void maxint(int[], int);

int main()
{
	const int MAX = 5;
	int myarray[MAX]{};
	
	std::cout << "Enter " << MAX << " numbers!" << std::endl << std::endl;
	for (int i = 0; i < MAX; i++)
	{
		std::cout << "Enter " << i + 1 << " number: ";
		std::cin >> myarray[i];
	}

	maxint(myarray, MAX);

	return EXIT_SUCCESS;
}

void maxint(int arr[], int size)
{
	int maximum = arr[0];
	int index = 0;
	for (int j = 1; j < size; j++)
	{
		if (maximum < arr[j])
		{
			maximum = arr[j];
			index = j;
		}
	}

	std::cout << std::endl << "Maximum number is " << maximum << " has index " << index << "!" << std::endl;
}