#define _CRT_SECURE_NO_WARNINGS

#ifndef CSTRING_H
#define CSTRING_H

#include <iostream>
using std::ostream;
using std::istream;
class cString
{
public:
	// Cannonical Functions
	cString(const char* = "");
	cString(const cString& copy);
	cString& operator=(const cString& rhs);
	~cString();

	// I/O functions
	friend ostream& operator<<(ostream& os, const cString& rhs);
	friend istream& operator>>(istream& is, cString& rhs);

	// Logic Functions
	friend bool operator==(const cString& lhs, const cString& rhs);
	friend bool operator==(const char * lhs, const cString & rhs);
	friend bool operator==(const cString & lhs, const char* rhs);

	friend bool operator< (const cString& lhs, const cString& rhs);
	friend bool operator< (const char* lhs, const cString& rhs);
	friend bool operator< (const cString& lhs, const char* rhs);

	friend bool operator> (const cString& lhs, const cString& rhs);
	friend bool operator> (const char* lhs, const cString& rhs);
	friend bool operator> (const cString& lhs, const char* rhs);
private:

	char * m_string;
};
#endif // !CSTRING_H