#include <iostream>

int main()
{
	// task3:-----------------------------------------------------------------------------------
	// Write a program that generates the following output :
	
	//	10
	//	20
	//	19
	
	// Use an integer constant for the 10, an arithmetic assignment operator to generate the 20,
	// and a decrement operator to generate the 19.

	int number = 10;

	std::cout << number << std::endl;
	std::cout << (number += 10) << std::endl;
	std::cout << --number << std::endl << std::endl;

	return 0;
}