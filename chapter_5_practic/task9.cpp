//Repeat Exercise 8, but instead of two int variables, have the swap() function interchange two struct time values(see Exercise 6)

#include <iostream>

struct user_time
{
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
};

inline void swap(user_time& a, user_time& b);

int main()
{
	user_time time1;
	user_time time2;
	char ch = ' ';

	std::cout << "Enter time in format hh/mm/ss: " << std::endl;
	std::cin >> time1.hours >> ch >> time1.minutes >> ch >> time1.seconds;

	std::cout << "Enter time in format hh/mm/ss: " << std::endl;
	std::cin >> time2.hours >> ch >> time2.minutes >> ch >> time2.seconds;

	std::cout << '\n' << "First time = " << time1.hours << ch << time1.minutes << ch << time1.seconds << std::endl;
	std::cout << "Second time = " << time2.hours << ch << time2.minutes << ch << time2.seconds << std::endl;

	std::cout << "Swap the values of variables...." << std::endl << std::endl;

	swap(time1, time2);

	std::cout << "First time = " << time1.hours << ch << time1.minutes << ch << time1.seconds << std::endl;
	std::cout << "Second time = " << time2.hours << ch << time2.minutes << ch << time2.seconds << std::endl;

	return EXIT_SUCCESS;
}

void swap(user_time& a, user_time& b)
{
	int temp = a.hours;
	a.hours = b.hours;
	b.hours = temp;

	temp = a.minutes;
	a.minutes = b.minutes;
	b.minutes = temp;

	temp = a.seconds;
	a.seconds = b.seconds;
	b.seconds = temp;
}