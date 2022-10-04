// Write a program that calculates the average of up to 100 English distances input by the
// user.Create an array of objects of the Distance class, as in the ENGLARAY example in
// this chapter.To calculate the average, you can borrow the add_dist() member function
// from the ENGLCON example in Chapter 6. You’ll also need a member function that divides
// a Distance value by an integer.Here’s one possibility :
// void Distance::div_dist(Distance d2, int divisor)
// {
// 	float fltfeet = d2.feet + d2.inches / 12.0;
// 	fltfeet /= divisor;
// 	feet = int(fltfeet);
// 	inches = (fltfeet - feet) * 12.0;
// }

#include <iostream>

class distance
{
private:
	int feet;
	float inches;
public:
	distance() : feet(0), inches(0.0)
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
		std::cout << feet << "\'" << inches << "\"";
	}
	void addDist(distance);
	void divDist(distance, int);
};

int main()
{
	const int MAX = 100;
	distance flat[MAX]{};
	distance summ;
	distance result;

	for (int j = 0; j < MAX; j++)
	{
		flat[j].getdist();
	}

	for (int i = 0; i < MAX; i++)
	{
		summ.addDist(flat[i]);
	}

	result.divDist(summ, MAX);
	result.showdist();

	return EXIT_SUCCESS;
}

void distance::addDist(distance d)
{
	inches += d.inches;
	if (inches >= 12.0)
	{
		inches -= 12.0;
		feet++;
	}
	feet += d.feet;
}

void distance::divDist(distance d2, int divisor)
{
	float fitfeet = d2.feet + d2.inches / 12.0;
	fitfeet /= divisor;
	feet = int(fitfeet);
	inches = (fitfeet - feet) * 12.0;
}
