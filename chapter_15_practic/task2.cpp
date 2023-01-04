// Apply the sort() algorithm to an array of words entered by the user, and display the
// result.Use push_back() to insert the words, and the[] operator and size() to display
// them.

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

int main()
{
	std::vector<std::string> myVector;
	char ch = 'y';
	std::string temp;
	do
	{
		std::cout << "Enter any word and press Enter" << std::endl;
		std::cin >> temp;
		myVector.push_back(temp);

		std::cout << "another one? y/n" << std::endl;
		std::cin >> ch;
	} while (ch == 'y');

	sort(myVector.begin(), myVector.end());

	for (int i = 0; i < myVector.size(); ++i)
	{
		std::cout << myVector[i] << " ";
	}

	return EXIT_SUCCESS;
}