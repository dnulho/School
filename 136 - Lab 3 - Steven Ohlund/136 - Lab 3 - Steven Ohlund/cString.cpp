#include "cString.h"

cString::cString(const char * string)
	:m_string(nullptr)
{
	this->m_string = new char[strlen(string) + 1];
	strcpy(this->m_string, string);
}

cString::cString(const cString & copy)
	:m_string(nullptr)
{
	this->m_string = new char[strlen(copy.m_string) + 1];
	strcpy(this->m_string, copy.m_string);
}

cString & cString::operator=(const cString & rhs)
{
	delete[] this->m_string;
	this->m_string = new char[strlen(rhs.m_string) + 1];
	strcpy(this->m_string, rhs.m_string);
	return *this;
}

cString::~cString()
{
	delete[] this->m_string;
	this->m_string = nullptr;
}

ostream & operator<<(ostream & os, const cString & rhs)
{
	os << rhs.m_string;
	return os;
}

istream & operator>>(istream & is, cString & rhs)
{
	is >> rhs.m_string;
	return is;
}

bool cString::operator==(const cString & rhs) const
{
	return !strcmp(this->m_string,rhs.m_string);
}

bool operator==(const char * lhs, const cString & rhs)
{
	return !strcmp(lhs, rhs.m_string);
}

bool cString::operator==(const char* rhs) const
{
	return !strcmp(this->m_string, rhs);
}

bool cString::operator<(const cString & rhs) const
{
	return (_stricmp(this->m_string, rhs.m_string) < 0);
}

bool operator<(const char * lhs, const cString & rhs)
{
	return (_stricmp(lhs, rhs.m_string) < 0);
}

bool cString::operator<(const char * rhs) const
{
	return (_stricmp(this->m_string, rhs) < 0);
}

bool cString::operator>(const cString & rhs) const
{
	return (_stricmp(this->m_string, rhs.m_string) > 0);
}

bool operator>(const char * lhs, const cString & rhs)
{
	return (_stricmp(lhs, rhs.m_string) > 0);
}

bool cString::operator>(const char * rhs) const
{
	return (_stricmp(this->m_string, rhs) > 0);
}
