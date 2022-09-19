// Create a structure called time.Its three members, all type int, should be called hours,
// minutes, and seconds.Write a program that prompts the user to enter a time value in
// hours, minutes, and seconds.This can be in 12:59:59 format, or each number can be
// entered at a separate prompt(“Enter hours : ”, and so forth).The program should then
// store the time in a variable of type struct time, and finally print out the total number of
// seconds represented by this time value :
// long totalsecs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds

#include <iostream>

int main()
{
	char ch = ' ';
	long totalsec = 0;

	struct time
	{
		int hours;
		int minutes;
		int seconds;
	};

	time time1;

	std::cout << "Enter time in format hh/mm/ss: ";
	std::cin >> time1.hours >> ch >> time1.minutes >> time1.seconds;

	totalsec = time1.hours * 3600 + time1.minutes * 60 + time1.seconds;

	std::cout << totalsec;

	return EXIT_SUCCESS;
}