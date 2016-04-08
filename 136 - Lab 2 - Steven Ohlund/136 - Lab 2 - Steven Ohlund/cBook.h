/* Author: Steven Ohlund
* Filename: cBook.h
* Created: 4.5.16
*/

#ifndef BOOK_H
#define BOOK_H

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

#include "cDate.h"

class cBook 
{
	friend class cInventory;

public:
	// Ctors and Dtors
	cBook(string ISBN = "0-000-00000-0", string Author = "Unknown", 
		cDate PubDate = { 0,0,0 }, uint16_t Price = 0, uint16_t Quantity = 0);
	~cBook();

	// Modification Functions
	void ChangePrice(uint16_t price);
	void Add_Q(uint16_t quantity);
	void Remove_Q(uint16_t quantity);

	// Direct Display Functions
	void DisplayISBN() const;
	void DisplayAuthor() const;
	void DisplayPubDateL() const;
	void DisplayPubDateS() const;
	void DisplayPrice() const;
	void DisplayQuantity() const;
	void DisplayAll() const;

	// Get Functions
		// Inline to reduce size and function call times
	const string& Get_ISBN() const { return m_ISBN; };
	const string& GetAuthor() const { return m_Author; };
	const cDate& GetPubDate() const { return m_PubDate; };
	const uint16_t GetPrice() const { return m_Price; };
	const int16_t Get_Q() const { return m_Quantity; };

private:
	string m_ISBN;
	string m_Author;
	cDate m_PubDate;
	uint16_t m_Price;
	uint16_t m_Quantity;

	cBook * m_next;
	cBook * m_previous;
};

void DisplayDollars(int Cents);
#endif // !BOOK_H
