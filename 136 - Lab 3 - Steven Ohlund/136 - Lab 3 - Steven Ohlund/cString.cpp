#include "cString.h"

cString::cString(const char * string)
	:m_string(nullptr)
{
	this->m_string = new char[(sizeof(string) + 1) * sizeof(char)];
	strcpy(this->m_string, string);
}

cString::cString(const cString & copy)
	:m_string(nullptr)
{
	this->m_string = new char[(sizeof(copy.m_string) + 1) * sizeof(char)];
	strcpy(this->m_string, copy.m_string);
}

cString & cString::operator=(const cString & rhs)
{
	delete[] this->m_string;
	this->m_string = new char[(sizeof(rhs.m_string) + 1) * sizeof(char)];
	strcpy(this->m_string, rhs.m_string);
	return *this;
}

cString::~cString()
{
	delete[] this->m_string;
	this->m_string = nullptr;
}

ostream & operator<<(ostream & os, cString & rhs)
{
	os << rhs.m_string;
	return os;
}