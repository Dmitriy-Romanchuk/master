#include <iostream>

int main()
{
	// task 7:----------------------------------------------------------------------------------
	// You can convert temperature from degrees Celsius to degrees Fahrenheit by multiplying
	// by 9 / 5 and adding 32. Write a program that allows the user to enter a floating - point number
	// representing degrees Celsius, and then displays the corresponding degrees Fahrenheit.

	float temperature = 0.0f;
	std::cout << "Enter the temperature in degrees Celsius:" << std::endl;
	std::cin >> temperature;
	float temp_fahr = temperature * 9 / 5 + 32;
	std::cout << "Temperature in Fahrenheit = " << temp_fahr << std::endl << std::endl;


	return 0;
}