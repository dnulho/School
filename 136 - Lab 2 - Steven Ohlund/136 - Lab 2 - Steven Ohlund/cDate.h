/* Author: Steven Ohlund
 * Filename: cDate.h
 * Created: 4.5.16
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>
using std::ostream;
#include <string>
using std::string;

class cDate
{
public:	
	friend ostream& operator<<(ostream& os, const cDate& obj);
	
	// -tors	
	cDate(uint8_t day = 0, uint8_t month = 0, uint16_t year = 0);
	~cDate();

	// Displayers
	void DisplayLongDate() const;
	void DisplayShortDate() const;

	// Getters
	uint8_t GetDay() { return m_day; };
	uint8_t GetMonth() { return m_month; };
	uint16_t GetYear() { return m_year; };

	//Setters
	void SetDay(uint8_t);
	void SetMonth(uint8_t);
	void SetYear(uint16_t);

private:
	void CheckValidity();

	uint8_t m_day : 5;
	uint8_t m_month : 4;
	uint16_t m_year : 14;
	uint8_t m_valid : 1; // 1 is valid date, 0 is invalid date

	static const char* m_monthNames[12];
};

ostream& operator<<(ostream& os, const cDate& obj);
#endif // !DATE_H
