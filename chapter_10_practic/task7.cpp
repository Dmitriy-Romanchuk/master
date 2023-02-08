// Modify the person class in the PERSORT program in this chapter so that it includes not
// only a name, but also a salary item of type float representing the person’s salary.
// You’ll need to change the setName() and printName() member functions to setData()
// and printData(), and include in them the ability to setand display the salary as well as
// the name.You’ll also need a getSalary() function.Using pointer notation, write a
// salsort() function that sorts the pointers in the persPtr array by salary rather than by
// name.Try doing all the sorting in salsort(), rather than calling another function as
// PERSORT does.If you do this, don’t forget that->takes precedence over*, so you’ll need
// to say
// if ((*(pp + j))->getSalary() > (*(pp + k))->getSalary())
// { /* swap the pointers */
// }

#include <iostream>
#include <string>

class person
{
protected:
	std::string name;
	float salary;
public:
	person() : salary(0)
	{}
	void setData()          
	{
		std::cout << "Enter name: "; 
		std::cin >> name;
		std::cout << "Enter salary: ";
		std::cin >> salary;
	}
	void printData() const 
	{
		std::cout << "Name: " << name;
		std::cout << ", salary: " << salary;
	}
	float getSalary() const
	{
		return salary;
	}
};

void salsort(person**, int n);

int main()
{
	person* persPtr[100];
	int n = 0;
	char ch = ' ';

	do
	{
		persPtr[n] = new person;             
		persPtr[n]->setData();               
		n++;                                 
		std::cout << "Create another person (y/n)? ";
		std::cin >> ch;
	} while (ch == 'y');

	salsort(persPtr, n);

	for (int j = 0; j < n; ++j)
	{
		persPtr[j]->printData();
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}

void salsort(person** pp, int n)
{
	int j = 0;
	int k = 0;

	for(j =0; j < n - 1; ++j)
		for (k = j + 1; k < n; ++k)
		{
			if ((*(pp + j))->getSalary() > (*(pp + k))->getSalary())
			{
				person* tempptr = *(pp + j);
				*(pp + j) = *(pp + k);
				*(pp + k) = tempptr;
			}
		}

}