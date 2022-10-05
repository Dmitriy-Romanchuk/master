// Start with the power() function of Exercise 2, which works only with type double.
// Create a series of overloaded functions with the same name that, in addition to double,
// also work with types char, int, long, and float.Write a main() program that exercises
// these overloaded functions with all argument types.

#include <iostream>

inline double power(double, int pow = 2);
inline double power(char, int pow = 2);
inline double power(int, int pow = 2);
inline double power(long, int pow = 2);
inline double power(float, int pow = 2);

int main()
{
	double dbl = 0;
	char ch = ' ';
	int i = 0;
	long l = 0;
	float fl = 0;
	int pow = 0;
	char select = ' ';
		
	std::cout << "Enter double number" << std::endl;
	std::cin >> dbl;
	std::cout << "Enter char number" << std::endl;
	std::cin >> ch;
	std::cout << "Enter int number" << std::endl;
	std::cin >> i;
	std::cout << "Enter long number" << std::endl;
	std::cin >> l;
	std::cout << "Enter float number" << std::endl;
	std::cin >> fl;

	std::cout << "Do you want to enter a power y/n: ?" << std::endl;
	std::cin >> select;
	if ('y' == select)
	{
		std::cout << "Enter power: " << std::endl;
		std::cin >> pow;
	}
	else
		pow = 2;

	std::cout << "type double: " << power(dbl, pow) << std::endl;
	std::cout << "type char: " << power(ch, pow) << std::endl;
	std::cout << "type int: " << power(i, pow) << std::endl;
	std::cout << "type long: " << power(l, pow) << std::endl;
	std::cout << "type float: " << power(fl, pow) << std::endl;
	
	return EXIT_SUCCESS;
}

double power(double num, int pow)
{
	for (int i = pow; i > 1; --i)
		num *= num;

	return num;
}

double power(char num, int pow)
{
	double temp = num -'0';

	for (int i = pow; i > 1; --i)
		temp *= temp;

	return temp;
}
	
double power(int num, int pow)
{
	for (int i = pow; i > 1; --i)
		num *= num;
	return num;
}

double power(long num, int pow)
{
	for (int i = pow; i > 1; --i)
		num *= num;

	return num;
}

double power(float num, int pow)
{
	for (int i = pow; i > 1; --i)
		num *= num;

	return num;
}
