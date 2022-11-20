// In the Distance class, as shown in the FRENGLand FRISQ examples in this chapter, create
// an overloaded* operator so that two distances can be multiplied together.Make it a
// friend function so that you can use such expressions as
// Wdist1 = 7.5 * dist2;
// You’ll need a one - argument constructor to convert floating - point values into Distance
// values.Write a main() program to test this operator in several ways.

#include<iostream>

class Distance
{
private:
	int feet;
	float inches;
public:
	Distance() : feet(0), inches(0)
	{}
	Distance(int f, float i) : feet(f), inches(i)
	{}
	Distance(float d)
	{
		feet = int(d);
		inches = 12 * d - feet;
	}
	void showData()
	{
		std::cout << feet << "\'-" << inches << '\"' << std::endl;
	}
	friend Distance operator* (Distance d1, Distance d2)
	{
		int f = d1.feet * d2.feet;
		float i = d1.inches * d2.inches;
		if (i >= 12)
		{
			i -= 12;
			f++;
		}
		return Distance(f, i);
	}
};

int main()
{
	Distance d1(5, 2.25);
	Distance result;

	result = d1 * 10.0;
	result.showData();
	result = 10.0 * d1;
	result.showData();

	return EXIT_SUCCESS;
}