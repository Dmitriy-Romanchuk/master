#include <iostream>

int main()
{
	// Task1:----------------------------------------------------------------------------------
	// Assuming there are 7.481 gallons in a cubic foot, write a program that asks the user to
	// enter a number of gallons, and then displays the equivalent in cubic feet

	const float ratio = 7.481f;
	float user_input = 0.0f;

	std::cout << "Enter the number of gallons:" << std::endl;
	std::cin >> user_input;
	std::cout << user_input << " gallons = " << user_input / ratio << " cubic pounds" << std::endl << std::endl;

	return 0;
}