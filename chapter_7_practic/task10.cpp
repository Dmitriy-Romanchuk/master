// A matrix is a two - dimensional array.Create a class matrix that provides the same safety
// feature as the array class in Exercise 7; that is, it checks to be sure no array index is out
// of bounds.Make the member data in the matrix class a 10 - by - 10 array.A constructor
// should allow the programmer to specify the actual dimensions of the matrix(provided
// they’re less than 10 by 10).The member functions that access data in the matrix will now
// need two index numbers : one for each dimension of the array.Here’s what a fragment of
// a main() program that operates on such a class might look like :
// matrix m1(3, 4); // define a matrix object
// int temp = 12345; // define an int value
// m1.putel(7, 4, temp); // insert value of temp into matrix at 7,4
// temp = m1.getel(7, 4); // obtain value from matrix at 7,4

#include <iostream>

class matrix
{
private:
	static const int max_1 = 10;
	static const int max_2 = 10;
	int limit[max_1][max_2]{};
	int custom_max_1 = 0;
	int custom_max_2 = 0;
public:
	matrix()
	{}
	matrix(int a, int b)
	{
		custom_max_1 = a;
		custom_max_2 = b;
		limit[custom_max_1][custom_max_2];
	}
	void putel(int index1, int index2, int value);
	int getel(int index1, int index2);
	int get_custom_max_1()
	{
		return custom_max_1;
	}
	int get_custom_max_2()
	{
		return custom_max_2;
	}
};

int main()
{
	int value = 0;
	int index_1 = 0;
	int index_2 = 0;
	int button = 0;
	bool repeat = true;
	matrix ma1(8, 8);

	while (repeat)
	{
		std::cout << "press 1 to enter information." << std::endl
			<< "press 2 to display information." << std::endl
			<< "press 0 to exit." << std::endl;
		std::cin >> button;

		switch (button)
		{
		case 1:
			std::cout << "Enter value: " << std::endl;
			std::cin >> value;
			std::cout << "Enter first index : " << std::endl;
			std::cin >> index_1;
			std::cout << "Enter second index : " << std::endl;
			std::cin >> index_2;
			ma1.putel(index_1,index_2, value);
			break;
		case 2:
			std::cout << "Enter first index" << std::endl;
			std::cin >> index_1;
			std::cout << "Enter second index : " << std::endl;
			std::cin >> index_2;
			if(-1 == ma1.getel(index_1, index_2))
				break;
			std::cout << "Number at index [" << index_1 << "][" << index_2 << "] is " << ma1.getel(index_1, index_2) << std::endl << std::endl;
			break;
		case 0:
			repeat = false;
			break;
		}
	}

	return EXIT_SUCCESS;
}

void matrix::putel(int index1, int index2, int value)
{
	if ((index1 < 0 || index1 > custom_max_1) || (index2 < 0 || index2 > custom_max_2))
	{
		std::cout << "You should select index_1 from 0 till " << custom_max_1 << std::endl;
		std::cout << "You should select index_2 from 0 till " << custom_max_2 << std::endl << std::endl;
		return;
	}

	limit[index1][index2] = value;
}

int matrix::getel(int index1, int index2)
{
	if((index1 < 0 || index1 > custom_max_1) || (index2 < 0 || index2 > custom_max_2))
	{
		std::cout << "You should select index_1 from 0 till " << custom_max_1 << std::endl;
		std::cout << "You should select index_2 from 0 till " << custom_max_2 << std::endl << std::endl;
		return -1;
	}

	return limit[index1][index2];
}