// Write a program that emulates the DOS COPY command.That is, it should copy the contents of a text file(such as any.CPP file) to another file.Invoke the program with two
// command - line arguments—the source file and the destination file—like this:
// C > ocopy srcfile.cpp destfile.cpp
// In the program, check that the user has typed the correct number of command - line arguments, and that the files specified can be opened

#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "incorrect format" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::ifstream source;           
	source.open(argv[1]);
	if (!source)
	{
		std::cout << "Can't open " << argv[1] << std::endl;
		exit(-1);
	}

	std::ofstream destination;
	destination.open(argv[2]);      
	if (!destination)
	{
		std::cout << "Can't open " << argv[2] << std::endl;
		exit(EXIT_FAILURE);
	}

	char ch = ' ';
	while (source.get(ch))
		destination.put(ch);

	std::cout << "Succsessful!" << std::endl;

	return EXIT_SUCCESS;
}