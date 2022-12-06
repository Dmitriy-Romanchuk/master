// Recall the STRCONV example from Chapter 8. The String class in this example has a
// flaw : It does not protect itself if its objects are initialized to have too many characters.
// (The SZ constant has the value 80.) For example, the definition
// String s = “This string will surely exceed the width of the “
// “screen, which is what the SZ constant represents.”;
// will cause the str array in s to overflow, with unpredictable consequences, such as
// crashing the system.
// With String as a base class, derive a class Pstring(for “protected string”) that prevents
// buffer overflow when too long a string constant is used in a definition.A new constructor
// in the derived class should copy only SZ–1 characters into str if the string constant is
// longer, but copy the entire constant if it’s shorter.Write a main() program to test different
// lengths of strings.

#include <iostream>
#include <string.h>

class String
{
protected:
	static const int SZ = 10;
	char str[SZ];
public:
	String()
	{
		str[0] = '\0';
	}
	String(char s[])
	{
		strcpy(str, s);
	}
	void display() const
	{
		std::cout << str;
	}
};

class Pstring : public String
{
public:
	Pstring(char s[])
	{
		if (strlen(s) > SZ - 1)
		{
			int i = 0;
			for (i; i < SZ - 1; ++i)
				str[i] = s[i];
			str[i] = '\0';
		}
		else
			String(s);
	}
};

	int main()
	{
		Pstring s1 = "HelloHelloHello";
		s1.display();

		return EXIT_SUCCESS;
	} 

