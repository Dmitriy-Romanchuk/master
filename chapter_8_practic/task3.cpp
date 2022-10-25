// Modify the time class from Exercise 3 in Chapter 6 so that instead of a function
// add_time() it uses the overloaded + operator to add two times.Write a program to test
// this class

#include <iostream>
#include <iomanip>

class user_time
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	user_time() : hours(0), minutes(0), seconds(0)
	{	}
	user_time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
	{	}
	void display() const
	{
		std::cout << std::setiosflags(std::ios::right) << std::setfill('0') << std::setw(2) << hours << ":"
			<< std::setw(2) << minutes << ":" << std::setw(2) << seconds << std::endl;
	}
	user_time operator+ (user_time b)
	{
		int totalsec = hours * 3600 + minutes * 60 + seconds + b.hours * 3600 + b.minutes * 60 + b.seconds;
		hours = totalsec / 3600;
		minutes = 0;
		seconds = totalsec - hours * 3600;
		while (seconds >= 60)
		{
			seconds -= 60;
			minutes += 1;
		}
		return user_time(hours, minutes, seconds);
	}
};

int main()
{
	user_time time1(2, 30, 21);
	user_time time2(7, 15, 40);
	user_time time3;

	time1.display();
	time2.display();
	time3 = time1 + time2;
	time3.display();

	return EXIT_SUCCESS;
}