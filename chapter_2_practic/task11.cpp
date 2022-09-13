#include <iostream>
#include <iomanip>

int main()
{
	// task 11:----------------------------------------------------------------------------------
	// By default, output is right - justified in its field.You can left - justify text output using the
	// manipulator std::setiosflags(ios::left). (For now, don’t worry about what this new notation means.) 
	// Use this manipulator, along with std::setw()

	int column_width = 18;

	std::cout << std::setfill(' ') << std::setiosflags(std::ios::left) << std::setw(column_width) << "Last name" << std::setw(column_width)
		<< "First name" << std::setw(column_width) << "Address" << std::setw(column_width) << "City" << std::endl;

	std::cout << std::setfill('-') << std::setw(65) << "-" << std::endl;

	std::cout << std::setfill(' ') << std::setiosflags(std::ios::left) << std::setw(column_width) << "Jones" << std::setw(column_width)
		<< "Bernard" << std::setw(column_width) << "109 Pine Lane" << std::setw(column_width) << "Littletown" << std::endl;

	std::cout << std::setiosflags(std::ios::left) << std::setw(column_width) << "O’Brian" << std::setw(column_width)
		<< "Coleen" << std::setw(column_width) << "42 E. 99th Ave" << std::setw(column_width) << "Bigcity" << std::endl;

	std::cout << std::setiosflags(std::ios::left) << std::setw(column_width) << "Wong" << std::setw(column_width)
		<< "Harry" << std::setw(column_width) << "A Alabama St" << std::setw(column_width) << "Lakeville" << std::endl <<std::endl;


	return 0;
}