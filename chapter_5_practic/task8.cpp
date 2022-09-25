// Write a function called swap() that interchanges two int values passed to it by the calling program. 
// (Note that this function swaps the values of the variables in the calling program, not those in the function.) 
// You’ll need to decide how to pass the arguments.Create
// a main() program to exercise the function.

#include <iostream>

inline void swap(int& a, int& b);

int main()
{
	int first = 0;
	int second = 0;
	std::cout << "Enter first number:" << std::endl;
	std::cin >> first;
	std::cout << "Enter second number:" << std::endl;
	std::cin >> second;
	std::cout << '\n' << "First = " << first << '\n' << "Second = " << second << '\n' << "Swap the values of variables...." << std::endl << std::endl;

	swap(first, second);

	std::cout << "Now!" << '\n'<< "first = " << first << '\n' << "second = " << second << std::endl;

	return EXIT_SUCCESS;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}