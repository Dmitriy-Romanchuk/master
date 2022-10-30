// Derive a class called employee2 from the employee class in the EMPLOY program in this
// chapter.This new class should add a type double data item called compensation, and
// also an enum type called period to indicate whether the employee is paid hourly, weekly,
// or monthly.For simplicity you can change the manager, scientist, and laborer classes
// so they are derived from employee2 instead of employee.However, note that in many
// circumstances it might be more in the spirit of OOP to create a separate base class called
// compensationand three new classes manager2, scientist2, and laborer2, and use
// multiple inheritance to derive these three classes from the original manager, scientist,
// and laborer classesand from compensation.This way none of the original classes
// needs to be modified.

#include <iostream>

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

class emploee2 : public emploee
{
protected:
	double compensation{};
	enum class period { hourly, weekly, monthly };
	period p1{};
public:
	void getData()
	{
		char ch = ' ';
		std::cout << "Compensation: ";
		std::cin >> compensation;
		std::cout << "period {hourly, weekly, monthly} only first letter: ";
		std::cin >> ch;
		switch (ch)
		{
		case 'h':
			p1 = period::hourly;
			break;
		case 'w':
			p1 = period::weekly;
			break;
		case 'm':
			p1 = period::monthly;
			break;
		default:
			break;
		}
	}
	void putData() const
	{
		std::cout << "Compensation: " << compensation << std::endl;
		std::cout << "Period: ";
		switch (p1)
		{
		case period::hourly:
			std::cout << "hourly" << std::endl;
			break;
		case period::weekly:
			std::cout << "weekly" << std::endl;
			break;
		case period::monthly:
			std::cout << "monthly" << std::endl;
			break;
		default:
			break;
		}
	}
};

class manager : public emploee
{
protected:
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

class scientist : public emploee
{
protected:
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

class manager2 : public manager, public emploee2
{
public:
	void getData()
	{
		manager::getData();
		emploee2::getData();
	}
	void putData() const
	{
		manager::putData();
		emploee2::putData();
	}
};
class scientist2 : public scientist, public emploee2
{
public:
	void getData()
	{
		scientist::getData();
		emploee2::getData();
	}
	void putData() const
	{
		scientist::putData();
		emploee2::putData();
	}
};
class laborer2 : public laborer, public emploee2
{
public:
	void getData()
	{
		laborer::getData();
		emploee2::getData();
	}
	void putData() const
	{
		laborer::putData();
		emploee2::putData();
	}
};

int main()
{
	manager2 m1;
	scientist2 s1;
	laborer2 l1;
	
	m1.getData();
	s1.getData();
	l1.getData();
	m1.putData();
	s1.putData();
	l1.putData();
}