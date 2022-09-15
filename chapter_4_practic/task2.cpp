// A point on the two - dimensional plane can be represented by two numbers : an x coordinate and a y coordinate.For example, (4, 5) represents a point 4 units to the right of the
// vertical axis, and 5 units up from the horizontal axis.The sum of two points can be
// defined as a new point whose x coordinate is the sum of the x coordinates of the two
// points, and whose y coordinate is the sum of the y coordinates.
// Write a program that uses a structure called point to model a point.Define three points,
// and have the user input values to two of them.Then set the third point equal to the sum
// of the other two, and display the value of the new point.Interaction with the program
// might look like this:
// Enter coordinates for p1 : 3 4
// Enter coordinates for p2 : 5 7
// Coordinates of p1 + p2 are : 8, 11

#include <iostream>

int main()
{
	struct Point
	{
		int x;
		int y;
	};

	Point first;
	Point second;
	Point third;

	std::cout << "Enter coordinates for p1: (e.g. 3 4): ";
	std::cin >> first.x >> first.y;

	std::cout << "Enter coordinates for p1: (e.g. 5 6): ";
	std::cin >> second.x >> second.y;

	third.x = first.x + second.x;
	third.y = first.y + second.y;

	std::cout << "Coordinates of first + second are: " << third.x << " " << third.y;

	return EXIT_SUCCESS;
}