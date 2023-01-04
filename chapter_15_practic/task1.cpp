// Write a program that applies the sort() algorithm to an array of floating point values
// entered by the user, and displays the result.

#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	std::vector<float> myVector;
	char ch = 'y';
	float temp = 0;
	do
	{
		std::cout << "Enter float number" << std::endl;
		std::cin >> temp;
		myVector.push_back(temp);

		std::cout << "another one? y/n"<< std::endl;
		std::cin >> ch;
	} while (ch == 'y');

	sort(myVector.begin(), myVector.end());

	for (int i = 0; i < myVector.size(); ++i)
	{
		std::cout << myVector[i] << " ";
	}

	return EXIT_SUCCESS;
}