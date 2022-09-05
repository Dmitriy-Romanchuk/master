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

	
	// task2:-----------------------------------------------------------------------------------
	// Write a program that generates the following table :
	
	//	1990 135
	//	1991 7290
	//	1992 11300
	//	1993 16200

	// Use a single cout statement for all output.

	cout << "Task 2" << endl;
	int year1 = 1990, year2 = 1991, year3 = 1992, year4 = 1993;
	int count1 = 135, count2 = 7290, count3 = 11300, count4 = 16200;
	int lenght = 10; //argument for setw

	cout << year1 << setw(lenght) << count1 << endl << year2 << setw(lenght) << count2 << endl
		 << year3 << setw(lenght) << count3 << endl << year4 << setw(lenght) << count4 << endl << endl;


	// task3:-----------------------------------------------------------------------------------
	// Write a program that generates the following output :
	
	//	10
	//	20
	//	19
	
	// Use an integer constant for the 10, an arithmetic assignment operator to generate the 20,
	// and a decrement operator to generate the 19.

	cout << "Task 3" << endl;
	int number = 10;

	cout << number << endl;
	cout << (number += 10) << endl;
	cout << --number << endl << endl;


	// task 4:----------------------------------------------------------------------------------
	// Write a program that displays your favorite poem.Use an appropriate escape sequence
	// for the line breaks.If you don’t have a favorite poem, you can borrow this one by Ogden
	// Nash:
	//			Candy is dandy,
	//			But liquor is quicker.

	cout << "Task 4" << endl;
	cout << '\t' << "Candy is dandy, " << "\n" << '\t' << "But liquor is quicker." << endl << endl;


	// task 5:----------------------------------------------------------------------------------
	// A library function, islower(), takes a single character(a letter) as an argumentand
	// returns a nonzero integer if the letter is lowercase, or zero if it is uppercase.
	// This function requires the header file CTYPE.H.Write a program that allows the user to enter a letter, 
	// and then displays either zero or nonzero, depending on whether a lowercase or
	// uppercase letter was entered. (See the SQRT program for clues.)

	cout << "Task 5" << endl;
	char letter;

	cout << "Enter any one letter" << endl;
	cin >> letter;
	cout << islower(letter) << endl << endl;


	// task 6:----------------------------------------------------------------------------------
	// On a certain day the British pound was equivalent to $1.487 U.S., the French franc was
	// $0.172, the German deutschemark was $0.584, and the Japanese yen was $0.00955.
	// Write a program that allows the user to enter an amount in dollars, and then displays this
	// value converted to these four other monetary units.

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


	// task 7:----------------------------------------------------------------------------------
	// You can convert temperature from degrees Celsius to degrees Fahrenheit by multiplying
	// by 9 / 5 and adding 32. Write a program that allows the user to enter a floating - point number
	// representing degrees Celsius, and then displays the corresponding degrees Fahrenheit.

	cout << "Task 7" << endl;
	float temperature;
	cout << "Enter the temperature in degrees Celsius:" << endl;
	cin >> temperature;
	float temp_fahr = temperature * 9 / 5 + 32;
	cout << "Temperature in Fahrenheit = " << temp_fahr << endl << endl;


	// task 8:----------------------------------------------------------------------------------
	// When a value is smaller than a field specified with setw(), the unused locations are, by
	// default, filled in with spaces.The manipulator setfill() takes a single character as an
	// argumentand causes this character to be substituted for spaces in the empty parts of a
	// field.Rewrite the WIDTH program so that the characters on each line between the location
	// nameand the population number are filled in with periods instead of spaces, as in
	// Portcity.....2425785

	cout << "Task 8" << endl;
	long pop1 = 8425785, pop2 = 47, pop3 = 9761;
	cout << setfill('*') << setw(11) << "City" << setw(12) << "Population" << endl
		<< setw(11) << "Chicago" << setw(12) << pop1 << endl
		<< setw(11) << "Ohayo" << setw(12) << pop2 << endl
		<< setw(11) << "San Andreas" << setw(12) << pop3 << endl << endl;


	// task 9:----------------------------------------------------------------------------------
	// If you have two fractions, a / b and c / d, their sum can be obtained from the formula
	// a/b + c/d = (a*d + b*c)/(b*d) 
	// For example, 1 / 4 + 2 / 3 = (1 * 3 + 4 * 2) / 4 * 3 = 11 / 12
	// Write a program that encourages the user to enter two fractions, and then displays their
	// sum in fractional form. (You don’t need to reduce it to lowest terms.) The interaction
	// with the user might look like this:
	// Enter first fraction : 1 / 2
	// Enter second fraction : 2 / 5
	// Sum = 9 / 10
	// You can take advantage of the fact that the extraction operator ( >> ) can be chained to
	// read in more than one quantity at once : cin >> a >> dummychar >> b;

	cout << "Task 9" << endl;
	int a, b, c, d;
	float result;
	char i;

	cout << "Enter first fraction : forexample 1/2" << endl;
	cin >> a >> i >> b;
	cout << "Enter second fraction : forexample 2/5" << endl;
	cin >> c >> i >> d;
	cout << "Result = " << (a * d + b * c) << i << (b * d) << endl << endl;


	// task 10:----------------------------------------------------------------------------------
	// In the heyday of the British empire, Great Britain used a monetary system based on pounds, shillings, and pence.
	// There were 20 shillings to a pound, and 12 pence to a shilling.The notation for this old system used the pound sign, £, and two decimal points,
	// so that, for example, £5.2.8 meant 5 pounds, 2 shillings, and 8 pence. (Pence is the plural of penny.) 
	// The new monetary system, introduced in the 1950s, consists of only pounds and pence, with 100 pence to a pound(like U.S.dollars and cents).
	// We’ll call this new system decimal pounds.Thus £5.2.8 in the old notation is £5.13 in decimal pounds(actually £5.1333333).
	// Write a program to convert the old pounds - shillings - pence format to decimal pounds.An example of the user’s interaction with the program would be
	// Enter pounds : 7
	// Enter shillings : 17
	// Enter pence : 9
	// Decimal pounds = £7.89
	// In most compilers you can use the decimal number 156 (hex character constant ‘\x9c’)
	// to represent the pound sign(£).In some compilers, you can put the pound sign into your
	// program directly by pasting it from the Windows Character Map accessory.


	cout << "Task 10" << endl;
	float  pounds, shillings, pence, new_pounds;

	cout << "Enter pounds" << endl;
	cin >> pounds;
	cout << "Enter shillings" << endl;
	cin >> shillings;
	cout << "Enter pence" << endl;
	cin >> pence;

	new_pounds = pounds + (shillings / 20) + (pounds / 240);
	
	

	cout << fixed << setprecision(2) << '\x9c' << new_pounds << endl << endl;;


	// task 11:----------------------------------------------------------------------------------
	// By default, output is right - justified in its field.You can left - justify text output using the
	// manipulator setiosflags(ios::left). (For now, don’t worry about what this new notation means.) 
	// Use this manipulator, along with setw()
	
	cout << "Task 11" << endl;
	int column_width = 18;

	cout << setfill(' ') << setiosflags(ios::left) << setw(column_width) << "Last name" << setw(column_width)
		<< "First name" << setw(column_width) << "Address" << setw(column_width) << "City" << endl;

	cout << setfill('-') << setw(65) << "-" << endl;

	cout << setfill(' ') << setiosflags(ios::left) << setw(column_width) << "Jones" << setw(column_width)
		<< "Bernard" << setw(column_width) << "109 Pine Lane" << setw(column_width) << "Littletown" << endl;

	cout << setiosflags(ios::left) << setw(column_width) << "O’Brian" << setw(column_width)
		<< "Coleen" << setw(column_width) << "42 E. 99th Ave" << setw(column_width) << "Bigcity" << endl;

	cout << setiosflags(ios::left) << setw(column_width) << "Wong" << setw(column_width)
		<< "Harry" << setw(column_width) << "A Alabama St" << setw(column_width) << "Lakeville" << endl <<endl;


	// task 12:----------------------------------------------------------------------------------
	// Write the inverse of Exercise 10, so that the user enters an amount in Great Britain’s new
	// decimal - pounds notation(pounds and pence), and the program converts it to the old
	// pounds - shillings - pence notation.An example of interaction with the program might be
	// Enter decimal pounds : 3.51
	// Equivalent in old notation = £3.10.2.
	// Make use of the fact that if you assign a floating - point value(say 12.34) to an integer
	// variable, the decimal fraction(0.34) is lost; the integer value is simply 12. Use a cast to
	// avoid a compiler warning.You can use statements like
	// float decpounds; // input from user (new-style pounds)
	// int pounds; // old-style (integer) pounds
	// float decfrac; // decimal fraction (smaller than 1.0)
	// pounds = static_cast<int>(decpounds); // remove decimal fraction
	// decfrac = decpounds - pounds; // regain decimal fraction
	// You can then multiply decfrac by 20 to find shillings.A similar operation obtains pence
	

		cout << "Task 11" << endl;
		float decpounds;
		int pounds1, shillings1, pence1;
		float decfrac, decfrac_pence;

		cout << "Enter decimal pounds:" << endl;
		cin >> decpounds;
		
		pounds1 = static_cast<int>(decpounds); 
		decfrac = decpounds - pounds1; 
		shillings1 = static_cast<int>(decfrac * 20); 
		decfrac_pence = decfrac * 20 - shillings1;
		pence1 = static_cast<int>(decfrac_pence * 12);

		cout << "Equivalent in old notation: " << char(156) << pounds1 << "." << shillings1 << "." << pence1 << endl << endl;

	return 0;
}