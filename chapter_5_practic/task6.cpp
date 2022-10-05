// Start with the program from Exercise 11 in Chapter 4, “Structures, ” which adds two
// struct time values.Keep the same functionality, but modify the program so that it uses
// two functions.The first, time_to_secs(), takes as its only argument a structure of type
// time, and returns the equivalent in seconds(type long).The second function,
// secs_to_time(), takes as its only argument a time in seconds(type long), and returns a
// structure of type time.

#include <iostream>

struct user_time
{
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
};

user_time time1;
user_time time2;

const int sec_in_hour = 3600;
const int sec_in_min = 60;
char ch = ' ';
long totalsec = 0;

long time_to_secs(user_time time1);
user_time secs_to_time(long total);

int main()
{
	std::cout << "Enter time in format hh/mm/ss: " << std::endl;
	std::cin >> time1.hours >> ch >> time1.minutes >> ch >> time1.seconds;
	totalsec = time_to_secs(time1);
	time2 = secs_to_time(totalsec);

	std::cout << time2.hours << ":" << time2.minutes << ":" << time2.seconds;

	return EXIT_SUCCESS;
}

long time_to_secs(user_time time1)
{
	totalsec = time1.hours * sec_in_hour + time1.minutes * sec_in_min + time1.seconds;
	return totalsec;
}

user_time secs_to_time(long total)
{
	time2.hours = total / sec_in_hour;
	time2.seconds = total % sec_in_hour; 
	time2.minutes = time2.seconds / 60;  
	time2.seconds = time2.seconds % 60;
	
	return time2;
}