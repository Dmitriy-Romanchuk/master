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

long time_to_secs(user_time);
user_time secs_to_time(long);

int main()
{
	std::cout << "Enter time in format hh/mm/ss: " << std::endl;
	std::cin >> time1.hours >> ch >> time1.minutes >> ch >> time1.seconds;
	totalsec = time_to_secs(time1);
	time2 = secs_to_time(totalsec);

	std::cout << time2.hours << ":" << time2.minutes << ":" << time2.seconds;

	return EXIT_SUCCESS;
}

long time_to_secs(user_time t)
{
	totalsec = t.hours * sec_in_hour + t.minutes * sec_in_min + t.seconds;
	return totalsec;
}

user_time secs_to_time(long total)
{
	time2.hours = total / sec_in_hour;
	time2.minutes = 0;
	time2.seconds = total - time2.hours * sec_in_hour;

	while (time2.seconds >= 60)
	{
		time2.seconds -= 60;
		time2.minutes += 1;
	}

	return time2;
}