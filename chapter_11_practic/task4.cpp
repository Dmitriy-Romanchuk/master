// Start with the program of Exercise 1 in this chapter, and add a member function of type
// bool called isOversize() to the bookand tape classes.Let’s say that a book with more
// than 800 pages, or a tape with a playing time longer than 90 minutes(which would
// require two cassettes), is considered oversize.You can access this function from main()
// and display the string “Oversize” for oversize booksand tapes when you display their
// other data.If bookand tape objects are to be accessed using pointers to them that are
// stored in an array of type publication, what do you need to add to the publication
// base class ? Can you instantiate members of this base class ?

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
	virtual bool isOversize() = 0;
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
	bool isOversize()
	{
		return (pages > 800 ? true : false);
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
	bool isOversize()
	{
		return (duration > 90) ? true : false;		
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
	{
		ptr[i]->putData();
		if (ptr[i]->isOversize())
			std::cout << "Oversize" << std::endl;
	}
	return EXIT_SUCCESS;
}