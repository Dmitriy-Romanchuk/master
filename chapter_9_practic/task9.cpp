// Start with the publication, book, and tape classes of Exercise 1. Suppose you want to
// add the date of publication for both booksand tapes.From the publication class, derive
// a new class called publication2 that includes this member data.Then change bookand
// tape so they are derived from publication2 instead of publication.Make all the
// necessary changes in member functions so the user can inputand output dates along with
// the other data.For the dates, you can use the date class from Exercise 5 in Chapter 6,
// which stores a date as three ints, for month, day, and year.

#include <iostream>
#include <iomanip>
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

class publication2 : public publication
{
protected:
	int day;
	int month;
	int year;
	char ch;
public:
	publication2() : month{ 0 }, day{ 0 }, year{ 0 }, ch{ ' ' }
	{}
	void getdate()
	{
		std::cout << "Enter date in format dd/mm/yyyy: ";
		std::cin >> day >> ch >> month >> ch >> year;
	}
	void showdate() const
	{
		std::cout << std::setiosflags(std::ios::right) << std::setfill('0') << "Publication date is : "
			<< std::setw(2) << day << ch << std::setw(2) << month << ch << std::setw(4) << year << std::endl;
	}
};

class book : public publication, public publication2
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
		publication2::getdate();
	}
	void putData()
	{
		publication::putData();
		std::cout << "Count of pages " << pages << std::endl;
		publication2::showdate();
	}
};

class type : public publication, public publication2
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