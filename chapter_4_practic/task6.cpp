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
	enum class etype { laborer, secretary, manager, accountant, executive, researcher };

	etype emploee = etype::laborer;
	
	std::cout << "Enter employee type(first letter only l, s, m, a, e, r)" << std::endl;
	std::cin >> ch;

	switch (ch)
	{
	case 'l':
		emploee = etype::laborer;
		break;
	case 's':
		emploee = etype::secretary;
		break;
	case 'm':
		emploee = etype::manager;
		break;
	case 'a':
		emploee = etype::accountant;
		break;
	case 'e':
		emploee = etype::executive;
		break;
	case 'r':
		emploee = etype::researcher;
		break;
	default:
		std::cout << "unexpected letter!" << std::endl;
	}

	switch (emploee)
	{
	case etype::laborer:
		std::cout << "Employee type is laborer";
		break;
	case etype::secretary:
		std::cout << "Employee type is secretary";
		break;
	case etype::manager:
		std::cout << "Employee type is manager";
		break;
	case etype::accountant:
		std::cout << "Employee type is accountant";
		break;
	case etype::executive:
		std::cout << "Employee type is executive";
		break;
	case etype::researcher:
		std::cout << "Employee type is researcher";
		break;
	}

	return EXIT_SUCCESS;
}