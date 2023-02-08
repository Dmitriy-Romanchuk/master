// Make a class called name from the data in Exercise 4 (first name, middle initial, last
// name, employee number).Create member functions for this class that readand write an
// object’s data to a disk file, using ofstream, and read it back using ifstream.
// Use formatted data with the << and >> operators.The read and write member functions should
// be self - contained : they should include statements to open the appropriate stream and read or write a record.
// The write function can simply append its data to the end of the file.The read function
// will need a way to select which record it’s going to read.One way to do this is to call it
// with a parameter representing the record number.Once it knows which record it should
// read, how does the read function find the record ? You might think you could use the
// seekg() function, but that isn’t much help because in formatted I / O the records are all
// different lengths(depending on the number of characters in the strings and the number
// of digits in the integer).So you’ll need to actually read records until you’ve skipped forward to the one you want.
// In main(), call these member functions to allow the user to enter data for a number of
// objects that are written to a file as they are entered.The program then displays all this
// data by reading it from the file.

#include <fstream>
#include <iostream>
#include <string>

class Name
{
private:
	std::string name{};
	std::string middle{};
	std::string surname{};
	unsigned long number = 0;
public:
	void get_data();
	void showData();
	void write_to_disk();
	void read_from_disk(int);
	static unsigned int diskCount();
};

int main()
{
	Name emploee;
	char ch = 'y';

	do {
		emploee.get_data();
		emploee.write_to_disk();
		std::cout << "Another one? y/n: ";
		std::cin >> ch;
	} while (ch == 'y');

	int records = Name::diskCount();

	for (int j = 1; j <= records; ++j)
	{
		emploee.read_from_disk(j);
		emploee.showData();
	}
	std::cout << std::endl;

	return 0;
}

void Name::get_data()
{
	std::cout << "Enter number of emploee" << std::endl;
	std::cin >> number;
	std::cout << "Enter name, middle initial, last name:" << std::endl;
	std::cin >> name >> middle >> surname;
}

void Name::showData()
{
	std::cout << "Emploee " << number << ": " << name << " " << middle << " " << surname << std::endl;
}

void Name::write_to_disk()
{
	std::ofstream outfile;
	outfile.open("PERSFILE.txt", std::ios::app);
	outfile << number << name << " " << middle << " " << surname << " ";
}

void Name::read_from_disk(int rec)
{
	std::fstream infile;
	infile.open("PERSFILE.txt");
	int count = 1;
	while (infile >> number >> name >> middle >> surname && count != rec)
		count++;
}

unsigned int Name::diskCount()
{
	std::fstream infile; 
	infile.open("PERSFILE.txt");
	unsigned int count = 0;
	std::string name, middle, surname;
	unsigned long number;
	while (infile >> number >> name >> middle >> surname)
		++count;
	return count;
}

