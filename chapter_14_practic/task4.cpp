// Create a function called swaps() that interchanges the values of the two arguments sent
// to it. (You will probably want to pass these arguments by reference.) Make the function
// into a template, so it can be used with all numerical data types(char, int, float, and so
// on).Write a main() program to exercise the function with several types.

#include <iostream>

template <class atype>
void swaps(atype &a, atype &b)
{
	atype temp = a;
	a = b;
	b = temp; 
}

int main()
{
	int first = 5;
	int second = 10;
	swaps(first, second);
	std::cout << "First = " << first << " Second = " << second << std::endl;

	float third = 20.3;
	float fourth = 30.5;
	swaps(third, fourth);
	std::cout << "Third = " << third << " Fourth = " << fourth << std::endl;

	return EXIT_SUCCESS;
}
