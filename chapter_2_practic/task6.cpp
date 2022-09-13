#include <iostream>

int main()
{
	// task 6:----------------------------------------------------------------------------------
	// On a certain day the British pound was equivalent to $1.487 U.S., the French franc was
	// $0.172, the German deutschemark was $0.584, and the Japanese yen was $0.00955.
	// Write a program that allows the user to enter an amount in dollars, and then displays this
	// value converted to these four other monetary units.

	float input = 0.0f; // for user input
	float british_pound = 1.487f;
	float french_franc = 0.172f;
	float german_deutschemark = 0.584;
	float japanese_yen = 0.00955;

	std::cout << "Enter count of U.S., $" << std::endl;
	std::cin >> input;

	std::cout << input << "$ :" << std::endl;
	std::cout << input / british_pound << " british_pounds" << std::endl;
	std::cout << input / french_franc << " french_franc" << std::endl;
	std::cout << input / german_deutschemark << " german_deutschemark" << std::endl;
	std::cout << input / japanese_yen << " japanese_yen" << std::endl << std::endl;


	return 0;
}