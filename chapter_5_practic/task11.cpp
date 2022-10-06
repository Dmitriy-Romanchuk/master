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

sterling user_input();
sterling total(sterling a, sterling b);
void output(sterling result);

int main()
{
	sterling st1 = user_input();
	sterling st2 = user_input();

	total(st1, st2);
	output(total(st1, st2));
	
	return EXIT_SUCCESS;
}

sterling user_input()
{
	int user_pounds = 0;
	int user_shillings = 0;
	int user_pence = 0;
	char ch = ' ';

	std::cout << "Enter the amount of money (e.g. 5.10.6): ";
	std::cin >> user_pounds >> ch >> user_shillings >> ch >> user_pence;

	return { user_pounds, user_shillings, user_pence };
}

sterling total(sterling a, sterling b)
{
	int total_pounds = 0;
	int total_shillings = 0;
	int total_pence = 0;
	
	total_pence = a.pence + b.pence;
	while (total_pence > 11)
	{
		total_pence -= 12;
		total_shillings += 1;
	}

	total_shillings += (a.shillings + b.shillings);
	while (total_shillings > 19)
	{
		total_shillings -= 20;
		total_pounds += 1;
	}
	total_pounds += (a.pounds + b.pounds);

	sterling result = { total_pounds, total_shillings, total_pence };
	return result;

}

void output(sterling result)
{
	std::cout << "Result is " << result.pounds << "." << result.shillings << "." << result.pence << std::endl;
}