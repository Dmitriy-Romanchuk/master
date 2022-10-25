// Augment the time class referred to in Exercise 3 to include overloaded increment(++)
// and decrement(--) operators that operate in both prefix and postfix notation and return
// values.Add statements to main() to test these operators.

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
	user_time operator++();
	user_time operator++(int);
	user_time operator--();
	user_time operator--(int);
	user_time converting_time(int totalsec);
};

int main()
{
	user_time time1(2, 30, 56);
	user_time time2;
	user_time time3(2, 30, 56);
	user_time time4(3, 10, 20);
	user_time time5(3, 10, 20);

	std::cout << "Operator ++i" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		time2 = ++time1;
		time2.display();
	}
	
	std::cout << "Operator i++" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		time2 = time3++;
		time2.display();
	}

	std::cout << "Operator --i" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		time2 = --time4;
		time2.display();
	}

	std::cout << "Operator i--" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		time2 = time5--;
		time2.display();
	}

	return EXIT_SUCCESS;
}

user_time::user_time() : hours(0), minutes(0), seconds(0)
{	}

user_time::user_time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
{	}

user_time user_time::operator+ (user_time b)
{
	int totalsec = hours * 3600 + minutes * 60 + seconds + b.hours * 3600 + b.minutes * 60 + b.seconds;
	hours = totalsec / 3600;
	minutes = (totalsec % 3600) / 60;
	seconds = (totalsec % 3600) % 60;
	return user_time(hours, minutes, seconds);
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

user_time user_time::operator++()
{
	int totalsec = hours * 3600 + minutes * 60 + seconds;
	int temp_sec = ++totalsec;

	return converting_time(temp_sec);
}
user_time user_time::operator++(int)
{
	user_time temp;
	int totalsec = hours * 3600 + minutes * 60 + seconds;
	int temp_sec = totalsec--;
	converting_time(totalsec);
	return temp.converting_time(temp_sec);
}
user_time user_time::operator--()
{
	int totalsec = hours * 3600 + minutes * 60 + seconds;
	int temp_sec = --totalsec;
	return converting_time(temp_sec);
}

user_time user_time::operator--(int)
{
	user_time temp;
	int totalsec = hours * 3600 + minutes * 60 + seconds;
	int temp_sec = totalsec--;
	converting_time(totalsec);
	return temp.converting_time(temp_sec);
}