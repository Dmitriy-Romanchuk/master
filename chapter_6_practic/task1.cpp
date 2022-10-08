// Create a class that imitates part of the functionality of the basic data type int.Call the
// class Int(note different capitalization).The only data in this class is an int variable.
// Include member functions to initialize an Int to 0, to initialize it to an int value, 
// to display it(it looks just like an int), and to add two Int values.
// Write a program that exercises this class by creating one uninitializedand two initialized
// Int values, adding the two initialized valuesand placing the response in the uninitialized
// value, and then displaying this result

#include <iostream>

class Int
{
private:
	int value;
public:
	Int() : value{ 0 }
	{	}
	Int(int a) : value{ a }
	{	}
	void show_value() const
	{
		std::cout << value;
	}
	void add_value(Int b, Int c)
	{
		value = b.value + c.value;
	}
};

int main()
{
	Int one(20);
	Int two(5);
	Int three;

	three.add_value(one, two);
	three.show_value();

	return EXIT_SUCCESS;
}