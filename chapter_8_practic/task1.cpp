// To the Distance class in the ENGLPLUS program in this chapter, add an overloaded
// - operator that subtracts two distances.It should allow statements like dist3 =
// dist1 - dist2; .Assume that the operator will never be used to subtract a larger number
// from a smaller one(that is, negative distances are not allowed).

#include <iostream>

class Distance
{
private:
	int feet;
	float inches;
public:
	Distance() : feet(0) , inches(0.0)
	{}
	Distance(int fe, float in) : feet(fe), inches(in)
	{}
	void getdist()
	{
		std::cout << "Enter feet: ";
		std::cin >> feet;
		std::cout << "Enter inches: ";
		std::cin >> inches;
	}
	void showdist() const
	{
		std::cout << feet << "\'-" << inches << '\"';
	}
	Distance operator - (Distance);

};

int main()
{
	Distance d1(15, 2.25);
	Distance d2(10, 3.86);
	Distance d3;

	d3 = d1 - d2;
	d3.showdist();

	return EXIT_SUCCESS;
}

Distance Distance::operator-(Distance d2)
{
	float dist_to_inches_first = static_cast<float>(feet) * 12 + inches;
	float dist_to_inches_second = static_cast<float>(d2.feet) * 12 + d2.inches;
	float result = dist_to_inches_first - dist_to_inches_second;

	int f = result / 12;
	float i = result - f * 12;
	if (i >= 12)
	{
		i -= 12;
		++f;
	}

	return Distance(f, i);
}
