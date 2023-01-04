// In Exercise 3, two ordinary(non - reverse) iterators were used to reverse the contents of a
// container.Now use one forwardand one reverse iterator to carry out the same task, this
// time on a vector.

#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	std::vector<int> myVec;

	for (int i = 0; i < 10; ++i)
	{
		myVec.push_back(i * 3);
	}

	std::vector<int>::iterator iter;
	std::vector<int>::reverse_iterator reviter;

	iter = myVec.begin();
	reviter = myVec.rbegin();

	int size = myVec.size() / 2;
	for(int i = 0; i < size; ++i)
	{
		std::swap(*iter, *reviter);

		++iter;;
		++reviter;
	}

	for (iter = myVec.begin(); iter != myVec.end(); ++iter)
	{
		std::cout << *iter << " ";
	}
	return EXIT_SUCCESS;
}