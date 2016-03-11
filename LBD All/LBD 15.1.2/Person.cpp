#include "Person.h"

Person::Person(int ID, char gender)
	: m_id(ID), m_gender(gender)
{
}

Person::Person()
	: m_id(0), m_gender('\0')
{
}



Person::~Person()
{
}

void Person::SetGender(char gender)
{
	m_gender = gender;
}

void Person::SetID(int ID)
{
	m_id = ID;
}

int Person::GetID()
{
	return m_id;
}

char Person::GetGender()
{
	return m_gender;
}