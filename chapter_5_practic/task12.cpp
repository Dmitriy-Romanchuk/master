// Revise the four - function fraction calculator from Exercise 12, Chapter 4, so that it uses
// functions for each of the four arithmetic operations.They can be called fadd(), fsub(),
// fmul(), and fdiv().Each of these functions should take two arguments of type struct
// fraction, and return an argument of the same type.

#include <iostream>

struct fraction
{
	int numerator = 0;
	int denominator = 1;
};

auto fadd(fraction, fraction);
auto fsub(fraction, fraction);
auto fmul(fraction, fraction);
auto fdiv(fraction, fraction);
void output(fraction a);

int main()
{
	fraction first;
	fraction second;
	fraction third;
	char repeat = 'y';

	while (repeat == 'y')
	{
		char i = ' ';
		char sign = ' ';

		std::cout << "Enter first fraction : for example 1/2" << std::endl;
		std::cin >> first.numerator >> i >> first.denominator;
		std::cout << "Enter operation '+', '-', '*', '/' ";
		std::cin >> sign;
		std::cout << "Enter second fraction : for example 2/5" << std::endl;
		std::cin >> second.numerator >> i >> second.denominator;

		switch (sign) // calculator
		{
		case '+':
			output(fadd(first, second));
			break;
		case '-':
			output(fsub(first, second));
			break;
		case '*':
			output(fmul(first, second));
			break;
		case '/':
			output(fdiv(first, second));
			break;
		default:
			std::cout << "Warning: \"" << sign << "\" is unknown operator" << std::endl;
		}

		std::cout << "Do another(y / n) ? "; // yes/no question
		std::cin >> repeat;
	}

	return EXIT_SUCCESS;
}

auto fadd(fraction first, fraction second)
{
	int const numerator = first.numerator * second.denominator + first.denominator * second.numerator;
	int const denominator = first.denominator * second.denominator;
	return fraction { numerator, denominator };
}

auto fsub(fraction first, fraction second)
{
	int const numerator =  first.numerator* second.denominator - first.denominator * second.numerator;
	int const denominator = first.denominator * second.denominator;
	return fraction{ numerator, denominator };
}

auto fmul(fraction first, fraction second)
{
	int const numerator = first.numerator* second.numerator;
	int const denominator = first.denominator* second.denominator;
	return fraction { numerator, denominator };
}

auto fdiv(fraction first, fraction second)
{
	int const numerator = first.numerator* second.denominator;
	int const denominator = first.denominator* second.numerator;
	return fraction { numerator, denominator };
}

void output(fraction a)
{
	std::cout << "Result is: " << a.numerator << "/" << a.denominator << std::endl;
}