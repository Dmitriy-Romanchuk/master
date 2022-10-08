// In ocean navigation, locations are measured in degreesand minutes of latitudeand longitude.
// Thus if you’re lying off the mouth of Papeete Harbor in Tahiti, your location is 149
// degrees 34.8 minutes west longitude, and 17 degrees 31.5 minutes south latitude.
// This is written as 149°34.8’ W, 17°31.5’ S.There are 60 minutes in a degree. (An older system
// also divided a minute into 60 seconds, but the modern approach is to use decimal minutes
// instead.) Longitude is measured from 0 to 180 degrees, east or west from Greenwich,
// England, to the international dateline in the Pacific.Latitude is measured from 0 to 90
// degrees, north or south from the equator to the poles.
// Create a class angle that includes three member variables : an int for degrees, a float
// for minutes, and a char for the direction letter(N, S, E, or W).This class can hold either
// a latitude variable or a longitude variable.Write one member function to obtain an angle
// value(in degrees and minutes) and a direction from the user, and a second to display the
// angle value in 179°59.9’ E format.Also write a three - argument constructor.Write a
// main() program that displays an angle initialized with the constructor, and then, within a
// loop, allows the user to input any angle value, and then displays the value.. You can use
// the hex character constant ‘\xF8’, which usually prints a degree(°) symbol.

#include <iostream>

class angle
{
private:
	int degrees;
	float minutes;
	char direction;
public:
	angle();
	angle(int deg, float min, char dir);
	void setdata();
	void showdata() const;
};

int main()
{
	char ch = 'y';
	angle angle_longitude_1(179, 59.9, 'W');
	angle angle_latitude_1(17, 31.5, 'S');
	angle_longitude_1.showdata();
	angle_longitude_1.showdata();
	
	angle angle_longitude_2;
	angle angle_latitude_2;

	do
	{
		angle_longitude_2.setdata();
		angle_latitude_2.setdata();
		angle_longitude_2.showdata();
		angle_latitude_2.showdata();
		std::cout << "Repeat? y/n: ";
		std::cin >> ch;
	} while ('y' == ch);

	return EXIT_SUCCESS;
}

angle::angle()
{
	degrees = 0;
	minutes = 0.0;
	direction = 'W';
}

angle::angle(int deg, float min, char dir)
{
	degrees = deg;
	minutes = min;
	direction = dir ;
}

void angle::setdata()
{
	std::cout << "Enter degrees, minutes, direction (for example 90 30.5 W): ";
	std::cin >> angle::degrees >> angle::minutes >> angle::direction;
}
void angle::showdata() const
{
	std::cout << "Coordinates is: " << angle::degrees << '\xF8' << angle::minutes << "'" << angle::direction << std::endl;
}