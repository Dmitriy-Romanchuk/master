// Add a variable of type enum etype(see Exercise 6), and another variable of type struct
// date(see Exercise 5) to the employee class of Exercise 4. 
// Organize the resulting program so that the user enters four items of information for each of three employees : an
// employee number, the employee’s compensation, the employee type, and the date of first
// employment.The program should store this information in three variables of type
// employee, and then display their contents.

#include <iostream>

int main()
{
	char ch = ' ';
	struct date
	{
		int day = 1;
		int month = 1;
		int year = 1;
	};

	enum etype { laborer, secretary, manager, accountant, executive, researcher };
	
	struct employee
	{
		int number = 0;
		float salary = 0.0f;
		date start_day;
		etype title;
	};

	employee first;
	employee second;
	employee third;


	std::cout << "Enter number of employee: ";  // get info about first employee
	std::cin >> first.number;
	std::cout << "Enter his salary: ";
	std::cin >> first.salary;
	std::cout << "Enter his start date (DD MM YYYY): ";
	std::cin >> first.start_day.day >> first.start_day.month >> first.start_day.year;
	std::cout << "Enter employee type(first letter only l, s, m, a, e, r): " << std::endl;
	std::cin >> ch;

	switch (ch)
	{
	case 'l':
		first.title = laborer;
		break;
	case 's':
		first.title = secretary;
		break;
	case 'm':
		first.title = manager;
		break;
	case 'a':
		first.title = accountant;
		break;
	case 'e':
		first.title = executive;
		break;
	case 'r':
		first.title = researcher;
		break;
	default:
		std::cout << "unexpected letter!" << std::endl;
	}

	std::cout << "Enter number of employee: "; // get info about second employee
	std::cin >> second.number;
	std::cout << "Enter his salary: ";
	std::cin >> second.salary;
	std::cout << "Enter his start date (DD MM YYYY): ";
	std::cin >> second.start_day.day >> second.start_day.month >> second.start_day.year;
	std::cout << "Enter employee type(first letter only l, s, m, a, e, r): " << std::endl;
	std::cin >> ch;

	switch (ch)
	{
	case 'l':
		second.title = laborer;
		break;
	case 's':
		second.title = secretary;
		break;
	case 'm':
		second.title = manager;
		break;
	case 'a':
		second.title = accountant;
		break;
	case 'e':
		second.title = executive;
		break;
	case 'r':
		second.title = researcher;
		break;
	default:
		std::cout << "unexpected letter!" << std::endl;
	}

	std::cout << "Enter number of employee: ";  // get info about third employee
	std::cin >> third.number;
	std::cout << "Enter his salary: ";
	std::cin >> third.salary;
	std::cout << "Enter his start date (DD MM YYYY): ";
	std::cin >> third.start_day.day >> third.start_day.month >> third.start_day.year;
	std::cout << "Enter employee type(first letter only l, s, m, a, e, r): " << std::endl;
	std::cin >> ch;

	switch (ch)
	{
	case 'l':
		third.title = laborer;
		break;
	case 's':
		third.title = secretary;
		break;
	case 'm':
		third.title = manager;
		break;
	case 'a':
		third.title = accountant;
		break;
	case 'e':
		third.title = executive;
		break;
	case 'r':
		third.title = researcher;
		break;
	default:
		std::cout << "unexpected letter!" << std::endl;
	}


	
	std::cout << "Employee number " << first.number << " has salary: " << first.salary << ", works since " 
		<< first.start_day.day << "/" << first.start_day.month << "/" << first.start_day.year << ". ";

	switch (first.title)
	{
	case laborer:
		std::cout << "Employee type is laborer" << std::endl;
		break;
	case secretary:
		std::cout << "Employee type is secretary" << std::endl;
		break;
	case manager:
		std::cout << "Employee type is manager" << std::endl;
		break;
	case accountant:
		std::cout << "Employee type is accountant" << std::endl;
		break;
	case executive:
		std::cout << "Employee type is executive" << std::endl;
		break;
	case researcher:
		std::cout << "Employee type is researcher" << std::endl;
		break;
	}



	std::cout << "Employee number " << second.number << " has salary: " << second.salary << ", works since "
		<< second.start_day.day << "/" << second.start_day.month << "/" << second.start_day.year << ". ";

	switch (second.title)
	{
	case laborer:
		std::cout << "Employee type is laborer" << std::endl;
		break;
	case secretary:
		std::cout << "Employee type is secretary" << std::endl;
		break;
	case manager:
		std::cout << "Employee type is manager" << std::endl;
		break;
	case accountant:
		std::cout << "Employee type is accountant" << std::endl;
		break;
	case executive:
		std::cout << "Employee type is executive" << std::endl;
		break;
	case researcher:
		std::cout << "Employee type is researcher" << std::endl;
		break;
	}



	std::cout << "Employee number " << third.number << " has salary: " << third.salary << ", works since "
		<< third.start_day.day << "/" << third.start_day.month << "/" << third.start_day.year << ". ";

	switch (third.title)
	{
	case laborer:
		std::cout << "Employee type is laborer" << std::endl;
		break;
	case secretary:
		std::cout << "Employee type is secretary" << std::endl;
		break;
	case manager:
		std::cout << "Employee type is manager" << std::endl;
		break;
	case accountant:
		std::cout << "Employee type is accountant" << std::endl;
		break;
	case executive:
		std::cout << "Employee type is executive" << std::endl;
		break;
	case researcher:
		std::cout << "Employee type is researcher" << std::endl;
		break;
	}

	return EXIT_SUCCESS;
}