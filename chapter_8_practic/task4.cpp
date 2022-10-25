// Create a class Int based on Exercise 1 in Chapter 6. Overload four integer arithmetic
// operators(+, -, *, and / ) so that they operate on objects of type Int.If the result of any
// such arithmetic operation exceeds the normal range of ints(in a 32 - bit environment)—
// from 2, 147, 483, 648 to –2, 147, 483, 647—have the operator print a warning and terminate
// the program.Such a data type might be useful where mistakes caused by arithmetic overflow are unacceptable.Hint : To facilitate checking for overflow, perform the calculations
// using type long double.Write a program to test this class.

#include <iostream>

class Int
{
private:
	int value;
public:
	Int();
	Int(int a);
	Int operator+ (Int b);
	Int operator- (Int b);
	Int operator* (Int b);
	Int operator/ (Int b);
	void show_value() const;
	long double compare(long double result) const;
};

int main()
{
	Int one(20);
	Int two(5);
	Int three;

	three = one + two;
	three.show_value();
	three = one - two;
	three.show_value();
	three = one * two;
	three.show_value();
	three = one / two;
	three.show_value();

	Int overflow = one + 2147483647; // test overflow
	overflow.show_value();

	return EXIT_SUCCESS;
}

Int::Int() : value{ 0 }
{	}

Int::Int(int a) : value{ a }
{	}

Int Int::operator+ (Int b)
{
	long double result;
	result = static_cast<long double>(value) + b.value;
	return compare(result);
}

Int Int::operator- (Int b)
{
	long double result;
	result = static_cast<long double>(value) - b.value;
	return compare(result);
}

Int Int::operator* (Int b)
{
	long double result;
	result = static_cast<long double>(value) * b.value;
	return compare(result);
}

Int Int::operator/ (Int b)
{
	long double result;
	result = static_cast<long double>(value) / b.value;
	return compare(result);
}

void Int::show_value() const
{
	std::cout << value << std::endl;
}

long double Int::compare(long double result) const
{
	const int min = -2147483648;
	const int max = 2147483647;

	if (result >= min && result <= max)
		return result;
	else
	{
		std::cout << "Number is too long" << std::endl;
		exit(EXIT_FAILURE);
	}
}