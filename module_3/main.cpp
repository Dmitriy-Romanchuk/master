#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// Task1:
	// Assuming there are 7.481 gallons in a cubic foot, write a program that asks the user to
	// enter a number of gallons, and then displays the equivalent in cubic feet

	cout << "Task 1" << endl;
	const float ratio = 7.481f;
	float user_input;

	cout << "Enter the number of gallons:" << endl;
	cin >> user_input;
	cout << user_input << " gallons = " << user_input / ratio << " cubic pounds" << endl << endl;

	
	//task2:
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




	return 0;
}