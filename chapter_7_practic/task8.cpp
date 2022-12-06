// Another weakness of C++ is that it does not automatically check array indexes to see
// whether they are in bounds. (This makes array operations faster but less safe.) We can
// use a class to create a safe array that checks the index of all array accesses.
// Write a class called safearay that uses an int array of fixed size(call it LIMIT) as its
// only data member.There will be two member functions.The first, putel(), takes an
// index numberand an int value as argumentsand inserts the int value into the array at
// the index.The second, getel(), takes an index number as an argumentand returns the
// int value of the element with that index.
// safearay sa1; // define a safearay object
// int temp = 12345; // define an int value
// sa1.putel(7, temp); // insert value of temp into array at index 7
// temp = sa1.getel(7); // obtain value from array at index 7
// Both functions should check the index argument to make sure it is not less than 0 or
// greater than LIMIT - 1. You can use this array without fear of writing over other parts of
// memory.
// Using functions to access array elements doesn’t look as eloquent as using the[]
// operator. In Chapter 8 we’ll see how to overload this operator to make our safearay
// class work more like built - in arrays.

#include <iostream>

class safearray
{
private:
	int limit[15];
public:
	void putel(int index, int value);
	int getel(int index);
};

int main()
{
	int value = 0;
	int index = 0;
	int button;
	bool repeat = true;
	safearray sa1{};

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
			std::cout << "Enter index: " << std::endl;
			std::cin >> index;
			sa1.putel(index, value);
			break;
		case 2:
			std::cout << "Enter index" << std::endl;
			std::cin >> index;
			if(-1 == sa1.getel(index))
				break;
			std::cout << "Number at index " << index << " is " << sa1.getel(index) << std::endl << std::endl;
			break;
		case 0:
			repeat = false;
			break;
		}
	}

	return EXIT_SUCCESS;
}

void safearray::putel(int index, int value)
{
	if (index < 0 || index > 14)
	{
		std::cout << "You should select index from 0 till 14" << std::endl << std::endl;
		return;
	}

	limit[index] = value;
}

int safearray::getel(int index)
{
	if(index < 0 || index > 14)
	{
		std::cout << "You should select index from 0 till 14" << std::endl << std::endl;
		return -1;
	}

	return limit[index];
}
