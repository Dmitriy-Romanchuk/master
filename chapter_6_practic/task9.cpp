// Transform the fraction structure from Exercise 8 in Chapter 4 into a fraction class.
// Member data is the fraction’s numerator and denominator.Member functions should
// accept input from the user in the form 3 / 5, and output the fraction’s value in the same
// format.Another member function should add two fraction values.Write a main() program
// that allows the user to repeatedly input two fractionsand then displays their sum.After
// each operation, ask whether the user wants to continue.

#include <iostream>

class fraction
{
private:
	int nominator;
	int denominator;
	char i;
public:
	fraction() : nominator(1), denominator(1), i(' ')
	{}
	void setdata()
	{
		std::cout << "Enter fraction : for example 1/2" << std::endl;
		std::cin >> nominator >> i >> denominator;
	}
	void add(fraction a, fraction b)
	{
		nominator = a.nominator * b.denominator + a.denominator * b.nominator;
		denominator = a.denominator * b.denominator;
	}

	void showdata()
	{
		std::cout << "Result = " << nominator << "/" << denominator << std::endl;
	}
};

int main()
{
	char select = 'y';
	fraction first;
	fraction second;
	fraction third;

	do
	{
		first.setdata();
		second.setdata();

		third.add(first, second);

		third.showdata();

		std::cout << "Repeat? y/n: ";
		std::cin >> select;

	} while ('y' == select);

	return EXIT_SUCCESS;
}
