// Imagine a publishing company that markets both bookand audiocassette versions of its
// works.Create a class publication that stores the title(a string) and price(type float)
// of a publication.From this class derive two classes : book, which adds a page count(type
// int), and tape, which adds a playing time in minutes(type float).Each of these three
// classes should have a getdata() function to get its data from the user at the keyboard,
// and a putdata() function to display its data.
// Write a main() program to test the bookand tape classes by creating instances of them,
// asking the user to fill in data with getdata(), and then displaying the data with putdata().

#include <iostream>
#include <string>

class publication
{
private:
	std::string name;
	float price;
public:
	publication() : name("N/A"), price(0.f)
	{}
	void getData()
	{
		std::cout << "Enter name of book:" << std::endl;
		std::cin >> name;
		std::cout << "Enter price:" << std::endl;
		std::cin >> price;
	}
	void putData()
	{
		std::cout << "Name " << name << ", price " << price << std::endl;
	}
};

class book : private publication
{
private:
	int pages;
public:
	book() : pages(0)
	{}
	book(int p) : pages(p)
	{}
	void getData()
	{
		publication::getData();
		std::cout << "Enter count of pages:" << std::endl;
		std::cin >> pages;
	}
	void putData()
	{
		publication::putData();
		std::cout << "Count of pages " << pages << std::endl;
	}
};

class type : private publication
{
private:
	float timing;
public:
	type() : timing(0.f)
	{}
	type(float t) : timing(t)
	{}
	void getData()
	{
		std::cout << "Enter timing:" << std::endl;
		std::cin >> timing;
	}
	void putData()
	{
		std::cout << "Timing " << timing << std::endl;
		
	}
};

int main()
{
	book b1;
	type t1;

	b1.getData();
	t1.getData();
	b1.putData();
	t1.putData();

	return EXIT_SUCCESS;
}