// Create an employee class, basing it on Exercise 4 of Chapter 4. The member data should
// comprise an int for storing the employee numberand a float for storing the employee’s
// compensation.Member functions should allow the user to enter this dataand display it.
// Write a main() that allows the user to enter data for three employeesand display it.

#include <iostream>

class emploee
{
private:
	int number;
	float compensation;
public:
	emploee() : number(0), compensation(0)
	{ }
	void set_info()
	{
		std::cout << "Enter Number of emploee: ";
		std::cin >> number;
		std::cout << "Enter Salary of emploee number " << number <<": ";
		std::cin >> compensation;
	}
	void display() const
	{
		std::cout << "Emploee number " << number << " has salary " << compensation << std::endl;
	}
};


int main()
{
	emploee em1;
	emploee em2;
	emploee em3;

	em1.set_info();
	em2.set_info();
	em3.set_info();
	em1.display();
	em2.display();
	em3.display();

	return EXIT_SUCCESS;
}