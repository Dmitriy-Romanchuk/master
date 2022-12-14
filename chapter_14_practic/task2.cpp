// A queue is a data - storage device.It’s like a stack, except that, instead of being last - infirst - out, it’s first - in - first - out, 
// like the line at a bank teller’s window.If you put in 1, 2, 3, you get back 1, 2, 3 in that order.
// A stack needs only one index to an array(top in the STAKARAY program in Chapter 7).A
// queue, on the other hand, must keep track of two indexes to an array: one to the tail,
// where new items are added, and one to the head, where old items are removed.The tail
// follows the head through the array as items are addedand removed.If either the tail or
// the head reaches the end of the array, it is reset to the beginning.
// Write a class template for a queue class.Assume that the programmer using the queue
// won’t make any mistakes, like exceeding the capacity of the queue or trying to remove
// an item when the queue is empty.Define several queues of different data types and insert
// and remove data from them.

#include <iostream>

template <class atype>
class queue
{
private:
	atype que[10]{};
	int head;
	int tail;
public:
	queue() : head(0), tail(-1)
	{}
	void put(atype var)
	{
		if (tail == 10 - 1)
		{
			tail = -1;
		}
		que[++tail] = var;
	}
	atype get()
	{
		atype temp = que[head++];
		if (head == 10)
		{
			head = 0;
		}
		return temp;
	}
};

int main()
{
	std::cout << "int" << std::endl;
	//-----------------------------------------
	queue<int> q1;	// type int
	q1.put(11);
	q1.put(22);
	std::cout << "1: " << q1.get() << std::endl;
	std::cout << "2: " << q1.get() << std::endl;
	q1.put(33);
	q1.put(44);
	q1.put(55);
	q1.put(66);
	std::cout << "3: " << q1.get() << std::endl;
	std::cout << "4: " << q1.get() << std::endl;
	std::cout << "5: " << q1.get() << std::endl;
	std::cout << "6: " << q1.get() << std::endl;

	std::cout << "float" << std::endl;
	//-----------------------------------------
	queue<float> q2;	// type float
	q2.put(11.1);
	q2.put(22.2);
	std::cout << "1: " << q2.get() << std::endl;
	std::cout << "2: " << q2.get() << std::endl;
	q2.put(33.3);
	q2.put(44.4);
	q2.put(55.5);
	q2.put(66.6);
	std::cout << "3: " << q2.get() << std::endl;
	std::cout << "4: " << q2.get() << std::endl;
	std::cout << "5: " << q2.get() << std::endl;
	std::cout << "6: " << q2.get() << std::endl;

	return EXIT_SUCCESS;
}