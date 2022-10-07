// Start with the date structure in Exercise 5 in Chapter 4 and transform it into a date
// class.Its member data should consist of three ints : month, day, and year.It should also
// have two member functions : getdate(), which allows the user to enter a date in
// 12 / 31 / 02 format, and showdate(), which displays the date.

#include <iostream>
#include <iomanip>

class date
{
private:
	int day;
	int month;
	int year;
	
public:
	date() : month{ 0 }, day{ 0 }, year{ 0 }
	{}
	void getdate()
	{
		char ch { ' ' };
		std::cout << "Enter date in format dd/mm/yyyy: ";
		std::cin >> day >> ch >> month >> ch >> year;
	}
	void showdate() const
	{
		char ch{ ' ' };
		std::cout << std::setiosflags(std::ios::right) << std::setfill('0') << "You Entered: "
			<< std::setw(2) << day << ch << std::setw(2) << month << ch << std::setw(4) << year << std::endl;
	}
};

int main()
{
	date date1;

	date1.getdate();
	date1.showdate();

	return EXIT_SUCCESS;
}