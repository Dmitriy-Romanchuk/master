// Write a function that takes two Distance values as argumentsand returns the larger one.
// Include a main() program that accepts two Distance values from the user, compares
// them, and displays the larger. (See the RETSTRC program for hints.)

#include <iostream>

struct Distance
{
	int feet = 0;
	float inches = 0.0f;
};

Distance compare (Distance, Distance);

int main()
{
	Distance first;
	Distance second;
	Distance result;

	std::cout << "Enter first feet (int):";
	std::cin >> first.feet;
	std::cout << "Enter first inches (float): ";
	std::cin >> first.inches;

	std::cout << "Enter second feet (int):";
	std::cin >> second.feet;
	std::cout << "Enter second inches (float): ";
	std::cin >> second.inches;

	result = compare(first, second);

	std::cout << result.feet << "'-" << result.inches << "\"";

	return EXIT_SUCCESS;
}

Distance compare(Distance d1, Distance d2)
{
	if (d1.feet > d2.feet)
		return d1;
	else if (d1.feet == d2.feet && d1.inches > d2.inches)
		return d1;
	else if (d1.feet == d2.feet && d1.inches == d2.inches)
	{
		std::cout << "Values are equivalent" << std::endl;
		exit(EXIT_SUCCESS);
	}
	else
		return d2;
}