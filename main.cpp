#include <ctype.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// Task1:----------------------------------------------------------------------------------
	// Assuming there are 7.481 gallons in a cubic foot, write a program that asks the user to
	// enter a number of gallons, and then displays the equivalent in cubic feet

	cout << "Task 1" << endl;

	const float ratio = 7.481f;
	float user_input;

	cout << "Enter the number of gallons:" << endl;
	cin >> user_input;
	cout << user_input << " gallons = " << user_input / ratio << " cubic pounds" << endl << endl;

	
	//task2:-----------------------------------------------------------------------------------
	//Write a program that generates the following table :
	
	//	1990 135
	//	1991 7290
	//	1992 11300
	//	1993 16200

	//Use a single cout statement for all output.

	cout << "Task 2" << endl;

	int year1 = 1990, year2 = 1991, year3 = 1992, year4 = 1993;
	int count1 = 135, count2 = 7290, count3 = 11300, count4 = 16200;
	int lenght = 10; //argument for setw

	cout << year1 << setw(lenght) << count1 << endl << year2 << setw(lenght) << count2 << endl
		 << year3 << setw(lenght) << count3 << endl << year4 << setw(lenght) << count4 << endl << endl;


	//task3:-----------------------------------------------------------------------------------
	//Write a program that generates the following output :
	
	//	10
	//	20
	//	19
	
	//	Use an integer constant for the 10, an arithmetic assignment operator to generate the 20,
	//	and a decrement operator to generate the 19.

	cout << "Task 3" << endl;

	int number = 10;

	cout << number << endl;
	cout << (number += 10) << endl;
	cout << --number << endl << endl;


	//task 4:----------------------------------------------------------------------------------
	// Write a program that displays your favorite poem.Use an appropriate escape sequence
	// for the line breaks.If you don’t have a favorite poem, you can borrow this one by Ogden
	// Nash:
	//			Candy is dandy,
	//			But liquor is quicker.

	cout << "Task 4" << endl;
	cout << '\t' << "Candy is dandy, " << "\n" << '\t' << "But liquor is quicker." << endl << endl;


	//task 5:----------------------------------------------------------------------------------
	// A library function, islower(), takes a single character(a letter) as an argumentand
	// returns a nonzero integer if the letter is lowercase, or zero if it is uppercase.
	// This function requires the header file CTYPE.H.Write a program that allows the user to enter a letter, 
	// and then displays either zero or nonzero, depending on whether a lowercase or
	//	uppercase letter was entered. (See the SQRT program for clues.)

	cout << "Task 5" << endl;
	char letter;

	cout << "Enter any one letter" << endl;
	cin >> letter;
	cout << islower(letter) << endl << endl;


	//task 6:----------------------------------------------------------------------------------
	//On a certain day the British pound was equivalent to $1.487 U.S., the French franc was
	//$0.172, the German deutschemark was $0.584, and the Japanese yen was $0.00955.
	//Write a program that allows the user to enter an amount in dollars, and then displays this
	//value converted to these four other monetary units.

	cout << "Task 6" << endl;
	float input; // for user input
	float british_pound = 1.487f;
	float french_franc = 0.172f;
	float german_deutschemark = 0.584;
	float japanese_yen = 0.00955;

	cout << "Enter count of U.S., $" << endl;
	cin >> input;

	cout << input << "$ :" << endl;
	cout << input / british_pound << " british_pounds" << endl;
	cout << input / french_franc << " french_franc" << endl;
	cout << input / german_deutschemark << " german_deutschemark" << endl;
	cout << input / japanese_yen << " japanese_yen" << endl << endl;


	//task 7:----------------------------------------------------------------------------------



	return 0;
}