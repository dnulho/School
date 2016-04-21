// File mystring.h - used for inlab #4 and lab 4
// Is this an example of a UDC????  Meet the criteria?
// Some startup code
// NOTE:  If desired, you can find some examples of a search method 
//        in our text or your reference books

#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstring> // new header (rather than string.h)
using namespace std;


class String
{
private:
	char* ptr;
public:
	inline String(const char* = "");
	inline String(char);
	inline String(const String&); // Copy constructor
	inline ~String();
	inline String& operator=(String& rhs);
};

inline String::String(const char* p)
	:ptr(nullptr)
{
	cout << "String CTOR long string\n";
	p = p ? p : "";	// What is this doing???
	ptr = new char[strlen(p) + 1];
	strcpy(ptr, p);
}

inline String::String(char ch)
	:ptr(nullptr)
{
	cout << "String CTOR single char\n";
	ptr = new char[2];
	ptr[0] = ch;
	ptr[1] = '\0';
}

inline String::String(const String& obj) // Copy constructor - OK - MAYBE JUST A BAD START FOR YOU TO CLEAN-UP
	:ptr(nullptr)
{
	cout << "String copy CTOR\n";
	this->ptr = new char[strlen(obj.ptr) + 1];
	strcpy(this->ptr, obj.ptr);
}

inline String::~String()
{ 
	cout << "String DTOR\n";
	delete[] this->ptr;
	this->ptr = nullptr;
}

inline String & String::operator=(String & rhs)
{
	cout << "String op=\n";
	delete[] this->ptr;
	this->ptr = new char[strlen(rhs.ptr) + 1];
	strcpy(this->ptr, rhs.ptr);
	return *this;
}

#endif