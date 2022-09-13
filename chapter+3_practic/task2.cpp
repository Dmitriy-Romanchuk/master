// Write a temperature - conversion program that gives the user the option of converting
// Fahrenheit to Celsius or Celsius to Fahrenheit.Then carry out the conversion.Use
// floating - point numbers.Interaction with the program might look like this:
// Type 1 to convert Fahrenheit to Celsius,
// 2 to convert Celsius to Fahrenheit : 1
// Enter temperature in Fahrenheit : 70
// In Celsius that’s 21.111111

#include <iostream>
#include <iomanip>

int main()
{
	char ch = 'y';
	int user_input = 0;
	float user_temperature = 0.0f;
	float result = 0.0f;

	while(ch == 'y')
	{
		std::cout << "Type 1 to convert Fahrenheit to Celsius, " << std::endl << "2 to convert Celsius to Fahrenheit: ";
		std::cin >> user_input;

		switch (user_input)
		{
		case 1:
			std::cout << "Enter temperature in Fahrenheit: ";
			std::cin >> user_temperature;
			result = (user_temperature - 32.0) / (9.0 / 5.0);
			std::cout << "In Celsius that is: " << result << std::endl;
			break;
		case 2:
			std::cout << "Enter temperature in Celsius: ";
			std::cin >> user_temperature;
			result = user_temperature * 9 / 5 + 32;
			std::cout << "In Fahrenheit that’s: " << result << std::endl;
			break;
		default:
			std::cout << "Error: you should select 1 or 2!" << std::endl;
		}
		std::cout << "Would you like to try again? y/n: ";
		std::cin >> ch;
	}

	return EXIT_SUCCESS;
}