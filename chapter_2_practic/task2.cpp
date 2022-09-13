#include <iostream>
#include <iomanip>

int main()
{
	// task2:-----------------------------------------------------------------------------------
	// Write a program that generates the following table :
	
	//	1990 135
	//	1991 7290
	//	1992 11300
	//	1993 16200

	// Use a single cout statement for all output.

	int year1 = 1990, year2 = 1991, year3 = 1992, year4 = 1993;
	int count1 = 135, count2 = 7290, count3 = 11300, count4 = 16200;
	int lenght = 10; //argument for setw

	std::cout << year1 << std::setw(lenght) << count1 << std::endl << year2 << std::setw(lenght) << count2 << std::endl
		 << year3 << std::setw(lenght) << count3 << std::endl << year4 << std::setw(lenght) << count4 << std::endl << std::endl;


	return 0;
}