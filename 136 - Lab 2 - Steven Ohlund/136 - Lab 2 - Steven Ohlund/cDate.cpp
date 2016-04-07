/* Author: Steven Ohlund
* Filename: cDate.cpp
* Created: 4.5.16
*/

#include "cDate.h"

// Overloaded op<< so I can output a cDate object to a stream easier,
// and increase readability
ostream& operator<<(ostream& os, const cDate& obj)
{
	os << static_cast<int>(obj.m_day) << "." << static_cast<int>(obj.m_month)
		<< "." << static_cast<int>(obj.m_year);
	return os;
}

// ctor with basic error checking.
cDate::cDate(uint8_t day, uint8_t month, uint16_t year)
	:m_day(day), m_month(month), m_year(year), m_valid(0)
{
	CheckValidity();
}

// Default dtor because no dynamic memory
cDate::~cDate()
{
}

// Display date in long format
void cDate::DisplayLongDate() const
{
	if (m_valid)
		std::cout << static_cast<int>(m_day) << " " << m_monthNames[m_month - 1]
		<< ", " << static_cast<int>(m_year);
	else
		std::cout << "Invalid Date";
}

// Display date in short format
void cDate::DisplayShortDate() const
{
	if (m_valid)
		std::cout << static_cast<int>(m_month) << "/" << static_cast<int>(m_day)
		<< "/" << static_cast<int>(m_year);
	else
		std::cout << "Invalid Date";
}

// m_day setter w/ error checking
void cDate::SetDay(uint8_t day)
{
	if (day <= 31 && day != 0)
	{
		m_day = day;
		CheckValidity();
	}
}

//m_month setter w/ error checking
void cDate::SetMonth(uint8_t month)
{
	if (month <= 12 && month != 0)
	{
		m_month = month;
		CheckValidity();
	}
}

// m_year setter (no value is invalid so no error checking)
void cDate::SetYear(uint16_t year)
{
		m_year = year;
}

// Error Checker Function
void cDate::CheckValidity() 
{
	if (m_day == 0 || m_month == 0 || m_month > 12)
	{
		std::cout << "Error: Invalid Date" << std::endl;
		m_valid = 0;
	}
	else
		m_valid = 1;
}

// array for DisplayLongDate() function
const char* cDate::m_monthNames[12] = { "January", "Febuary", "March", "April",
"May", "June", "July", "Augest", "September", "October", "November", "December" };