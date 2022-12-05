// Refer to the CIRCAREA program in Chapter 2, “C++ Programming Basics.” Write a function 
// called circarea() that finds the area of a circle in a similar way.It should take an
// argument of type floatand return an argument of the same type.Write a main() function 
// that gets a radius value from the user, calls circarea(), and displays the result.

#include <iostream>

inline float circarea(float s); //declaration
const float PI = 3.14159f;
float radius = 0.0f;
float square = 0.0f;

int main()
{
	std::cout << "Enter radius: " << std::endl;
	std::cin >> radius;

	circarea(radius);

	std::cout << "The area of a circle with a radius = " << radius << " is " << square << std::endl;

	return EXIT_SUCCESS;
}

//--------------------------------------------------
float circarea(float s) //definition
{
	square = PI * radius * radius;
	return square;
}