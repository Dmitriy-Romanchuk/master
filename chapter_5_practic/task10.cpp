// Write a function that, when you call it, displays a message telling how many times it has
// been called : “I have been called 3 times”, for instance.Write a main() program that calls
// this function at least 10 times.Try implementing this function in two different ways.
// First, use a global variable to store the count.Second, use a local static variable.Which
// is more appropriate ? Why can’t you use a local variable ?


#include <iostream>

void println_global();
void println_local();

int counter_global = 0;

int main()
{
	std::cout << "GLOBAL" << std::endl;
	for (int i = 10; i > 0; --i)
		println_global();

	std::cout <<std::endl << "LOCAL" << std::endl;
	for (int i = 10; i > 0; --i)
		println_local();

	return EXIT_SUCCESS;
}

void println_global()
{
	++counter_global;
	std::cout << counter_global << std::endl;
}

void println_local()
{
	static int counter_local = 0;
	++counter_local;
	std::cout << counter_local << std::endl;
}
