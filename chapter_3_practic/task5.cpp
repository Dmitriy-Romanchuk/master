//Use for loops to construct a program that displays a pyramid of Xs on the screen.The
//pyramid should look like this
//     X
//    XXX
//   XXXXX
//  XXXXXXX
// XXXXXXXXX
//except that it should be 20 lines high, instead of the 5 lines shown here.One way to do
//this is to nest two inner loops, one to print spacesand one to print Xs, inside an outer
//loop that steps down the screen from line to line.

#include <iostream>

int main()
{
	int count_of_lines = 20;
	char ch = 'X';
	int counter = 1;

	for (int i = 1; i <= count_of_lines; i++)
	{
		for (int j = 1; j < count_of_lines * 2; j++)
		{
			if(j > (count_of_lines - counter) && j < (count_of_lines + counter))
				std::cout << ch;
			else
				std::cout << " ";	
		}
		counter += 1;
		std::cout << std::endl;
			
	}

	return EXIT_SUCCESS;
}