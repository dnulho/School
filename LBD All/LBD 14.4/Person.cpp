#include "Person.h"

Person::Person(string fname, string lname, int phone, Date date)
	: m_fname(fname), m_lname(lname), m_phone(phone), m_birth(date)
{
}

Person::Person()
	: m_fname(""), m_lname(""), m_phone(0), m_birth()
{}

Person::~Person()
{
}

string Person::Getfname()
{
	return m_fname;
}

string Person::Getlname()
{
	return m_lname;
}

int Person::GetPhone()
{
	return m_phone;
}

Date Person::GetBDay()
{
	return m_birth;
}

void Person::Setfname(string name)
{
	m_fname = name;
}

void Person::Setlname(string name)
{
	m_lname = name;
}

void Person::SetPhone(int number)
{
	m_phone = number;
}

void Person::SetBDay(Date bday)
{
	m_birth = bday;
}
