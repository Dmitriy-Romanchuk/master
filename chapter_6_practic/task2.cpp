// Imagine a tollbooth at a bridge.Cars passing by the booth are expected to pay a 50 cent
// toll.Mostly they do, but sometimes a car goes by without paying.The tollbooth keeps
// track of the number of cars that have gone by, and of the total amount of money collected.
// Model this tollbooth with a class called tollBooth.The two data items are a type
// unsigned int to hold the total number of cars, and a type double to hold the total amount
// of money collected.A constructor initializes both of these to 0. A member function called
// payingCar() increments the car total and adds 0.50 to the cash total.Another function,
// called nopayCar(), increments the car total but adds nothing to the cash total.Finally, a
// member function called display() displays the two totals.Make appropriate member
// functions const.
// Include a program to test this class.This program should allow the user to push one key
// to count a paying car, and another to count a nonpaying car.Pushing the Esc key should
// cause the program to print out the total carsand total cashand then exit.


#include <iostream>
#include <conio.h>

class toolBooth
{
private:
	unsigned int counter;
	double revenue;
public:
	toolBooth() : counter(0), revenue(0.0)
	{	}
	void payingCar()
	{
		counter++;
		revenue += 0.5;
	}
	void nopayCar()
	{
		counter++;
	}
	void display() const
	{
		std::cout << "Number of cars " << counter << " and revenue = " << revenue << "$" << std::endl;
	}
};

int main()
{
	toolBooth m1;
	bool flag = true;
	char select = ' ';

	while (flag)
	{
		std::cout << "Did the driver pay? y/n? " << std::endl;
		select = getch();

		if ('y' == select)
			m1.payingCar();
		else if ('n' == select)
			m1.nopayCar();
		else if (27 == select)
		{
			m1.display();
			flag = false;
		}
	}

	return EXIT_SUCCESS;
}