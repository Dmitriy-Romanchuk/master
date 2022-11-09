// Start with an array of pointers to strings representing the days of the week, as found in
// the PTRTOSTR program in this chapter. Provide functions to sort the strings into alphabetical order, 
// using variations of the bsort() and order() functions from the PTRSORT program in this chapter.
// Sort the pointers to the strings, not the actual strings.

#include <iostream>

const int SIZE = 7;

void bsort(char**, int);
void order(char**, char**);

int main()
{
	char* arrptrs [SIZE] ={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

	bsort(arrptrs, SIZE);

	for (int j = 0; j < SIZE; ++j)
		std::cout << *(arrptrs + j) << std::endl;

	return 0;
}

void bsort(char** ptr, int n)
{
	for (int j = 0; j < n - 1; ++j)      
		for (int k = j + 1; k < n; ++k)  
			order(ptr + j, ptr + k);    
}

void order(char** s1, char** s2)
{
	if (strcmp(*s1, *s2) > 0)   
	{
		char* temp = *s1; 
		*s1 = *s2;
		*s2 = temp;
	}
}
