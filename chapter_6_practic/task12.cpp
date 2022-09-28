// Note that one advantage of the OOP approach is that an entire class can be used, without
// modification, in a different program.Use the fraction class from Exercise 11 
// in a program that generates a multiplication table for fractions.Let the user input a denominator,
// and then generate all combinations of two such fractions that are between 0 and 1, and
// multiply them together.Here’s an example of the output if the denominator is 6:

#include <iostream>
#include <cmath>

class fraction
{
private:
	int nominator;
	int denominator;
public:
	fraction() : nominator(1), denominator(1)
	{}
	void set_nominator(int i)
	{
		nominator = i;
	}

	int get_denominator()
	{
		return denominator;
	}

	void input_value();
	void fmul(fraction, fraction);
	void output();
	void fraction::lowterms();
};

int main()
{
	
	fraction frac; //first fraction
	frac.input_value(); // Get the value of the denominator of the first fraction
	fraction frac2 = frac; // second fraction
	fraction result; // for results of multiplication

	std::cout << '\t'; 
	
	for (int j = 1; j < frac.get_denominator(); j++) // prints the first line
	{
		frac.set_nominator(j);
		frac.output();
	}
	std::cout << std::endl;

	for (int k = 0; k < frac.get_denominator() * 8; k++) //prints a line "-". Automatic line length calculation.
	{
		std::cout << "-";
	}
	std::cout << std::endl;
	
	for (int j = 1; j < frac.get_denominator(); j++) // multiplication of fractions
	{
		frac.set_nominator(j);
		frac.output();

		for (int i = 1; i < frac.get_denominator(); i++)
		{
			frac2.set_nominator(i);
			result.fmul(frac, frac2);
			result.lowterms();
			result.output();
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}

void fraction::input_value()
{
	std::cout << "Enter denominator: ";
	std::cin >> denominator;
}

void fraction::fmul(fraction first, fraction second)
{
	nominator = first.nominator * second.nominator;
	denominator = first.denominator * second.denominator;
}

void fraction::lowterms() 
{
	long tnum = 0;
	long tden = 0;
	long temp = 0;
	long gcd = 0;

	tnum = labs(nominator);
	tden = labs(denominator);
	if (tden == 0)
	{
		std::cout << "Illegal fraction : division by 0";
		exit(1);
	}
	else if (tnum == 0)
	{
		nominator = 0;
		denominator = 1;
		return;
	}

	while (tnum != 0)
	{
		if (tnum < tden)
		{
			temp = tnum; tnum = tden; tden = temp;
		}
		tnum = tnum - tden;
	}
	gcd = tden;
	nominator = nominator / gcd;
	denominator = denominator / gcd;
}

void fraction::output()
{
	std::cout << nominator << "/" << denominator << '\t';
}