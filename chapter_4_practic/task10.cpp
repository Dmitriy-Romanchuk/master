// Create a structure called sterling that stores money amounts in the old - style British
// system discussed in Exercises 8 and 11 in Chapter 3, “Loopsand Decisions.” The members could be called pounds, shillings, and pence, all of type int.The program should
// ask the user to enter a money amount in new - style decimal pounds(type double), convert it to the old - style system, store it in a variable of type struct sterling, and then
// display this amount in pounds - shillings - pence format.

#include <iostream>

int main()
{
	float decpounds = 0.0f;
	float decfrac = 0.0f;
	float decfrac_pence = 0.0f;

	struct sterling
	{
		int pounds;
		int shillings;
		int pence;
	};

	sterling st;

	std::cout << "Enter decimal pounds:" << std::endl;
	std::cin >> decpounds;

	st.pounds = static_cast<int>(decpounds);
	decfrac = decpounds - st.pounds;
	st.shillings = static_cast<int>(decfrac * 20);
	decfrac_pence = decfrac * 20 - st.shillings;
	st.pence = static_cast<int>(decfrac_pence * 12);

	std::cout << st.pounds << "." << st.shillings << "." << st.pence;

	return EXIT_SUCCESS;
}