// Write a function called zeroSmaller() that is passed two int arguments by reference
// and then sets the smaller of the two numbers to 0. Write a main() program to exercise
// this function.

#include <iostream>

void zero_smaller(int& a, int& b);

int main()
{
	int first = 25;
	int second = 30;
	int third = 40;
	int fourth = 10;

	zero_smaller(first, second);
	zero_smaller(third, fourth);

	std::cout << first << std::endl;
	std::cout << second << std::endl << std::endl;

	std::cout << third << std::endl;
	std::cout << fourth << std::endl << std::endl;

	return EXIT_SUCCESS;
}

void zero_smaller(int& a, int& b)
{
	if (b < a)
		b = 0;
	else
		a = 0;


}