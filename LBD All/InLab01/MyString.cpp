#include "MyString.h"
#include <iostream>
using std::cout;
using std::endl;

MyString::MyString()
	:m_string(nullptr)
{
	cout << "MyString Default CTOR" << endl;
}

MyString::MyString(char * string)
	:m_string(nullptr)
{
	m_string = new char[strlen(string) + 1];
	strcpy(m_string, string);
	cout << "MyString 1 Arg CTOR" << endl;
}

MyString::~MyString()
{
	cout << "MyString DTOR" << endl;
	delete[] m_string;
	m_string = nullptr;
}

MyString::MyString(const MyString & copy)
	:m_string(nullptr)
{
	cout << "MyString Copy CTOR" << endl;
	m_string = new char[strlen(copy.m_string) + 1];
	strcpy(m_string, copy.m_string);
}

MyString & MyString::operator=(const MyString & rhs)
{
	cout << "MyString OP=" << endl;
	if (this != &rhs)
	{
		delete[] m_string;
		m_string = new char[strlen(rhs.m_string) + 1];
		strcpy(m_string, rhs.m_string);
	}
	return *this;
}

void MyString::Display()
{
	cout << m_string << endl;
}
