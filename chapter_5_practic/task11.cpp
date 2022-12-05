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
	output(total (user_input(), user_input()));
	
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
	sterling from_user = { user_pounds, user_shillings, user_pence };

	return from_user;
}

sterling total(sterling a, sterling b)
{
	int total_sterling = (a.pounds + b.pounds) * 240 + (a.shillings + b.shillings) * 12 + a.pence + b.pence;
	
	int total_pounds = total_sterling / 240;
	int total_shillings = (total_sterling % 240) / 12;
	int total_pence = (total_sterling % 240) % 12;

	sterling result = { total_pounds, total_shillings, total_pence };

	return result;
}

void output(sterling result)
{
	std::cout << "Result is " << result.pounds << "." << result.shillings << "." << result.pence << std::endl;
}