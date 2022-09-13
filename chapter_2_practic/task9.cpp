#include <iostream>

int main()
{
	// task 9:----------------------------------------------------------------------------------
	// If you have two fractions, a / b and c / d, their sum can be obtained from the formula
	// a/b + c/d = (a*d + b*c)/(b*d) 
	// For example, 1 / 4 + 2 / 3 = (1 * 3 + 4 * 2) / 4 * 3 = 11 / 12
	// Write a program that encourages the user to enter two fractions, and then displays their
	// sum in fractional form. (You don’t need to reduce it to lowest terms.) The interaction
	// with the user might look like this:
	// Enter first fraction : 1 / 2
	// Enter second fraction : 2 / 5
	// Sum = 9 / 10
	// You can take advantage of the fact that the extraction operator ( >> ) can be chained to
	// read in more than one quantity at once : std::cin >> a >> dummychar >> b;

	
	int a = 0, b = 0, c = 0, d = 0;
	float result = 0.0f;
	char i = ' ';

	std::cout << "Enter first fraction : for example 1/2" << std::endl;
	std::cin >> a >> i >> b;
	std::cout << "Enter second fraction : for example 2/5" << std::endl;
	std::cin >> c >> i >> d;
	std::cout << "Result = " << (a * d + b * c) << i << (b * d) << std::endl << std::endl;

	return 0;
}