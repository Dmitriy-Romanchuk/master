// Use the time structure from Exercise 9, and write a program that obtains two time values 
// from the user in 12:59:59 format, stores them in struct time variables, converts
// each one to seconds(type int), adds these quantities, converts the result back to 
// hoursminutes - seconds, stores the result in a time structure, and finally displays 
// the result in 12:59:59 format.

#include <iostream>

int main()
{
	const int sec_in_hour = 3600;
	const int sec_in_min = 60;
	char ch = ' ';
	long totalsec = 0;
	
	struct time
	{
		int hours = 0;
		int minutes = 0;
		int seconds = 0;
	};

	time time1;
	time time2;
	time time3;

	for (int i = 0; i < 2; i++)
	{
		std::cout << "Enter time in format hh/mm/ss: " << std::endl;
		if(i == 0)
			std::cin >> time1.hours >> ch >> time1.minutes >> ch >> time1.seconds;
		else if (i == 1)
			std::cin >> time2.hours >> ch >> time2.minutes >> ch >> time2.seconds;
	}
	
	totalsec = time1.hours * sec_in_hour + time1.minutes * sec_in_min + time1.seconds + time2.hours * sec_in_hour + time2.minutes * sec_in_min + time2.seconds;

	time3.hours = totalsec / sec_in_hour;
	time3.minutes = 0;
	time3.seconds = totalsec - time3.hours * sec_in_hour;

	while (time3.seconds >= 60)
	{
		time3.seconds -= 60;
		time3.minutes += 1;
	}

	std::cout << time3.hours << ":" << time3.minutes << "." << time3.seconds;

	return EXIT_SUCCESS;
}