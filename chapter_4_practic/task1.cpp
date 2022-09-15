// A phone number, such as(212) 767 - 8900, can be thought of as having three parts : the
// area code(212), the exchange(767), and the number(8900).Write a program that uses a
// structure to store these three parts of a phone number separately.Call the structure
// phone.Create two structure variables of type phone.Initialize one, and have the user
// input a number for the other one.Then display both numbers.The interchange might
// look like this :
// Enter your area code, exchange, and number : 415 555 1212
// My number is(212) 767 - 8900
// Your number is(415) 555 - 1212

#include <iostream>

int main()
{
	struct Phone
	{
		int code;
		int exchange;
		int number;
	};

	Phone my_phone {212, 870, 8491};
	Phone your_phone;

	std::cout << "Enter your area code, exchange, and number: XXX XXX XXXX: ";
	std::cin >> your_phone.code >> your_phone.exchange >> your_phone.number;

	std::cout << "My number is: (" << my_phone.code << ") " << my_phone.exchange << "-" << my_phone.number << std::endl;
	std::cout << "Your number is: (" << your_phone.code << ") " << your_phone.exchange << "-" << your_phone.number << std::endl;

	return EXIT_SUCCESS;
}