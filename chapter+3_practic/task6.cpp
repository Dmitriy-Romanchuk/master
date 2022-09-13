//Modify the FACTOR program in this chapter so that it repeatedly asks for a numberand
//calculates its factorial, until the user enters 0, at which point it terminates.You can
//enclose the relevant statements in FACTOR in a while loop or a do loop to achieve this
//effect.

#include <iostream>

int main()
{
	unsigned int numb = 0;
	
	while(true)
	{
		unsigned long fact = 1;

		std::cout << "Enter number ";
		std::cin >> numb;

		if (numb == 0)
			exit(EXIT_FAILURE);

		for (int j = numb; j > 0; j--)
			fact *= j;

		std::cout << "Factorial = " << fact << std::endl;
	}

	return EXIT_SUCCESS;
}