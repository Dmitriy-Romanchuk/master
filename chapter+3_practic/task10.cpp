// Write a program that calculates how much money you’ll end up with if you invest an
// amount of money at a fixed interest rate, compounded yearly.Have the user furnish the
// initial amount, the number of years, and the yearly interest rate in percent.Some interaction with the program might look like this:
// Enter initial amount : 3000
// Enter number of years : 10
// Enter interest rate(percent per year) : 5.5
// At the end of 10 years, you will have 5124.43 dollars.
// At the end of the first year you have 3000 + (3000 * 0.055), which is 3165. At the end of
// the second year you have 3165 + (3165 * 0.055), which is 3339.08.Do this as many
// times as there are years.A for loop makes the calculation easy

#include <iostream>

int main()
{
	float initial_amount = 0.0f;
	float finish_amount = 0.0f;
	float percent_per_year = 0.0f;
	int counter_of_years = 0;

	std::cout << "Enter initial amount: ";
	std::cin >> initial_amount;
	std::cout << "Enter finish_amount: ";
	std::cin >> finish_amount;
	std::cout << "Enter interest rate(percent per year): ";
	std::cin >> percent_per_year;

	while (initial_amount <= finish_amount)
	{
		initial_amount += (initial_amount * (percent_per_year / 100));
		counter_of_years++;
	}

	std::cout << counter_of_years << " years";

	return EXIT_SUCCESS;
}