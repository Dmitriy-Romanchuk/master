// Write a program that substitutes an overloaded += operator for the overloaded + operator
// in the STRPLUS program in this chapter.This operator should allow statements like
// s1 += s2;
// where s2 is added(concatenated) to s1and the result is left in s1.The operator should
// also permit the results of the operation to be used in other calculations, as in
// s3 = s1 += s2;

#include <iostream>
#include <string.h>
#include <stdlib.h>

class string
{
private:
	static const int SZ= 80;
	char str[SZ];
public:
	string()
	{
		strcpy(str, "");
	}
	string(char s[])
	{
		strcpy(str, s);
	}
	void display()
	{
		std::cout << str << std::endl;
	}
	string operator += (string ss)
	{
		int source_str = strlen(str);
		int addes_str = strlen(ss.str);

		if (source_str + addes_str < SZ)
			return strcat(str, ss.str);
		else
		{
			std::cout << "Text is too long" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
};

int main()
{
	string s1 = "Hello_";
	string s2 = "Dima";
	string s3 = "Test";
	s1 += s2;
	s1.display();
	s3 = s1 += s2;
	s3.display();

	return EXIT_SUCCESS;
}