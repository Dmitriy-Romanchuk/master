// Revise the four - function fraction calculator from Exercise 12, Chapter 4, so that it uses
// functions for each of the four arithmetic operations.They can be called fadd(), fsub(),
// fmul(), and fdiv().Each of these functions should take two arguments of type struct
// fraction, and return an argument of the same type.

#include <iostream>

struct fraction
{
	int nominator = 0;
	int denominator = 1;
};

fraction fadd(fraction, fraction);
fraction fsub(fraction, fraction);
fraction fmul(fraction, fraction);
fraction fdiv(fraction, fraction);
void output(fraction a);

fraction first;
fraction second;
fraction third;

int main()
{
	char repeat = 'y';

	while (repeat == 'y')
	{
		char i = ' ';
		char sign = ' ';

		std::cout << "Enter first fraction : for example 1/2" << std::endl;
		std::cin >> first.nominator >> i >> first.denominator;
		std::cout << "Enter operation '+', '-', '*', '/' ";
		std::cin >> sign;
		std::cout << "Enter second fraction : for example 2/5" << std::endl;
		std::cin >> second.nominator >> i >> second.denominator;

		switch (sign) // калькулятор
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

		std::cout << "Do another(y / n) ? "; // воспрос повторить или нет
		std::cin >> repeat;
	}

	return EXIT_SUCCESS;
}

fraction fadd(fraction first, fraction second)
{
	fraction temp;
	temp.nominator = first.nominator * second.denominator + first.denominator * second.nominator;
	temp.denominator = first.denominator * second.denominator;
	return temp;
}

fraction fsub(fraction first, fraction second)
{
	fraction temp;
	temp.nominator =  first.nominator* second.denominator - first.denominator * second.nominator;
	temp.denominator = first.denominator * second.denominator;
	return temp;
}

fraction fmul(fraction first, fraction second)
{
	fraction temp;
	temp.nominator = first.nominator* second.nominator;
	temp.denominator = first.denominator* second.denominator;
	return temp;
}

fraction fdiv(fraction first, fraction second)
{
	fraction temp;
	temp.nominator = first.nominator* second.denominator;
	temp.denominator = first.denominator* second.nominator;
	return temp;
}

void output(fraction a)
{
	std::cout << "Result is: " << a.nominator << "/" << a.denominator << std::endl;
}