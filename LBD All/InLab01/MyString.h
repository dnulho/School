#pragma once
class MyString
{
public:
	MyString();
	MyString(char * string);
	~MyString();
	MyString(const MyString & copy);
	MyString & operator =(const MyString & rhs);

	void Display();
private:
	char * m_string;
};

