// Start with the safearay class from the ARROVER3 program in Chapter 8. Make this class
// into a template, so the safe array can store any kind of data.In main(), create safe arrays
// of at least two different types, and store some data in them.

#include <iostream>

const int LIMIT = 3;

template<class T>
class safearray
{
private:
	T arr[LIMIT];
public:
	void putel(int n, T elvalue);
	T getel(int n) const;
};

int main()
{
	safearray<int> s1;
	s1.putel(1, 100);
	std::cout << s1.getel(1) << std::endl;

	safearray<double> s2;
	s2.putel(0, 5.5);
	std::cout << s2.getel(0) << std::endl;

	return EXIT_SUCCESS;
}

template<class T>
void safearray<T>::putel(int n, T elvalue)
{
	if (n < 0 || n >= LIMIT)
	{
		std::cout << "Index Error";
		exit(EXIT_FAILURE);
	}
	arr[n] = elvalue;
}

template<class T>
T safearray<T>::getel(int n) const
{
	if (n < 0 || n >= LIMIT)
	{
		std::cout << "Index Error";
		exit(EXIT_FAILURE);
	}
	return arr[n];
}