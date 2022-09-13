//Create the equivalent of a four - function calculator.The program should ask the user to
//enter a number, an operator,and another number. (Use floating point.) It should then
//carry out the specified arithmetical operation : adding, subtracting, multiplying, or dividing the two numbers.Use a switch statement to select the operation.Finally, display the
//result.
//When it finishes the calculation, the program should ask whether the user wants to do
//another calculation.The response can be ‘y’ or ‘n’.Some sample interaction with the
//program might look like this :
	//Enter first number, operator, second number : 10 / 3
	//Answer = 3.333333
	//Do another(y / n) ? y
	//Enter first number, operator, second number : 12 + 100
	//Answer = 112
	//Do another(y / n) ? n

#include <iostream>

int main()
{
	char ch = ' ';
	char repeat = 'y';
	float first = 0.0f;
	float second = 0.0f;
	float result = 0.0f;

	while (repeat == 'y')
	{
		std::cout << "Enter first number, operator, second number : ";
		std::cin >> first >> ch >> second;

		switch(ch)
		{
			case '+':
				result = first + second;
				break;
			case '-':
				result = first - second;
				break;
			case '/':
				result = first / second;
				break;
			case '*':
				result = first * second;
				break;
			default:
				std::cout << "Warning: \"" << ch <<"\" is unknown operator" << std::endl;
		}
		std::cout << "Answer = " << result << std::endl;
		std::cout << "Do another(y / n) ? ";
		std::cin >> repeat;
	}

	return EXIT_SUCCESS;
}