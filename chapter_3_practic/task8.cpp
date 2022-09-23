// Write a program that repeatedly asks the user to enter two money amounts expressed in
// old - style British currency : pounds, shillings, and pence. (See Exercises 10 and 12 in
// Chapter 2, “C++ Programming Basics.”) The program should then add the two amounts
// and display the answer, again in pounds, shillings, and pence.Use a do loop that asks the
// user whether the program should be terminated.Typical interaction might be
// Enter first amount : £5.10.6
// Enter second amount : £3.2.6
// Total is £8.13.0
// Do you wish to continue (y / n) ?
// To add the two amounts, you’ll need to carry 1 shilling when the pence value is greater
// than 11, and carry 1 pound when there are more than 19 shillings.

#include <iostream>

int main()
{
	char repeat = 'y';

	while (repeat == 'y')
	{
		int  pounds1 = 0, shillings1 = 0, pence1 = 0;
		int  pounds2 = 0, shillings2 = 0, pence2 = 0;
		int  pounds = 0, shillings = 0, pence = 0; // for results
		char ch = ' ';

		std::cout << "Enter first amount: (5.10.6)";
		std::cin >> pounds1 >> ch >> shillings1 >> ch >> pence1;

		std::cout << "Enter second amount: (3.2.6)";
		std::cin >> pounds2 >> ch >> shillings2 >> ch >> pence2;

		pence = pence1 + pence2; // подсчет пенсов и, если их больше 12, то +1 к шиллингам
		while (pence > 11)
		{
			pence -= 12;
			shillings += 1;
		}

		shillings += (shillings1 + shillings2); //подсчет шиллингов, и если их больше 20, то + 1 к фунтам
		while (shillings > 19)
		{
			shillings -= 20;
			pounds += 1;
		}
		pounds += (pounds1 + pounds2); // подсчет фунтов

		std::cout << pounds << "." << shillings << "." << pence << std::endl;
		std::cout << "Do another(y / n) ? ";
		std::cin >> repeat;
	}

	return EXIT_SUCCESS;
}