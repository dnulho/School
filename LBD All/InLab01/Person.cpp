#include "Person.h"

Person::Person()
	:m_age(-1), m_name()
{
	cout << "Person Default CTOR" << endl;
}

Person::~Person()
{
	cout << "Person DTOR" << endl;
}

Person::Person(MyString name, int age)
	:m_name(name), m_age(age)
{
	if (age == -1)
	{
		cout << "Person 1 Arg CTOR " << endl;
		m_name.Display();
	}
	else
	{
		cout << "Person 2 Arg CTOR" << endl;
		m_name.Display();
	}
}

Person::Person(const Person & copy)
	:m_age(copy.m_age), m_name()
{
	cout << "Person Copy CTOR" << endl;
	m_name = copy.m_name;
	m_name.Display();
}

Person & Person::operator=(const Person & rhs)
{
	cout << "Person OP=" << endl;

	if (this != &rhs)
	{
		m_age = rhs.m_age;
		m_name = rhs.m_name;
		m_name.Display();
	}
	return *this;
}
