// Create a class called time that has separate int member data for hours, minutes, and
// seconds.One constructor should initialize this data to 0, and another should initialize it
// to fixed values.Another member function should display it, in 11 :59 : 59 format.The final
// member function should add two objects of type time passed as arguments.
// A main() program should create two initialized time objects(should they be const ? ) and
// one that isn’t initialized.Then it should add the two initialized values together, leaving the
// result in the third time variable.Finally it should display the value of this third variable.
// Make appropriate member functions const.

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
	void add_time(user_time a, user_time b)
	{
		int totalsec = a.hours * 3600 + a.minutes * 60 + a.seconds + b.hours * 3600 + b.minutes * 60 + b.seconds;
		hours = totalsec / 3600;
		minutes = 0;
		seconds = totalsec - hours * 3600;
		while (seconds >= 60)
		{
			seconds -= 60;
			minutes += 1;
		}
	}
};

int main()
{
	user_time time1(2, 30, 21);
	user_time time2(7, 15, 40);
	user_time time3;

	time3.add_time(time1, time2);
	time1.display();
	time2.display();
	time3.display();

	return EXIT_SUCCESS;
}