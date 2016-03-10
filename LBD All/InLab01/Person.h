#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
using std::cout;
using std::endl;
#include "MyString.h"

class Person
{
public:
	Person();
	Person(MyString name, int age = -1);
	~Person();
	Person(const Person & copy);
	Person & operator =(const Person & rhs);

private:
	MyString m_name;
	int m_age;
};

#endif
