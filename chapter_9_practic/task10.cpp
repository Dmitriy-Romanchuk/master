// There is only one kind of manager in the EMPMULT program in this chapter.Any serious
// company has executives as well as managers.From the manager class derive a class
// called executive. (We’ll assume an executive is a high - end kind of manager.) The additional data in the executive class will be the size of the employee’s yearly bonusand the
// number of shares of company stock held in his or her stock - option plan.Add the appropriate
// member functions so these data items can be input and displayed along with the other
// manager data.

#include <iostream>

class student
{
private:
	static const int len = 80;
	char school[len]{};
	char degree[len]{};
public:
	void getedu()
	{
		std::cout << "Enter name of school: ";
		std::cin >> school;
		std::cout << "Enter higher education degree: ";
		std::cin >> degree;
	}
	void putedu() const
	{
		std::cout << "School: " << school << std::endl;
		std::cout << "Higher education degree: " << degree << std::endl;
	}
};

class emploee
{
protected:
	static const int len = 80;
	char name[len]{};
	unsigned long number = 0;
public:
	void getData()
	{
		std::cout << "Enter name: ";
		std::cin >> name;
		std::cout << "Enter number of emploee: ";
		std::cin >> number;
	}
	void putData() const
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Number: " << number << std::endl;
	}
};

class manager : private emploee, private student
{
private:
	static const int len = 80;
	char title[len]{};
	double dues{};
public:
	void getData()
	{
		emploee::getData();
		std::cout << "Enter job title: ";
		std::cin >> title;
		std::cout << "Enter the amount of contributions to the golf club : ";
		std::cin >> dues;
	}
	void putData() const
	{
		emploee::putData();
		std::cout << "job title: " << title << std::endl;
		std::cout << "Amount of contributions: " << dues << std::endl;
	}
};

class scientist : public emploee, private student
{
private:
	int pubs{};
public:
	void getData()
	{
		emploee::getData();
		std::cout << "Enter count of publication: ";
		std::cin >> pubs;
	}
	void putData() const
	{
		emploee::putData();
		std::cout << "Count of publication: " << pubs << std::endl;
	}
};

class laborer : public emploee
{
public:
	void getData()
	{
		emploee::getData();
	}
	void putData() const
	{
		emploee::putData();
	}
};

class executive : public manager
{
private:
	float bonus = 0;
	int number_of_shares = 0;
public:
	void getData()
	{
		manager::getData();
		std::cout << "Enter number of shares: ";
		std::cin >> number_of_shares;
		std::cout << "Enter bonus: ";
		std::cin >> bonus;
	}
	void putData() const
	{
		manager::putData();
		std::cout << "Number of shares: " << number_of_shares << "%" << std::endl;
		std::cout << "Bonus: " << bonus << "$" << std::endl;
	}
};

int main()
{
	manager m1;
	scientist s1;
	laborer l1;
	executive e1;

	m1.getData();
	s1.getData();
	l1.getData();
	e1.getData();
	m1.putData();
	s1.putData();
	l1.putData();
	e1.putData();
}