#pragma once
#include <fstream>
using std::string;

class Date
{
public:
	Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year) {};
	Date() :m_day(0), m_month(0), m_year(0) {};
	~Date()	{};

	int GetDay()		{ return static_cast<int>(m_day); };
	int GetMonth()		{ return static_cast<int>(m_month); };
	int GetYear()		{ return static_cast<int>(m_year); };

	void SetDay(int day)		{ if (day <= 31) m_day = day; };
	void SetMonth(int month)	{ if (month <= 12) m_month = month; };
	void SetYear(int year)		{ m_year = year; };

private:
	char m_day;
	char m_month;
	short int m_year;
};

class Person
{
public:
	Person(string fname, string lname, int phone, Date date);
	Person();
	~Person();
	
	string Getfname();
	string Getlname();
	int GetPhone();
	Date GetBDay();

	void Setfname(string name);
	void Setlname(string name);
	void SetPhone(int number);
	void SetBDay(Date bday);

private:
	string m_fname;
	string m_lname;
	int m_phone;
	Date m_birth;
};