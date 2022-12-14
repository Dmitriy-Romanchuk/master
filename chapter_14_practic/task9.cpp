// Modify the exception class in Exercise 8 (adapted from ARROVER3) so that the 
// error message in the catch block reports the value of the index that caused the exception

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
	{
	public:
		int index;
		index_exeption(int a) : index(a)
		{}
	};
};

int main()
{
	try
	{
		safearray<int> s1;
		s1.putel(1, 100);
		std::cout << s1.getel(1) << std::endl;

		safearray<double> s2;
		s2.putel(8, 5.5);
		std::cout << s2.getel(1) << std::endl;
	}
	catch (safearray<int>::index_exeption ex )
	{
		std::cout <<  ex.index <<" is error index!";
	}
	catch (safearray<double>::index_exeption ex)
	{
		std::cout << ex.index << " is error index";
	}

	return EXIT_SUCCESS;
}

template<class T>
void safearray<T>::putel(int n, T elvalue)
{
	if (n < 0 || n >= LIMIT)
		throw index_exeption(n);
	arr[n] = elvalue;
}

template<class T>
T safearray<T>::getel(int n) const
{
	if (n < 0 || n >= LIMIT)
		throw index_exeption(n);

	return arr[n];
}