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
	bool operator==(const cString& rhs) const;
	friend bool operator==(const char * lhs, const cString & rhs);
	bool operator==(const char* rhs) const;

	bool operator< (const cString& rhs) const;
	friend bool operator< (const char * lhs, const cString& rhs);
	bool operator< (const char* rhs) const;

	bool operator> (const cString& rhs) const;
	friend bool operator> (const char * lhs, const cString& rhs);
	bool operator> (const char* rhs) const;
private:

	char * m_string;
};
#endif // !CSTRING_H