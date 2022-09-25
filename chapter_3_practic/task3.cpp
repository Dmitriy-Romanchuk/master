//Operators such as >> , which read input from the keyboard, must be able to convert a
//series of digits into a number.Write a program that does the same thing.It should allow
//the user to type up to six digits, and then display the resulting number as a type long
//integer.The digits should be read individually, as characters, using getche().
//Constructing the number involves multiplying the existing value by 10 and then adding
//the new digit. (Hint: Subtract 48 or ‘0’ to go from ASCII to a numerical digit.)
//Chapter 3 126

//Here’s some sample interaction :
//Enter a number : 123456
//Number is : 123456

#include <iostream>
#include <conio.h>

int main()
{
	char ch = ' ';
	long result = 0L;

	std::cout << "Enter a number and press enter: " ;

	while ((ch = getche()) != '\r')
		result = result * 10 + (ch - '0');
	
	std::cout << std::endl  << result;

	return EXIT_SUCCESS;
}