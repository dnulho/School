#pragma once

#include "MyString.h"
class Person
{
public:
	Person();
	~Person();
	Person(MyString name, int age = -1);
	Person(const Person & copy);
	Person & operator =(const Person & rhs);

private:
	MyString m_name;
	int m_age;
};

