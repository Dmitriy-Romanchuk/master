// Write a function called reversit() that reverses a C - string(an array of char).Use a for
// loop that swaps the firstand last characters, then the secondand next - to - last characters,
// and so on.The string should be passed to reversit() as an argument.
// Write a program to exercise reversit().The program should get a string from the user,
// call reversit(), and print out the result.Use an input method that allows embedded
// blanks.Test the program with Napoleon’s famous phrase, “Able was I ere I saw Elba.”


#include <iostream>
#include <cstring>

void reversit(char[]);

int main()
{
	const int MAX = 100;
	char array[MAX];
	std::cout << "Enter string e.g. Able was I ere I saw Elba" << std::endl;
	std::cin.get(array, 100);

	reversit(array);
	std::cout << array;

	return EXIT_SUCCESS;
}

void reversit(char str[])
{
	char temp = ' ';
	int lenght = strlen(str);
	
	for (int i = 0; i < lenght / 2; ++i)
	{
		temp = str[i];
		str[i] = str[lenght - i - 1];
		str[lenght - i - 1] = temp;
	}
}
