// Write a function called hms_to_secs() that takes three int values—for hours, minutes,
// and seconds—as arguments, and returns the equivalent time in seconds(type long).
// Create a program that exercises this function by repeatedly obtaining a time value in
// hours, minutes, and seconds from the user(format 12:59 : 59), calling the function, and
// displaying the value of seconds it returns.

#include <iostream>

inline int hms_to_secs(int h, int m, int s);

int main()
{
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	char ch = ' ';
	char select = 'y';

	do
	{
		std::cout << "Enter time in format hh/mm/ss: ";
		std::cin >> hours >> ch >> minutes >> ch >> seconds;
		std::cout << hms_to_secs(hours, minutes, seconds) << " seconds" << std::endl;
		std::cout << "Repeat? y/n: ";
		std::cin >> select;
	}

	while ('y' == select);

	return EXIT_SUCCESS;
}

int hms_to_secs(int h, int m, int s)
{
	return h * 3600 + m * 60 + s;
}