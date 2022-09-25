// Create a three - function calculator for old - style English currency, where money amounts
// are specified in pounds, shillings, and pence. (See Exercises 10 and 12 in Chapter 2.)
// The calculator should allow the user to add or subtract two money amounts, or to multiply a money amount by a floating - point number. 
// (It doesn’t make sense to multiply two
// money amounts; there is no such thing as square money.We’ll ignore division.Use the
// general style of the ordinary four - function calculator in Exercise 4 in this chapter.)

#include <iostream>

int main()
{
	char repeat = 'y';
	char sign = ' ';

	while (repeat == 'y')
	{
		int pounds1 = 0;
		int shillings1 = 0;
		int pence1 = 0;
		int pounds2 = 0;
		int shillings2 = 0;
		int pence2 = 0;
		int pounds = 0;
		int shillings = 0;
		int pence = 0; // for results
		float multiplay = 0.0f;
		char ch = ' ';

		std::cout << "Enter first amount: (5.10.6)"; // Запрос ввода пользователем первого значения
		std::cin >> pounds1 >> ch >> shillings1 >> ch >> pence1;

		std::cout << "Enter operation '+', '-' or '*'";// Выбор операции: сложение, вычитание, умножение и запрос на ввод значений
		std::cin >> sign;
		if ('*' == sign)
		{
			std::cout << "Enter multiply factor: ";
			std::cin >> multiplay;	
		}
		else
		{
			std::cout << "Enter second amount: (3.2.6)";
			std::cin >> pounds2 >> ch >> shillings2 >> ch >> pence2;
		}
		pence1 += shillings1 * 12 + pounds1 * 240; // перевод введенных сумм в пенсы
		pence2 += shillings2 * 12 + pounds2 * 240;


		switch (sign) // калькулятор
		{
		case '+':
			pence = pence1 + pence2;
			shillings = pence / 12;
			while (shillings > 19)
			{
				shillings -= 20;
				pounds += 1;
			}
			pence = pence % 12;
			break;
		case '-':
			pence = pence1 - pence2;
			shillings = pence / 12;
			while (shillings > 19)
			{
				shillings -= 20;
				pounds += 1;
			}
			pence = pence % 12;
			break;
		case '*':
			pence = pence1 * multiplay;
			shillings = pence / 12;
			while (shillings > 19)
			{
				shillings -= 20;
				pounds += 1;
			}
			pence = pence % 12;
			break;
			default:
				std::cout << "Warning: \"" << ch << "\" is unknown operator" << std::endl;
			}

			std::cout << pounds << "." << shillings << "." << pence << std::endl; //Вывод результата
			std::cout << "Do another(y / n) ? "; // воспрос повторить или нет
			std::cin >> repeat;
		}

		return EXIT_SUCCESS;
}