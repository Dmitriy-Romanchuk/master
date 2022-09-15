// Create a structure called employee that contains two members : an employee number
// (type int) and the employee’s compensation(in dollars; type float).Ask the user to fill
// in this data for three employees, store it in three variables of type struct employee, and
// then display the information for each employee.

#include <iostream>

int main()
{
	struct emploee
	{
		int number;
		float compensation;
	};

	emploee em1;
	emploee em2;
	emploee em3;
	
	std::cout << "Enter Number and Salary of emploee (e.g. 1 250.5): ";
	std::cin >> em1.number >> em1.compensation;

	std::cout << "Enter Number and Salary of emploee (e.g. 1 250.5): ";
	std::cin >> em2.number >> em2.compensation;

	std::cout << "Enter Number and Salary of emploee (e.g. 1 250.5): ";
	std::cin >> em3.number >> em3.compensation;

	std::cout << "Emploee number " << em1.number << " has salary " << em1.compensation << std::endl;
	std::cout << "Emploee number " << em2.number << " has salary " << em2.compensation << std::endl;
	std::cout << "Emploee number " << em3.number << " has salary " << em3.compensation << std::endl;


	return EXIT_SUCCESS;
}