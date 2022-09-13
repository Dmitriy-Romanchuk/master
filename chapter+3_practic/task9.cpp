// Suppose you give a dinner party for six guests, but your table seats only four.In how
// many ways can four of the six guests arrange themselves at the table ? Any of the six
// guests can sit in the first chair.Any of the remaining five can sit in the second chair.Any
// of the remaining four can sit in the third chair, and any of the remaining three can sit in
// the fourth chair. (The last two will have to stand.) So the number of possible arrangements of six guests in four chairs is 6 * 5 * 4 * 3, which is 360. 
// Write a program that calculates the number of possible arrangements for any number of guestsand any number of
// chairs. (Assume there will never be fewer guests than chairs.) Don’t let this get too complicated.A simple for loop should do it.

#include <iostream>

int main()
{
	int seats = 0;
	int guests = 0;
	unsigned int counter = 1;

	std::cout << "Enter the number of seats at the table: ";
	std::cin >> seats;
	do
	{
		std::cout << "Enter the number of guests: (more than seats) ";
		std::cin >> guests;
	} while (seats > guests);

	for (int i = seats; i > 0; i--, guests--)
	{
		counter *= guests;

	}
	std::cout << counter;

	return EXIT_SUCCESS;
}