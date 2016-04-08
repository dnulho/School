#define _CRT_SECURE_NO_WARNINGS

#ifndef CSTRING_H
#define CSTRING_H

#include <iostream>
using std::ostream;
class cString
{
public:
	// Cannonical Functions
	cString(const char* = "");
	cString(const cString& copy);
	cString& operator=(const cString& rhs);
	~cString();

	// Display functions
	friend ostream& operator<<(ostream& os,cString& rhs);



private:

	char * m_string;
};
#endif // !CSTRING_H