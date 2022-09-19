// We said earlier that C++ I / O statements don’t automatically understand the data types of
// enumerations.Instead, the(>> ) and (<< ) operators think of such variables simply as integers.You can overcome this limitation by using switch statements to translate between
// the user’s way of expressing an enumerated variableand the actual values of the enumerated variable.For example, imagine an enumerated type with values that indicate an
// employee type within an organization :
// enum etype { laborer, secretary, manager, accountant, executive,researcher};
// Write a program that first allows the user to specify a type by entering its first letter
// (‘l’, ‘s’, ‘m’, and so on), then stores the type chosen as a value of a variable of type
// enum etype, and finally displays the complete word for this type.
// Enter employee type(first letter only)
// laborer, secretary, manager,
// accountant, executive, researcher): a
// Employee type is accountant.
// You’ll probably need two switch statements : one for inputand one for output.

#include <iostream>

int main()
{
	char ch = ' ';
	enum etype { laborer, secretary, manager, accountant, executive, researcher };

	etype emploee = laborer;
	
	std::cout << "Enter employee type(first letter only l, s, m, a, e, r)" << std::endl;
	std::cin >> ch;

	switch (ch)
	{
	case 'l':
		emploee = laborer;
		break;
	case 's':
		emploee = secretary;
		break;
	case 'm':
		emploee = manager;
		break;
	case 'a':
		emploee = accountant;
		break;
	case 'e':
		emploee = executive;
		break;
	case 'r':
		emploee = researcher;
		break;
	default:
		std::cout << "unexpected letter!" << std::endl;
	}

	switch (emploee)
	{
	case laborer:
		std::cout << "Employee type is laborer";
		break;
	case secretary:
		std::cout << "Employee type is secretary";
		break;
	case manager:
		std::cout << "Employee type is manager";
		break;
	case accountant:
		std::cout << "Employee type is accountant";
		break;
	case executive:
		std::cout << "Employee type is executive";
		break;
	case researcher:
		std::cout << "Employee type is researcher";
		break;
	}

	return EXIT_SUCCESS;
}