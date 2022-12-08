// In a loop, prompt the user to enter name data consisting of a first name, middle initial,
// last name, and employee number(type unsigned long).Then, using formatted I / O with
// the insertion(<< ) operator, write these four data items to an ofstream object.
// Don’t forget that strings must be terminated with a space or other whitespace character.When the
// user indicates that no more name data will be entered, close the ofstream object, open
// an ifstream object, readand display all the data in the file, and terminate the program.

#include <fstream>
#include <iostream>
#include <string>

int main()
{
	std::string name{};
	std::string middle{};
	std::string surname{};
	unsigned long number = 0;
	char ch = 'y';

	std::ofstream outfile("data.txt"); 

	do {
		std::cout << "Enter number of emploee" << std::endl;
		std::cin >> number;
		std::cout << "Enter name, middle initial, last name:" << std::endl;
		std::cin >> name >> middle >> surname;

		outfile << number << name << " " << middle << " " << surname << " ";
	
		std::cout << "Another one? y/n:" << std::endl;;
		std::cin >> ch; 
	} while (ch == 'y');

	outfile.close();

	std::fstream infile("data.txt");
	
	while (infile >> number >> name >> middle >> surname)
		std::cout << "Emploee " << number << ": "
		<< name << " " << middle << " " << surname << std::endl;

	return EXIT_SUCCESS;
}