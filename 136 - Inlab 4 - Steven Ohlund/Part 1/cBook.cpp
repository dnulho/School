#include "cBook.h"

cBook::cBook(std::string title, uint16_t id, bool checkedIn)
	:m_title(title), m_id(id), m_checkedIn(checkedIn)
{
	cout << "Book CTOR: ";
	Display();
}

cBook::cBook(const cBook & copy)
	: m_title(copy.m_title), m_id(copy.m_id), m_checkedIn(copy.m_checkedIn)
{
	cout << "Book Copy CTOR: ";
	Display();
}

cBook& cBook::operator=(const cBook & rhs)
{
	this->m_title = rhs.m_title;
	this->m_id = rhs.m_id;
	this->m_checkedIn = rhs.m_checkedIn;
	cout << "Book Op=: ";
	Display();
	return *this;
}

cBook::~cBook()
{
	cout << "Book DTOR: ";
	Display();
}

void cBook::Display() const
{
	cout << m_title << ", " << m_id << ", " << (m_checkedIn ? "In" : "Out") << endl;
}

int cBook::totalBooks = 0;