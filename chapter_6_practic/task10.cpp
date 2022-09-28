// Create a class called ship that incorporates a ship’s numberand location.Use the
// approach of Exercise 8 to number each ship object as it is created.Use two variables of
// the angle class from Exercise 7 to represent the ship’s latitude and longitude.A member
// function of the ship class should get a position from the user and store it in the object;
// another should report the serial numberand position.Write a main() program that creates three ships, 
// asks the user to input the position of each, and then displays each ship’s numberand position.3

#include <iostream>

class angle
{
private:
	int degrees;
	float minutes;
	char direction;
public:
	angle() : degrees(0), minutes(0.0), direction('W')
	{}
	angle(int deg, float min, char dir) : degrees(deg), minutes(min), direction(dir)
	{}
	void setdata();
	void showdata() const;
};

class ship
{
private:
	static int count;
	int number;
	angle angle_longitude;
	angle angle_latitude;
public:
	ship() : number(count)
	{
		count++;
	}
	
	void setdata()
	{
		angle_longitude.setdata();
		angle_latitude.setdata();
	}
	void about_boat()
	{
		std::cout << "Boat number " << number << " has coordinates: ";
		angle_longitude.showdata();
		std::cout << " longitude ";
		angle_latitude.showdata();
		std::cout << " latitude " << std::endl;
	}
};

int ship::count = 1;

int main()
{
	ship boat1;
	ship boat2;
	ship boat3;

	boat1.setdata();
	boat2.setdata();
	boat3.setdata();
	boat1.about_boat();
	boat2.about_boat();
	boat3.about_boat();

	return EXIT_SUCCESS;
}

void angle::setdata()
{
	std::cout << "Enter degrees, minutes, direction (for example 90 30.5 W): ";
	std::cin >> angle::degrees >> angle::minutes >> angle::direction;
}

void angle::showdata() const
{
	std::cout << angle::degrees << '\xF8' << angle::minutes << "'" << angle::direction;
}