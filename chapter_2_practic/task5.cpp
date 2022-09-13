#include <ctype.h>
#include <iostream>

int main()
{
	// task 5:----------------------------------------------------------------------------------
	// A library function, islower(), takes a single character(a letter) as an argumentand
	// returns a nonzero integer if the letter is lowercase, or zero if it is uppercase.
	// This function requires the header file CTYPE.H.Write a program that allows the user to enter a letter, 
	// and then displays either zero or nonzero, depending on whether a lowercase or
	// uppercase letter was entered. (See the SQRT program for clues.)

	char letter = ' ';

	std::cout << "Enter any one letter" << std::endl;
	std::cin >> letter;
	std::cout << islower(letter) << std::endl << std::endl;

	return 0;
}