// Start with the person class, and create a multiset to hold pointers to person objects.
// Define the multiset with the comparePersons function object, so it will be sorted automatically by names of persons.
// Define a half - dozen persons, put them in the multiset, and display its contents.
// Several of the persons should have the same name, to verify that
// the multiset stores multiple objects with the same key

#include<iostream>
#include<string>
#include<set>
#include<iomanip>

class person
{
private:
	std::string lastName;
	std::string firstName;
	long phoneNumber;
public:
	person() : lastName("empty"), firstName("empty"), phoneNumber(0)
	{ }
	person(std::string lana, std::string fina, long pho) :
		lastName(lana), firstName(fina), phoneNumber(pho)
	{ }
	friend bool operator<(const person&, const person&);
	friend bool operator==(const person&, const person&);
	void display() const
	{
		std::cout << std::setiosflags(std::ios::left) << std::setw(10) << lastName << " " << std::setw(10) << firstName << "Phone: " << std::setw(15) << phoneNumber << std::endl;
	}
};

class comparePerson
{
public:
	bool operator()(const person* ptrP1, const person* ptrP2) const
	{
		return(*ptrP1 < *ptrP2);
	}
};

int main()
{
	person* ptrP1 = new person("Romanchuk", "Dmitriy", 8708491);
	person* ptrP2 = new person("Romanchuk", "Nadezhda", 1589632);
	person* ptrP3 = new person("Romanchuk", "Ivan", 2583532);
	person* ptrP4 = new person("Sukhovilo", "Ilia", 5895587);
	person* ptrP5 = new person("Akinfeev", "Ilia", 2534567);

	std::multiset<person*, comparePerson> mySet;
	std::multiset<person*, comparePerson>::iterator iter;

	mySet.insert(ptrP1);
	mySet.insert(ptrP2);
	mySet.insert(ptrP3);
	mySet.insert(ptrP4);
	mySet.insert(ptrP5);

	for (iter = mySet.begin(); iter != mySet.end(); ++iter)
	{
		(**iter).display();
	}

	return EXIT_SUCCESS;
}

bool operator<(const person& p1, const person& p2)
{
	if (p1.lastName == p2.lastName)
		return (p1.firstName < p2.firstName) ? true : false;
	return (p1.lastName < p2.lastName) ? true : false;
}

bool operator==(const person& p1, const person& p2)
{
	return (p1.lastName == p2.lastName &&
		p1.firstName == p2.firstName) ? true : false;
}
