// Start with the COUNTEN2 program in this chapter.It can increment or decrement a
// counter, but only using prefix notation.Using inheritance, add the ability to use postfix
// notation for both incrementingand decrementing. (See Chapter 8 for a description of
// postfix notation.)

#include <iostream>

class counter
{
protected:
	unsigned int count;
public:
	counter() : count(0)
	{}
	counter(int c) : count(c)
	{}
	unsigned int get_count() const
	{
		return count;
	}
	counter operator++()
	{
		return counter(++count);
	}
	counter operator--()
	{
		return counter(--count);
	}
};

class counter_postfix : public counter
{
public:
	counter_postfix() : counter(0)
	{}
	counter_postfix(int c) : counter(c)
	{}
	counter::operator++;
	counter::operator--;
	counter_postfix operator++(int)
	{
		return counter_postfix(count++);
	}
	counter_postfix operator--(int)
	{
		return counter_postfix(count--);
	}
};

int main()
{
	counter_postfix c1;
	std::cout << c1.get_count() << std::endl;
	std::cout << c1++.get_count() << std::endl;
	std::cout << c1--.get_count() << std::endl;
	std::cout << c1.get_count() << std::endl;
	++c1;
	std::cout << c1.get_count() << std::endl;
	--c1;
	std::cout << c1.get_count() << std::endl;

	return EXIT_SUCCESS;
}