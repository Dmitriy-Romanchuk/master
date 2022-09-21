// Create a four - function calculator for fractions. (See Exercise 9 in Chapter 2, and
// Exercise 4 in this chapter.) Here are the formulas for the four arithmetic operations
// applied to fractions :
// Addition:        a / b + c / d = (a * d + b * c) / (b * d)
// Subtraction :    a / b - c / d = (a * d - b * c) / (b * d)
// Multiplication : a / b * c / d = (a * c) / (b * d)
// Division :       a / b / c / d = (a * d) / (b * c)
// The user should type the first fraction, an operator,and a second fraction.The program
// should then display the result and ask whether the user wants to continue.

#include <iostream>

int main()
{
	char repeat = 'y';
	
	struct fraction
	{
		int nominator;
		int denominator;
	};

	while (repeat == 'y')
	{
		fraction first;
		fraction second;
		fraction third;
		
		float result = 0.0f;
		char i = ' ';
		char sign = ' ';

		std::cout << "Enter first fraction : for example 1/2" << std::endl;
		std::cin >> first.nominator >> i >> first.denominator;
		std::cout << "Enter operation '+', '-', '*', '/' ";// Выбор операции: сложение, вычитание, умножение и запрос на ввод значений
		std::cin >> sign;
		std::cout << "Enter second fraction : for example 2/5" << std::endl;
		std::cin >> second.nominator >> i >> second.denominator;
	
		switch (sign) // калькулятор
		{
		case '+':
			std::cout << "Result is: " << (first.nominator * second.denominator + first.denominator * second.nominator) << "/" << (first.denominator * second.denominator) << std::endl;
			break;
		case '-':
			std::cout << "Result is: " << (first.nominator * second.denominator - first.denominator * second.nominator) << "/" << (first.denominator * second.denominator) << std::endl;
			break;
		case '*':
			std::cout << "Result is: " << (first.nominator * second.nominator) << "/" << (first.denominator * second.denominator) << std::endl;
			break;
		case '/':
			std::cout << "Result is: " << (first.nominator * second.denominator) << "/" << (first.denominator * second.nominator) << std::endl;
			break;
			default:
				std::cout << "Warning: \"" << sign << "\" is unknown operator" << std::endl;
		}

			std::cout << "Do another(y / n) ? "; // воспрос повторить или нет
			std::cin >> repeat;
		}

		return EXIT_SUCCESS;
}