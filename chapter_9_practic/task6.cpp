// Start with the ARROVER3 program in Chapter 8. Keep the safearay class the same as in
// that program, and, using inheritance, derive the capability for the user to specify both the
// upperand lower bounds of the array in a constructor.This is similar to Exercise 9 in
// Chapter 8, except that inheritance is used to derive a new class (you can call it safehilo)
// instead of modifying the original class.

#include <iostream>

class safearray
{
protected:
	static const int limit = 100;
	int arr[limit]{};
public:
	int& operator[](int n)
	{
		if (n < 0 || n >= limit)
		{
			std::cout << "Error! Incorrect Index";
		}
		return arr[n];
	}
};

class safehilo : public safearray
{
private:
	int bottom; 
	int upper;
public:
	safehilo(int bot, int up) : bottom(bot), upper(up)
	{
		if (bottom > upper)
		{
			std::cout << "Error! bottom must be lower than upper!";
			exit(EXIT_FAILURE);
		}
		if (upper - bottom >= limit)
		{
			std::cout << "Error! Maximum " << limit << " elements!"; 
			exit(EXIT_FAILURE);
		}
	}

	int& operator[] (int n)
	{
		if (n < bottom || n > upper)
		{
			std::cout << "Index Error!"; 
			exit(1);
		}
		return safearray::operator[] (n - bottom);
	}
};

int main()
{
	int low, up;

	std::cout << "Enter bottom: "; 
	std::cin >> low;
	std::cout << "Enter upper: "; 
	std::cin >> up;

	safehilo sa1(low, up);

	for (int j = low; j <= up; j++)
		sa1[j] = j;

	for (int j = low; j <= up; j++)
	{
		int temp = sa1[j];
		std::cout << "Element " << j << " is " << temp << std::endl;
	}

	return EXIT_SUCCESS;
}