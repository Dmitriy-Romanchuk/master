// Write a program, based on the sterling structure of Exercise 10 in Chapter 4, that
// obtains from the user two money amounts in old - style British format(£9:19 : 11), adds
// them, and displays the result, again in old - style format.Use three functions.The first
// should obtain a pounds - shillings - pence value from the user and return the value as a
// structure of type sterling.The second should take two arguments of type sterling and
// return a value of the same type, which is the sum of the arguments.The third should take
// a sterling structure as its argumentand display its value

#include <iostream>

struct sterling
{
	int pounds = 0;
	int shillings = 0;
	int pence = 0;
};

sterling st1;
sterling st2;

sterling user_input();
sterling total(sterling a, sterling b);
void output(sterling a);

int main()
{
	st1 = user_input();
	st2 = user_input();

	total(st1, st2);
	output(total(st1, st2));
	
	return EXIT_SUCCESS;
}

sterling user_input()
{
	sterling temp;
	char ch = ' ';
	std::cout << "Enter the amount of money (e.g. 5.10.6): ";
	std::cin >> temp.pounds >> ch >> temp.shillings >> ch >> temp.pence;
	return temp;
}

sterling total(sterling a, sterling b)
{
	sterling temp;
	temp.pence = a.pence + b.pence; 
	while (temp.pence > 11)
	{
		temp.pence -= 12;
		temp.shillings += 1;
	}

	temp.shillings += (a.shillings + b.shillings); 
	while (temp.shillings > 19)
	{
		temp.shillings -= 20;
		temp.pounds += 1;
	}
	temp.pounds += (a.pounds + b.pounds);

	return temp;
}

void output(sterling a)
{
	std::cout << "Result is " << a.pounds << "." << a.shillings << "." << a.pence;
}