#ifndef BOOK_H
#define BOOK_H

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class cBook
{
public:
	cBook(string title = "UNKNOWN", uint16_t id = 0, bool checkedIn = true);
	cBook(const cBook& copy);
	cBook& operator=(const cBook& rhs);
	~cBook();

	void Display() const;

	const string& GetTitle() const { return m_title; };
	int GetID() const { return m_id; };
	bool GetStatus() const { return m_checkedIn; };

	void SetStatus(bool status) { m_checkedIn = status; };
	void ChangeID(uint16_t id) { m_id = id; };

private:
	string m_title;
	uint16_t m_id;
	bool m_checkedIn;

	static int totalBooks;
};

#endif