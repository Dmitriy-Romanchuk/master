// Write a program that returns the size in bytes of a program entered on the command
// line :
// C > filesize program.ext

#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Enter file name as argument!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::ifstream infile;
	infile.open(argv[1]);

	infile.seekg(0, std::ios::end);
	std::cout << "File size " << argv[1] << " = " << infile.tellg() << " bites" << std::endl;

	return EXIT_SUCCESS;
}
