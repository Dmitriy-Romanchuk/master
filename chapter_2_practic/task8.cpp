#include <iostream>
#include <iomanip>

int main()
{
	// task 8:----------------------------------------------------------------------------------
	// When a value is smaller than a field specified with std::setw(), the unused locations are, by
	// default, filled in with spaces.The manipulator setfill() takes a single character as an
	// argumentand causes this character to be substituted for spaces in the empty parts of a
	// field.Rewrite the WIDTH program so that the characters on each line between the location
	// nameand the population number are filled in with periods instead of spaces, as in
	// Portcity.....2425785

	
	long pop1 = 8425785, pop2 = 47, pop3 = 9761;
	std::cout << std::setfill('*') << std::setw(11) << "City" << std::setw(12) << "Population" << std::endl
		<< std::setw(11) << "Chicago" << std::setw(12) << pop1 << std::endl
		<< std::setw(11) << "Ohayo" << std::setw(12) << pop2 << std::endl
		<< std::setw(11) << "San Andreas" << std::setw(12) << pop3 << std::endl << std::endl;

	
	return 0;
}