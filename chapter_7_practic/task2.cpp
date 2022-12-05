// Create a class called employee that contains a name(an object of class string) and an
// employee number(type long).Include a member function called getdata() to get data
// from the user for insertion into the object, and another function called putdata() to
// display the data.Assume the name has no embedded blanks.
// Write a main() program to exercise this class.It should create an array of type employee,
// and then invite the user to input data for up to 100 employees.Finally, it should print out
// the data for all the employees.

#include <iostream>
#include <string>
#include <conio.h>

class emploee
{
private:
	std::string name;
	long number;
public:
	emploee() : name("empty"), number(0)
	{ }
	void getdata()
	{
		std::cout << "Enter number of emploee: ";
		std::cin >> number;
		std::cin.get();
		std::cout << "Enter name: ";
		getline(std::cin, name);
	}
	void putdata()
	{
		std::cout << "number " << number << " name " << name << std::endl;
	}
};

int main()
{
	const int MAX = 100;
	emploee managers[MAX];
	char repeat = 'y';
	int counter = 0;

	for (int j = 0; j < MAX; ++j)
	{
		managers[j].getdata();
		std::cout << "y - to the next name. Press any button to exit ";
		repeat = getche();
		std::cout << std::endl;
		counter++;

		if ('y' == repeat)
			continue;
		else             //output
		{
			for (int i = 0; i < counter; ++i)
			{
				managers[i].putdata();
			}
			break;
		}
	}
	
	return EXIT_SUCCESS;
}