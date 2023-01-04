// Start with a list of int values.Use two normal(not reverse) iterators, 
// one moving forward through the listand one moving backward, in a while loop, to reverse the contents
// of the list.You can use the swap() algorithm to save a few statements. (Make sure your
// solution works for both evenand odd numbers of items.) To see how the experts do it,
// look at the reverse() function in your compiler’s ALGORITHM header file.

#include<iostream>
#include<list>
#include<algorithm>

int main()
{
	std::list<int> myList;

	for (int i = 0; i < 10; ++i)
	{
		myList.push_back(i * 3);
	}

	std::list<int>::iterator iter;
	std::list<int>::iterator reviter;
	
	iter = myList.begin();
	reviter = myList.end();
	--reviter;

	while (iter != reviter)
	{
		std::swap(*iter, *reviter);

		++iter;
		
		if (iter == reviter)
			break;
		--reviter;
	}

	for (iter = myList.begin(); iter != myList.end(); ++iter)
	{
		std::cout << *iter << " ";
	}
	return EXIT_SUCCESS;
}