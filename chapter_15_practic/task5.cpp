// Fill an array with even numbersand a set with odd numbers.Use the merge() algorithm
// to merge these containers into a vector.Display the vector contents to show that all went
// well.

#include<iostream>
#include<set>
#include<list>
#include<vector>
#include<algorithm>

int main()
{
	int myArr[] = {1, 3, 5, 7, 9, 11};
	std::set<int> mySet;
	std::vector<int>myVec(12);
	std::vector<int>::iterator iter;

	mySet.insert(2);
	mySet.insert(4);
	mySet.insert(6);
	mySet.insert(8);
	mySet.insert(10);
	mySet.insert(12);

	std::merge(myArr, myArr + 6, mySet.begin(), mySet.end(), myVec.begin());

	for (iter = myVec.begin(); iter != myVec.end(); ++iter)
	{
		std::cout << *iter << " ";
	}
	
	return EXIT_SUCCESS;
}