// Make your own version of the library function strcmp(s1, s2), which compares two
// stringsand returns –1 if s1 comes first alphabetically, 0 if s1and s2 are the same, and 1
// if s2 comes first alphabetically.Call your function compstr().It should take two char*
// strings as arguments, compare them character by character, and return an int.Write a
// main() program to test the function with different combinations of strings.Use pointer
// notation throughout

#include <iostream>
#include <string.h>

int compstr(char*, char*);

int main()
{
	char* sentense1 = "abcde";
	char* sentense2 = "abcde";
	char* sentense3 = "abcdef";

	std::cout << compstr(sentense1, sentense2) << std::endl; //expected 0
	std::cout << compstr(sentense1, sentense3) << std::endl; //expected -1
	std::cout << compstr(sentense3, sentense2) << std::endl; //expected 1

	return EXIT_SUCCESS;
}

int compstr(char* s1, char* s2)
{	
	int lenght = strlen(s1) < strlen(s2) ? strlen(s1) : strlen(s2);
	int ret = -2;
	
	for (int i = 0; i < lenght; ++i)
	{
		if ((*(s1 + i)) < (*(s2 + i)))
		{
			ret = -1;
			break;
		}
		if ((*(s1 + i)) > (* (s2 + i)))
		{
			ret = 1;
			break;
		}
		if ((*(s1 + i)) == (*(s2 + i)))
		{
			ret = 0;
		}	
	}

	if(ret == 0 && strlen(s1) != strlen(s2))
		ret = strlen(s1) < strlen(s2) ? -1 : 1;

	return ret;
}