// Add exceptions to the queue template in Exercise 2. Throw two exceptions : one if the
// capacity of the queue is exceeded, the other if the program tries to remove an item from
// an empty queue.One way to handle this is to add a new data member to the queue : a
// count of the number of items currently in the queue.Increment the count when you
// insert an item, and decrement it when you remove an item.Throw an exception if this
// count exceeds the capacity of the queue, or if it becomes less than 0.
// You might try making the main() part of this exercise interactive, 
// so the user can put values on a queueand take them off.This makes it easier to exercise the queue.Following
// an exception, the program should allow the user to recover from a mistake without corrupting the contents of the queue.

#include <iostream>

template <class atype>
class queue
{
private:
	const static int MAX = 3;
	atype que[MAX]{};
	int head;
	int tail;
	int counter;
public:
	class que_ex
	{};
	queue() : head(0), tail(-1), counter(0)
	{}
	void put(atype var)
	{
		if (tail == MAX - 1)
		{
			tail = -1;
		}
		que[++tail] = var;
		++counter;
		if (counter > MAX)
			throw que_ex();
	}
	atype get()
	{
		atype temp = que[head++];
		if (head == MAX)
		{
			head = 0;
		}
		--counter;
		if (counter < 0)
			throw que_ex();
		return temp;
	}
};

int main()
{
	try 
	{
		std::cout << "int" << std::endl;
		//-----------------------------------------
		queue<int> q1;
		q1.put(11);
		q1.put(22);
		q1.put(33);
		q1.put(44);
		
		// std::cout << "1: " << q1.get() << std::endl;
		// std::cout << "2: " << q1.get() << std::endl;
		// std::cout << "3: " << q1.get() << std::endl;
		// std::cout << "4: " << q1.get() << std::endl;

	}
	catch (queue<int>::que_ex)
	{
		std::cout << "Error! Array is full or empty!" << std::endl;
	}
	return EXIT_SUCCESS;
}