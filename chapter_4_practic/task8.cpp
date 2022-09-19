// Start with the fraction - adding program of Exercise 9 in Chapter 2, “C++ Programming
// Basics.” This program stores the numeratorand denominator of two fractions before
// adding them, and may also store the answer, which is also a fraction.
// Modify the program so that all fractions are stored in variables of type struct fraction, whose two
// members are the fraction’s numeratorand denominator(both type int).All fractionrelated data should be stored in structures of this type.


#include <iostream>

int main()
{
	char i = ' ';

	struct fraction
	{
		int nominator;
		int denominator;
	};

	fraction first;
	fraction second;
	fraction third;

	std::cout << "Enter first fraction : for example 1/2" << std::endl;
	std::cin >> first.nominator >> i >> first.denominator;

	std::cout << "Enter second fraction : for example 2/5" << std::endl;
	std::cin >> second.nominator >> i >> second.denominator;

	std::cout << "Result = " << (first.nominator * second.denominator + first.denominator * second.nominator) 
		<< i << (first.denominator * second.denominator) << std::endl;

	return EXIT_SUCCESS;
}

