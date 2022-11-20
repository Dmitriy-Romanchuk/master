// Imagine the same publishing company described in Exercise 1 in Chapter 9 that markets
// both book and audiocassette versions of its works.As in that exercise, create a class
// called publication that stores the title(a string) and price(type float) of a publication.
// From this class derive two classes : book, which adds a page count(type int);and tape,
// which adds a playing time in minutes(type float).Each of the three classes should have
// a getdata() function to get its data from the user at the keyboard, and a putdata()
// function to display the data.
// Write a main() program that creates an array of pointers to publication.This is similar
// to the VIRTPERS example in this chapter.In a loop, ask the user for data about a particular
// book or tape, and use new to create an object of type book or tape to hold the data.Put
// the pointer to the object in the array.When the user has finished entering the data for all
// booksand tapes, display the resulting data for all the booksand tapes entered, using a
// for loopand a single statement such as
// pubarr[j]->putdata();
// to display the data from each object in the array

#include <iostream>
#include <string>

class publication
{
protected:
	std::string name = "Not added!";
	float price = 0.f;
public:
	virtual void getData()
	{
		std::cout << "Enter book's name" << std::endl;
		std::cin >> name;
		std::cout << "Enter price:" << std::endl;
		std::cin >> price;
	}
	virtual void putData() const
	{
		std::cout << "Book's name is: " << name << ", price: " << price;
	}
};

class book : public publication
{
private:
	int pages = 0;
public:
	void getData()
	{
		publication::getData();
		std::cout << "Enter pages count of book" << std::endl;
		std::cin >> pages;
	}
	void putData() const
	{
		publication::putData();
		std::cout << ", pages count of book are: " << pages << std::endl;
	}
};

class type : public publication
{
private:
	float duration = 0.f;
public:
	void getData()
	{
		publication::getData();
		std::cout << "Enter the duration of the recording" << std::endl;
		std::cin >> duration;
	}
	void putData() const
	{
		publication::putData();
		std::cout << ", duration of the recording are: " << duration << std::endl;
	}
};

int main()
{
	publication* ptr[100]{};
	int n = 0;
	char ch = ' ';

	do
	{
		std::cout << "Select book (b) or type (t)" << std::endl;
		std::cin >> ch;
		if ('b' == ch)
		{
			ptr[n] = new book;
		}
		if ('t' == ch)
		{
			ptr[n] = new type;
		}
		ptr[n++]->getData();

		std::cout << "Would you like to add another item? y/n:" << std::endl;
		std::cin >> ch;
		
	} while ('y' == ch);

	for (int i = 0; i < n; ++i)
		ptr[i]->putData();

	return EXIT_SUCCESS;
}