// Create a time class that includes integer member values for hours, minutes, and seconds.
// Make a member function get_time() that gets a time value from the user, and a function
// put_time() that displays a time in 12 :59 : 59 format.Add error checking to the get_time()
// function to minimize user mistakes.This function should request hours, minutes, and seconds separately, and check each one for ios error status flagsand the correct range.Hours
// should be between 0 and 23, and minutesand seconds between 0 and 59. Don’t input these
// values as strings and then convert them; read them directly as integers.This implies that
// you won’t be able to screen out entries with superfluous decimal points, as does the
// ENGL_IO program in this chapter, but we’ll assume that’s not important.
// In main(), use a loop to repeatedly get a time value from the user with get_time() and
// then display it with put_time(), like this:
// Enter hours : 11
// Enter minutes : 59
// Enter seconds : 59
// time = 11 : 59 : 59
// Do another(y / n) ? y
// Enter hours : 25
// Hours must be between 0 and 23
// Enter hours : 1
// Enter minutes : 10
// Enter seconds : five
// Incorrect seconds input
// Enter seconds : 5
// time = 1 : 10 : 05

#include <iostream>
#include <fstream>

class user_time
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	void get_time();
	void show_time() const;
};

int main()
{
	char ch = 'y';

	user_time time;
	do
	{
		time.get_time();
		time.show_time();
		std::cout << "again? y/n";
		std::cin >> ch;
	} while (ch == 'y');

	return EXIT_SUCCESS;
}

void user_time::get_time()
{
	const int limit_hours = 23;
	const int limit_minutes = 59;
	const int limit_seconds = 59;

	while (true)
	{
		std::cout << "Enter hours: ";
		std::cin >> hours;

		if (std::cin.good())
		{
			if (hours >= 0 && hours <= limit_hours)
			{
				std::cin.ignore(10, '\n');
				break;
			}
			else
				std::cout << "Hours must be 0 - " << limit_hours << std::endl;
		}
	}
	while (true)
	{
		std::cout << "Enter minutes: ";
		std::cin >> minutes;

		if (std::cin.good())
		{
			if (minutes >= 0 && minutes <= limit_minutes)
			{
				std::cin.ignore(10, '\n');
				break;
			}
			else
				std::cout << "Minutes must be 0 - " << limit_minutes << std::endl;
		}
	}
	while (true)
	{
		std::cout << "Enter seconds: ";
		std::cin >> seconds;

		if (std::cin.good())
		{
			if (seconds >= 0 && seconds <= limit_seconds)
			{
				std::cin.ignore(10,  '\n');
				break;
			}
			else
				std::cout << "Seconds must be 0 - " << limit_seconds << std::endl;
		}
	}
}

void user_time::show_time() const
{
	std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
}