// Assume that the publisher in Exercises 1 and 3 decides to add a third way to distribute
// books : on computer disk, for those who like to do their reading on their laptop.Add a
// disk class that, like bookand tape, is derived from publication.The disk class should
// incorporate the same member functions as the other classes.The data item unique to this
// class is the disk type : either CD or DVD.You can use an enum type to store this item.
// The user could select the appropriate type by typing c or d.

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

class disk : private publication
{
private:
	enum class disk_type {CD,DVD};
	disk_type d_type{};
public:
	void getData()
	{
		char ch = ' ';
		std::cout << "Enter Type of Disk 'c' or 'd': ";
		std::cin >> ch;
		switch (ch)
		{
		case 'c':
			d_type = disk_type::CD;
			break;
		case 'd':
			d_type = disk_type::DVD;
			break;
		}
	}
	void putData()
	{
		std::cout << "Disk type is: ";
		switch (d_type)
		{
		case disk_type::CD:
			std::cout << "CD" << std::endl;
			break;
		case disk_type::DVD:
			std::cout << "DVD" << std::endl;
			break;
		}
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
	disk d1;

	b1.getData();
	t1.getData();
	d1.getData();
	b1.putData();
	t1.putData();
	d1.putData();

	return EXIT_SUCCESS;
}