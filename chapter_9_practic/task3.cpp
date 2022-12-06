// Start with the publication, book, and tape classes of Exercise 1. Add a base class sales
// that holds an array of three floats so that it can record the dollar sales of a particular
// publication for the last three months.Include a getdata() function to get three sales
// amounts from the user, and a putdata() function to display the sales figures.Alter the
// bookand tape classes so they are derived from both publicationand sales.An object
// of class book or tape should input and output sales data along with its other data.Write
// a main() function to create a book object and a tape object and exercise their input / output
// capabilities.

#include <iostream>
#include <string>

class sales
{
private:
	static const int month = 3;
	float sale[month]{};
public:
	void getData()
	{
		for (int i = 0; i < month; ++i)
		{
			std::cout << "Enter summ of sales in " << i + 1 << " month: ";
			std::cin >> sale[i];
		}
	}
	void putData()
	{
		for (int i = 0; i < month; ++i)
			std::cout << "Sales in " << i + 1 << " month = " << sale[i] << std::endl;
	}

};

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
		std::cout << "Name: " << name << '\n' << "Price: " << price << "$" << std::endl;
	}
};

class book : private publication, private sales
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
		std::cout << "Count of pages: " << pages << std::endl;
	}
};

class type : private publication, private sales
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
		sales::getData();
	}
	void putData()
	{
		std::cout << "Timing " << timing << " sec" << std::endl;
		sales::putData();
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