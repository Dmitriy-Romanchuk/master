// Add an exception class to the ARROVER3 program in Chapter 8 so that an out - of - bounds
// index will trigger the exception.The catch block can print an error message for the user.

#include <iostream>

const int LIMIT = 3;

template<class T>
class safearray
{
private:
	T arr[LIMIT]{};
public:
	void putel(int n, T elvalue);
	T getel(int n) const;
	class index_exeption
	{};
};

int main()
{
	try
	{
		safearray<int> s1;
		s1.putel(1, 100);
		std::cout << s1.getel(1) << std::endl;

		safearray<double> s2;
		s2.putel(1, 5.5);
		std::cout << s2.getel(1) << std::endl;
	}
	catch (safearray<int>::index_exeption)
	{
		std::cout << "Error index!";
	}
	catch (safearray<double>::index_exeption)
	{
		std::cout << "Error index!";
	}
	
	return EXIT_SUCCESS;
}

template<class T>
void safearray<T>::putel(int n, T elvalue)
{
	if (n < 0 || n >= LIMIT)
		throw index_exeption();
	arr[n] = elvalue;
}

template<class T>
T safearray<T>::getel(int n) const
{
	if (n < 0 || n >= LIMIT)
		throw index_exeption();
	
	return arr[n];
}