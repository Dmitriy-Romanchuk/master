// Start with the Distance class from the ENGLCON example in Chapter 6, “Objectsand
// Classes.” Using a loop similar to that in the DISKFUN example in this chapter, 
// get a number of Distance values from the user, and write them to a disk file.Append them to
// existing values in the file, if any.When the user signals that no more values will be
// input, read the fileand display all the values.

#include <fstream>  
#include <iostream>

class Distance
{
private:
	int feet;    
	float inches; 
public:
	Distance() : feet(0), inches(0.0)
	{ }
	Distance(int ft, float in) : feet(ft), inches(in)
	{ }
	void getdist();
	void showdist();
};

int main()
{
	char ch = ' ';
	Distance dist;
	std::fstream file;

	file.open("group.dat", std::ios::app | std::ios::out | std::ios::in | std::ios::binary);

	do
	{
		std::cout << "Enter data:" << std::endl;
		dist.getdist();
		file.write(reinterpret_cast<char*>(&dist), sizeof(dist));
		std::cout << "Continue (y/n)? ";
		std::cin >> ch;
	} while (ch == 'y');

	file.seekg(0);                 
	file.read(reinterpret_cast<char*>(&dist), sizeof(dist));
	int count = 0;
	while (!file.eof())            
	{
		std::cout << "Distance " << ++count << ": ";
		dist.showdist(); std::cout << std::endl;
		file.read(reinterpret_cast<char*>(&dist), sizeof(dist));
	}

	return EXIT_SUCCESS;
}
void Distance::showdist()
{
	std::cout << feet << "\'-" << inches << '\"';
}

void Distance::getdist()
{
	std::cout << "Enter feet:";
	std::cin >> feet;
	std::cout << "Enter inches:";
	std::cin >> inches;
}
