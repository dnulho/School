#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "MyString.h"
#include "Person.h"

void StrValFunct(MyString value);
void StrRefFunct(MyString & ref);
void StrPntFunct(MyString * ptr);
void StrConstRefFnt(const MyString & const_ref);

Person PerLocalInst();
void PerValFunct(Person value);
void PerRefFunct(Person & ref);
void PerConstRefFnt(const Person & const_ref);

int main()
{
	MyString str1;
	cout << endl;
	MyString str2("hello world");
	cout << endl;
	Person per1;
	cout << endl;
	Person per2("Steven", 21);

	cout << endl;
	StrValFunct(str2);
	cout << endl;
	StrRefFunct(str1);
	cout << endl;
	StrPntFunct(&str2);
	cout << endl;
	StrConstRefFnt(str1);
	cout << endl;

	per1 = PerLocalInst();
	cout << endl;
	PerValFunct(per2);
	cout << endl;
	PerRefFunct(per1);
	cout << endl;
	PerConstRefFnt(per2);
	cout << endl;
	return 0;
}

void StrValFunct(MyString value)
{
	cout << "String Value Function" << endl;
}

void StrRefFunct(MyString & ref)
{
	cout << "String Reference Function" << endl;
	ref = "Referenced";
}

void StrPntFunct(MyString * ptr)
{
	cout << "String Pointer Function" << endl;
	ptr->Display();
}

void StrConstRefFnt(const MyString & const_ref)
{
	cout << "String Const-Ref Function" << endl;
}

Person PerLocalInst()
{
	cout << "Person Local Instance Function" << endl;
	Person local("Oliver");
	return local;
}

void PerValFunct(Person value)
{
	cout << "Person Value Function" << endl;

}

void PerRefFunct(Person & ref)
{
	cout << "Person Reference Function" << endl;

}

void PerConstRefFnt(const Person & const_ref)
{
	cout << "Person Const-Ref Function" << endl;

}