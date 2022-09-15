// Create a structure of type date that contains three members : the month, the day of the
// month, and the year, all of type int. (Or use day - month - year order if you prefer.) Have
// the user enter a date in the format 12 / 31 / 2001, store it in a variable of type struct date,
// then retrieve the values from the variableand print them out in the same format.

#include <iostream>

int main()
{
	char ch = ' ';
	struct date
	{
		int month;
		int day;
		int year;
	};
	date user_date;

	std::cout << "Enter date in format dd/mm/yyyy: ";
	std::cin >> user_date.day >> ch >> user_date.month >> ch >> user_date.year;

	std::cout << "You Entered: " << user_date.day << ch << user_date.month << ch << user_date.year;

	return EXIT_SUCCESS;
}