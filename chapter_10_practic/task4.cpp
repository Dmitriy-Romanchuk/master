// Add a destructor to the LINKLIST program.It should delete all the links when a linklist
// object is destroyed.It can do this by following along the chain, deleting each link as it
// goes.You can test the destructor by having it display a message each time it deletes a
// link; it should delete the same number of links that were added to the list. (A destructor
// is called automatically by the system for any existing objects when the program exits.)


#include <iostream>

struct link  
{
	int data;  
	link* next;
};

class linklist            
{
private:
	link* first;          
public:
	linklist()
	{
		first = NULL;
	}
	~linklist();          
	void additem(int d);  
	void display();       
};

void linklist::additem(int d) 
{
	link* newlink = new link; 
	newlink->data = d;        
	newlink->next = first;    
	first = newlink;          
}

void linklist::display() 
{
	link* current = first;             
	while (current)                     
	{                                   
		std::cout << current->data << std::endl; 
		current = current->next;
	}
}

linklist::~linklist()
{
	link* current = first;
	while (current)
	{
		first = current->next;
		delete current;
		std::cout << "Element deleted" << std::endl;
		current = first;
	}
}

int main()
{
	linklist li;

	li.additem(25);
	li.additem(36);
	li.additem(49);
	li.additem(64);

	li.display();   

	return EXIT_SUCCESS;
}