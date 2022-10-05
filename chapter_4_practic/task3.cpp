// Create a structure called Volume that uses three variables of type Distance(from the
// ENGLSTRC example) to model the volume of a room.Initialize a variable of type Volume
// to specific dimensions, then calculate the volume it represents, and print out the result.
// To calculate the volume, convert each dimension from a Distance variable to a variable
// of type float representing feetand fractions of a foot, and then multiply the resulting
// three numbers

#include <iostream>

int main()
{
	struct Distance
	{
		float meter = 0.0f;
		float cm = 0.0f;
	};

	struct Volume
	{
		Distance lenght;
		Distance width;
		Distance height;
	};

	Volume bedroom;
	

	bedroom.height.meter = 2;
	bedroom.height.cm = 70;
	bedroom.lenght.meter = 3;
	bedroom.lenght.cm = 40;
	bedroom.width.meter = 3;
	bedroom.width.cm = 15;

	std::cout << "Volume of room = " << 
		(bedroom.height.meter + bedroom.height.cm / 100) * (bedroom.lenght.meter + bedroom.lenght.cm / 100) * (bedroom.width.meter + bedroom.width.cm / 100);

	return EXIT_SUCCESS;
}

