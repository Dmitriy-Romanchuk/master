// Start with the fraction class from Exercises 11 and 12 in Chapter 6. Write a main()
// program that obtains an arbitrary number of fractions from the user, stores them in an
// array of type fraction, averages them, and displays the result.

#include <iostream>

class fraction
{
private:
	int nominator;
	int denominator;
public:
	fraction();
	fraction(int a, int b);
	void input_value();
	void fadd(fraction);
	void fraction::fmul(fraction first, fraction second);
	void output();
	void fraction::lowterms();
};

int main()
{
	const auto MAX = 100;
	auto number{ 0 };
	fraction frac[MAX]; // array of objects of fraction class
	fraction result_summ; 
	fraction result_div; //division result

	do
	{
		std::cout << "How many fractional numbers do you want to enter? (Max = 100): ";
		std::cin >> number;
	} while (number > MAX);

	
	for (int i = 0; i < number; ++i)
	{
		frac[i].input_value();
	}

	for (int i = 0; i < number; ++i)
	{
		result_summ.fadd(frac[i]);
	}

	fraction division(1, number);
	
	result_div.fmul(result_summ, division);
	result_div.lowterms();
	result_div.output();

	return EXIT_SUCCESS;
}

fraction::fraction()
{
	nominator = 0;
	denominator = 1;
}

fraction::fraction(int a, int b)
{
	nominator = a;
	denominator = b;
}
void fraction::input_value()
{
	char i = ' ';
	std::cout << "Enter fraction : for example 1/2" << std::endl;
	std::cin >> nominator >> i >> denominator;
}

void fraction::fadd(fraction second)
{
	nominator = nominator * second.denominator + denominator * second.nominator;
	denominator = denominator * second.denominator;
}

void fraction::fmul(fraction first, fraction second)
{
	nominator = first.nominator * second.nominator;
	denominator = first.denominator * second.denominator;
}

void fraction::output()
{
	std::cout << "Result is: " << nominator << "/" << denominator << std::endl;
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