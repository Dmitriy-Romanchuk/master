// Add to the time class of Exercise 5 the ability to subtract two time values using the
// overloaded(-) operator,and to multiply a time value by a number of type float, using
// the overloaded(*) operator.

#include <iostream>
#include <iomanip>

class user_time
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	user_time();
	user_time(int h, int m, int s);
	void display() const;
	user_time operator+ (user_time b);
	user_time operator- (user_time b);
	user_time operator* (user_time b);
	user_time converting_time(int totalsec);
};

int main()
{
	user_time time1(2, 30, 50);
	user_time time2(1, 15, 25);
	user_time time3;
	user_time time4;
	
	time3 = time1 - time2;
	time4 = time1 * time2;

	std::cout << "time1 + time2 = ";
	time3.display();
	std::cout << "time1 * time2 = ";
	time4.display();

	return EXIT_SUCCESS;
}

user_time::user_time() : hours(0), minutes(0), seconds(0)
{	}

user_time::user_time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
{	}

user_time user_time::operator+ (user_time b)
{
	int totalsec = hours * 3600 + minutes * 60 + seconds + b.hours * 3600 + b.minutes * 60 + b.seconds;
	return converting_time(totalsec);
}

user_time user_time::operator- (user_time b)
{
	int totalsec = (hours * 3600 + minutes * 60 + seconds) - (b.hours * 3600 + b.minutes * 60 + b.seconds);
	return converting_time(totalsec);
}

user_time user_time::operator* (user_time b)
{
	int totalsec = (hours * 3600 + minutes * 60 + seconds) * (b.hours * 3600 + b.minutes * 60 + b.seconds);
	return converting_time(totalsec);
}

user_time user_time::converting_time(int totalsec)
{
	hours = totalsec / 3600;
	minutes = (totalsec % 3600) / 60;
	seconds = (totalsec % 3600) % 60;
	return user_time(hours, minutes, seconds);
}

void user_time::display() const
{
	std::cout << std::setiosflags(std::ios::right) << std::setfill('0') << std::setw(2) << hours << ":"
		<< std::setw(2) << minutes << ":" << std::setw(2) << seconds << std::endl;
}