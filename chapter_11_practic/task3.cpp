// As we saw earlier, it’s possible to make a class that acts like an array.The CLARRAY
// example shown here is a complete program that shows one way to create your own array
// class :
// The output of this program is
// 0 1 4 9 16 25 36 49 64 81
// Starting with CLARRAY, add an overloaded assignment operator and an overloaded copy
// constructor to the Array class.Then add statements such as
// Array arr2(arr1);
// and
// arr3 = arr1;
// to the main() program to test whether these overloaded operators work.The copy constructor should create an entirely new Array object with its own memory for storing
// array elements.Both the copy constructorand the assignment operator should copy the
// contents of the old Array object to the new one.What happens if you assign an Array of
// one size to an Array of a different size ?

#include <iostream>

class Array
{
	int* ptr;
	int size;
public:
	Array() : ptr(0), size(0)
	{ }
	Array(int s)
	{
		size = s;
		ptr = new int[s];
	}
	Array(const Array& arr)
	{
		size = arr.size;
		ptr = new int[size];
		for (int i = 0; i < size; ++i)
			*(ptr + i) = *(arr.ptr + i);
	}
	~Array()
	{
		delete[] ptr;
	}
	int& operator[] (int j)
	{
		return *(ptr + j);
	}
	Array& operator= (const Array& arr)
	{
		if (this == &arr) 
			return *this;

		delete[] ptr;
								  
		size = arr.size;
		ptr = new int[size];
		for (int i = 0; i < size; ++i)
			*(ptr + i) = *(arr.ptr + i);
		return *this;
	}
	void display()
	{
		for (int i = 0; i < size; ++i)
			std::cout << *(ptr + i) << ' ';
	}
};

int main()
{
	const int ASIZE = 10;
	Array arr1(ASIZE);

	for (int j = 0; j < ASIZE; ++j)
		arr1[j] = j * j;

	std::cout << "arr1 = "; arr1.display(); std::cout << std::endl;

	Array arr2(arr1);
	std::cout << "arr2 = "; 
	arr2.display(); 
	std::cout << std::endl;

	Array arr3(10);
	Array arr4(5);
	Array arr5(15);
	arr3 = arr1;
	arr4 = arr1;
	arr5 = arr1;

	std::cout << "arr3 = "; 
	arr3.display(); 
	std::cout << std::endl;

	std::cout << "arr4 = ";
	arr4.display();
	std::cout << std::endl;

	std::cout << "arr5 = ";
	arr5.display(); 
	std::cout << std::endl;

	arr1 = arr1;
	std::cout << "arr1 = "; 
	arr1.display(); 
	std::cout << std::endl;

	Array arr6;
	Array arr7;
	arr7 = arr6 = arr1;

	std::cout << "arr6 = "; 
	arr6.display(); 
	std::cout << std::endl;

	std::cout << "arr7 = "; 
	arr7.display(); 
	std::cout << std::endl;

	return EXIT_SUCCESS;
}
