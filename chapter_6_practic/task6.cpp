// Extend the employee class of Exercise 4 to include a date class (see Exercise 5) and an
// etype enum (see Exercise 6 in Chapter 4).An object of the date class should be used to
// hold the date of first employment; that is, the date when the employee was hired.The
// etype variable should hold the employee’s type : laborer, secretary, manager, and so on.
// These two items will be private member data in the employee definition, just like the
// employee numberand salary.You’ll need to extend the getemploy() and putemploy()
// functions to obtain this new information from the userand display it.These functions will
// probably need switch statements to handle the etype variable.Write a main() program that
// allows the user to enter data for three employee variablesand then displays this data.

#include <iostream>
#include <iomanip>

enum class etype { laborer, secretary, manager, accountant, executive, researcher };

class date
{
private:
	int day;
	int month;
	int year;
	char ch;
public:
	date() : month(0), day(0), year(0), ch(' ')
	{}
	void getdate()
	{
		std::cout << "Enter date in format dd/mm/yyyy: ";
		std::cin >> day >> ch >> month >> ch >> year;
	}
	void showdate() const
	{
		std::cout << std::setiosflags(std::ios::right) << std::setfill('0') << "Start Date is : "
			<< std::setw(2) << day << ch << std::setw(2) << month << ch << std::setw(4) << year << std::endl;
	}
};

class emploee
{
private:
	int number;
	float compensation;
	date start_date;
	etype job_title;
	char title;

public:
	emploee() : number(0), compensation(0), job_title(etype::manager), title('l')
	{ }
	void getemploy()
	{
		std::cout << "Enter Number of emploee: ";
		std::cin >> number;
		std::cout << "Enter Salary of emploee number " << number << ": ";
		std::cin >> compensation;
		start_date.getdate();
		std::cout << "Enter first letter of job_title (laborer, secretary, manager, accountant, executive, researcher) : ";
		std::cin >> title;
		switch (title)
		{
		case 'l':
			job_title = etype::laborer;
			break;
		case 's':
			job_title = etype::secretary;
			break;
		case 'm':
			job_title = etype::manager;
			break;
		case 'a':
			job_title = etype::accountant;
			break;
		case 'e':
			job_title = etype::executive;
			break;
		case 'r':
			job_title = etype::researcher;
			break;
		default:
			std::cout << "unexpected letter!" << std::endl;
		}
	}
		
	void putemploy() const
	{
		std::cout << "Emploee number " << number << " has salary " << compensation << std::endl;
		start_date.showdate();

		switch (job_title)
		{
		case etype::laborer:
			std::cout << "Employee type is laborer" << std::endl;
			break;
		case etype::secretary:
			std::cout << "Employee type is secretary" << std::endl;
			break;
		case etype::manager:
			std::cout << "Employee type is manager" << std::endl;
			break;
		case etype::accountant:
			std::cout << "Employee type is accountant" << std::endl;
			break;
		case etype::executive:
			std::cout << "Employee type is executive" << std::endl;
			break;
		case etype::researcher:
			std::cout << "Employee type is researcher" << std::endl;
			break;
		}
	}
};

int main()
{
	emploee m1;
	emploee m2;
	emploee m3;

	m1.getemploy();
	m2.getemploy();
	m3.getemploy();

	m1.putemploy();
	m2.putemploy();
	m3.putemploy();

	return EXIT_SUCCESS;
}