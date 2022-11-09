// Start with the String class from the NEWSTR example in this chapter.Add a member
// function called upit() that converts the string to all uppercase.You can use the
// toupper() library function, which takes a single character as an argumentand returns a
// character that has been converted(if necessary) to uppercase.This function uses the
// CCTYPE header file.Write some code in main() to test upit().

#include <iostream>
#include <string.h>
#include <cctype>

class String
{
private:
	char* str;
public:
	String(char* s)
	{
		int lenght = strlen(s);
		str = new char[lenght + 1];
		strcpy(str, s);
		upit(str);
	}
	void display() const
	{
		std::cout << str << std::endl;
	}
	void upit(char* p)
	{
		while (*p)
		{
			*p = toupper(*p);
			p++;
		}
	}
	~String()
	{
		std::cout << "Delete objects";
		delete[] str;
	}
};

int main()
{
	String s1 = "Test";
	s1.display();

	return EXIT_SUCCESS;
}