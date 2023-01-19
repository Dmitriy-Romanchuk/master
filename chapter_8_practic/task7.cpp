//Modify the fraction class in the four - function fraction calculator from Exercise 11 in
//Chapter 6 so that it uses overloaded operators for addition, subtraction, multiplication,
//and division. (Remember the rules for fraction arithmetic in Exercise 12 in Chapter 3,
//“Loopsand Decisions.”) Also overload the == and != comparison operators, and use them
//to exit from the loop if the user enters 0 / 1, 0 / 1 for the values of the two input fractions.
//You may want to modify the lowterms() function so that it returns the value of its argument
//reduced to lowest terms.This makes it more useful in the arithmetic functions, where it
//can be applied just before the answer is returned.

#include <iostream>
#include <cmath>

class fraction
{
private:
	int numerator;
	int denominator;
public:
	fraction() : numerator(0), denominator(1)
	{}
	fraction(int a, int b) : numerator(a), denominator(b)
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
	fraction first;
	fraction second;
	fraction third;
	fraction test(0, 1);
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

void fraction::input_value()
{
	char i = ' ';

	std::cout << "Enter fraction : for example 1/2" << std::endl;
	std::cin >> numerator >> i >> denominator;
}

fraction fraction::operator+ (fraction second)
{
	int const num = numerator * second.denominator + denominator * second.numerator;
	int const denom = denominator * second.denominator;
	return  { num, denom };
}

fraction fraction::operator- (fraction second)
{
	int const num = numerator * second.denominator - denominator * second.numerator;
	int const denom = denominator * second.denominator;
	return  { num, denom };
}

fraction fraction::operator* (fraction second)
{
	int const num = numerator * second.numerator;
	int const denom = denominator * second.denominator;
	return  { num, denom };
}

fraction fraction::operator/ (fraction second)
{
	int const num = numerator * second.denominator;
	int const denom = denominator * second.numerator;
	return  { num, denom };
}

bool fraction::operator== (fraction test) const
{
	if ((numerator == test.numerator) && (denominator == test.denominator))
		return true;
	else
		return false;
}

bool fraction::operator!= (fraction test) const
{
	if ((numerator == test.numerator) && (denominator == test.denominator))
		return false;
	else
		return true;
}

void fraction::lowterms() // change ourself to lowest terms
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

void fraction::output()
{
	std::cout << "Result is: " << numerator << "/" << denominator << std::endl;
}