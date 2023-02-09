// Start with the frac classand the four - function fraction calculator of Exercise 7 in
// Chapter 8. Make the frac class into a template so it can be instantiated using different
// data types for the numeratorand denominator.These must be integer types, which pretty
// much restricts you to char, short, int, and long(unless you develop an integer type of
// your own).In main(), instantiate a class frac<char>and use it for the four - function calculator.
// Class frac<char> will take less memory than frac<int>, but won’t be able to handle large fractions.

#include <iostream>
#include <cmath>

template<class T>
class fraction
{
private:
	T numerator;
	T denominator;
public:
	fraction()
	{}
	fraction(T a, T b) : numerator(a), denominator(b)
	{}
	void input_value();
	void output();
	void fraction::lowterms();
	fraction operator+ (fraction);
	fraction operator- (fraction);
	fraction operator* (fraction);
	fraction operator/ (fraction);
	bool operator== (fraction) const;
	bool operator!= (fraction) const;
};

int main()
{
	fraction<int> first;
	fraction<int> second;
	fraction<int> third;
	fraction<int> test(0, 1);
	char sign = ' ';
	char repeat = 'y';

	while (repeat == 'y')
	{
		first.input_value();

		std::cout << "Enter operation '+', '-', '*', '/' ";
		std::cin >> sign;

		second.input_value();

		if (first == test || second == test)
		{
			std::cout << "One or all of fraction are 0/1" << std::endl;
			break;
		}

		switch (sign)
		{
		case '+':
			third = first + second;
			third.lowterms();
			third.output();
			break;
		case '-':
			third = first - second;
			third.lowterms();
			third.output();
			break;
		case '*':
			third = first * second;
			third.lowterms();
			third.output();
			break;
		case '/':
			third = first / second;
			third.lowterms();
			third.output();
			break;
		default:
			std::cout << "Warning: \"" << sign << "\" is unknown operator" << std::endl;
		}

		std::cout << "Do another(y / n)? ";
		std::cin >> repeat;
	}

	return EXIT_SUCCESS;
}

template<class T>
void fraction<T>::input_value()
{
	char i = ' ';

	std::cout << "Enter fraction : for example 1/2" << std::endl;
	std::cin >> numerator >> i >> denominator;
}

template<class T>
fraction<T> fraction<T>::operator+ (fraction second)
{
	int const num = numerator * second.denominator + denominator * second.numerator;
	int const denom = denominator * second.denominator;
	return  { num, denom };
}

template<class T>
fraction<T> fraction<T>::operator- (fraction second)
{
	int const num = numerator * second.denominator - denominator * second.numerator;
	int const denom = denominator * second.denominator;
	return  { num, denom };
}

template<class T>
fraction<T> fraction<T>::operator* (fraction second)
{
	int const num = numerator * second.numerator;
	int const denom = denominator * second.denominator;
	return  { num, denom };
}

template<class T>
fraction<T> fraction<T>::operator/ (fraction second)
{
	int const num = numerator * second.denominator;
	int const denom = denominator * second.numerator;
	return  { num, denom };
}

template<class T>
bool fraction<T>::operator== (fraction test) const
{
	if ((numerator == test.numerator) && (denominator == test.denominator))
		return true;
	else
		return false;
}

template<class T>
bool fraction<T>::operator!= (fraction test) const
{
	if ((numerator == test.numerator) && (denominator == test.denominator))
		return false;
	else
		return true;
}

template<class T>
void fraction<T>::lowterms() // change ourself to lowest terms
{
	long tnum = 0;
	long tden = 0;
	long temp = 0;
	long gcd = 0;

	tnum = labs(numerator); // use non-negative copies
	tden = labs(denominator); // (needs cmath)
	if (tden == 0) // check for n/0
	{
		std::cout << "Illegal fraction : division by 0";
		exit(1);
	}
	else if (tnum == 0) // check for 0/n
	{
		numerator = 0;
		denominator = 1;
		return;
	}

	// this ‘while’ loop finds the gcd of tnum and tden
	while (tnum != 0)
	{
		if (tnum < tden) // ensure numerator larger
		{
			temp = tnum; tnum = tden; tden = temp;
		} // swap them
		tnum = tnum - tden; // subtract them
	}
	gcd = tden; // this is greatest common divisor
	numerator = numerator / gcd; // divide both num and den by gcd
	denominator = denominator / gcd; // to reduce frac to lowest terms
}

template<class T>
void fraction<T>::output()
{
	std::cout << "Result is: " << numerator << "/" << denominator << std::endl;
}