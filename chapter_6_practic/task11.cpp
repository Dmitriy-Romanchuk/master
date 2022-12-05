// Modify the four - function fraction calculator of Exercise 12 in Chapter 5 to use a
// fraction class rather than a structure.There should be member functions for inputand
// output, as well as for the four arithmetical operations.While you’re at it, you might as
// well install the capability to reduce fractions to lowest terms.Here’s a member function
// that will reduce the fraction object of which it is a member to lowest terms.It finds the
// greatest common divisor(gcd) of the fraction’s numeratorand denominator, and uses this
// gcd to divide both numbers.
// void fraction::lowterms() // change ourself to lowest terms
// {
// 		long tnum, tden, temp, gcd;
// 		tnum = labs(num); // use non-negative copies
// 		tden = labs(den); // (needs cmath)
// 		if (tden == 0) // check for n/0
//		{
//			cout << “Illegal fraction : division by 0”; exit(1);
//	 	}
//		else if (tnum == 0) // check for 0/n
//		{
// 			num = 0; den = 1; return;
// 		}
//		// this ‘while’ loop finds the gcd of tnum and tden
//		while (tnum != 0)
//		{
// 			if (tnum < tden) // ensure numerator larger
// 			{
// 				temp = tnum; tnum = tden; tden = temp;
// 			} // swap them
// 			tnum = tnum - tden; // subtract them
// 		}
//		gcd = tden; // this is greatest common divisor
//		num = num / gcd; // divide both num and den by gcd
//		den = den / gcd; // to reduce frac to lowest terms
//	}
// You can call this function at the end of each arithmetic function, or just before you perform output.You’ll also need the usual member functions : four arithmetic operations,
// input, and display.You may find a two - argument constructor useful.

#include <iostream>
#include <cmath>

class fraction
{
private:
	int nominator;
	int denominator;
public:
	fraction() : nominator(0), denominator(1)
	{}
	fraction(int a, int b) : nominator(a), denominator(b)
	{}
	void input_value();
	void fadd(fraction, fraction);
	void fsub(fraction, fraction);
	void fmul(fraction, fraction);
	void fdiv(fraction, fraction);
	void output();
	void fraction::lowterms();
};

fraction first;
fraction second;
fraction third;
char sign = ' ';

int main()
{
	char repeat = 'y';

	while (repeat == 'y')
	{
		first.input_value();

		std::cout << "Enter operation '+', '-', '*', '/' ";
		std::cin >> sign;

		second.input_value();
		
		switch (sign)
		{
		case '+':
			third.fadd(first, second);
			third.lowterms();
			third.output();
			break;
		case '-':
			third.fsub(first, second);
			third.lowterms();
			third.output();
			break;
		case '*':
			third.fmul(first, second);
			third.lowterms();
			third.output();
			break;
		case '/':
			third.fdiv(first, second);
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
	std::cin >> nominator >> i >> denominator;
}

void fraction::fadd(fraction first, fraction second)
{
	nominator = first.nominator * second.denominator + first.denominator * second.nominator;
	denominator = first.denominator * second.denominator;
}

void fraction::fsub(fraction first, fraction second)
{
	nominator = first.nominator * second.denominator - first.denominator * second.nominator;
	denominator = first.denominator * second.denominator;
}

void fraction::fmul(fraction first, fraction second)
{
	nominator = first.nominator * second.nominator;
	denominator = first.denominator * second.denominator;
}

void fraction::fdiv(fraction first, fraction second)
{
	nominator = first.nominator * second.denominator;
	denominator = first.denominator * second.nominator;
}


void fraction::lowterms() // change ourself to lowest terms
{
	long tnum = 0;
	long tden = 0;
	long temp = 0;
	long gcd = 0;

	tnum = labs(nominator); // use non-negative copies
	tden = labs(denominator); // (needs cmath)
	if (tden == 0) // check for n/0
	{
		std::cout << "Illegal fraction : division by 0"; 
		exit(1);
 	}
	else if (tnum == 0) // check for 0/n
	{
		nominator = 0;
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
	nominator = nominator / gcd; // divide both num and den by gcd
	denominator = denominator / gcd; // to reduce frac to lowest terms
}

void fraction::output()
{
	std::cout << "Result is: " << nominator << "/" << denominator << std::endl;
}