// Raising a number n to a power p is the same as multiplying n by itself p times.Write a
// function called power() that takes a double value for nand an int value for p, and
// returns the result as a double value.Use a default argument of 2 for p, so that if this
// argument is omitted, the number n will be squared.Write a main() function that gets values from the user to test this function.


#include <iostream>

inline double power (double num, int pow = 2);

int main()
{
	double number = 0;
	double result = 0;
	int pow = 0;
	char ch = ' ';

	std::cout << "Enter number: ";
	std::cin >> number;
	std::cout << "Do you want to enter a power y/n: ?";
	std::cin >> ch;
	if ('y' == ch)
	{
		std::cout << "Enter power: ";
		std::cin >> pow;
		result = power(number, pow);
	}
	else
		result = power(number);

	std::cout << "Result is " << result << std::endl;

	return EXIT_SUCCESS;
}

double power(double num, int pow)
{
	for (int i = pow; i > 1; i--)
		num *= num;

	return num;
}

