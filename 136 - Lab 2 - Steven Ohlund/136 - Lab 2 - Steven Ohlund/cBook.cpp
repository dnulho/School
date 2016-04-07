/* Author: Steven Ohlund
* Filename: cBook.cpp
* Created: 4.5.16
*/

#include "cBook.h"

// Ctors and Dtors
cBook::cBook(string ISBN, string Author, cDate PubDate,
		uint16_t Price, uint16_t Quantity)
	:m_ISBN(ISBN), m_Author(Author), m_PubDate(PubDate), m_Price(Price),
		m_Quantity(Quantity), m_next(nullptr), m_previous(nullptr)
{
}

cBook::~cBook()
{
}

// Modification Functions
// Change the price to the new price
void cBook::ChangePrice(uint16_t price)
{
	m_Price = price;
}

// Add quantity to the object's quantity
void cBook::Add_Q(uint16_t quantity)
{
	m_Quantity += quantity;
}

// Remove quantity from the object's quantity
void cBook::Remove_Q(uint16_t quantity)
{
	if (m_Quantity >= quantity)
		m_Quantity -= quantity;
	else
		cout << "Error: Not enough books inventory";
}

// Direct Display Functions
//Display the ISBN
void cBook::DisplayISBN() const
{
	cout << m_ISBN;
}

// Displat the Author
void cBook::DisplayAuthor() const
{
	cout << m_Author;
}

// Display the Publication Date in a long format
void cBook::DisplayPubDateL() const
{
	m_PubDate.DisplayLongDate();
}

//Display the Publication Date in a short format
void cBook::DisplayPubDateS() const
{
	m_PubDate.DisplayShortDate();
}

// Display the Price
void cBook::DisplayPrice() const
{
	DisplayDollars(m_Price);
}

// Display the Quantity
void cBook::DisplayQuantity() const
{
	cout << m_Quantity;
}

// Display all of the data contained in an object
void cBook::DisplayAll() const
{
	cout << "ISBN: " << m_ISBN << " Author: " << m_Author << " Publish Date: ";
	m_PubDate.DisplayLongDate();
	cout << "\nCurrent Price: "; DisplayPrice(); 
	cout << "Current Quantity: " << m_Quantity << std::endl;
}

//display an int as in dollars
void DisplayDollars(int Cents)
{
	int dollars = Cents / 100;
	int penny = Cents % 100;
	cout << "$" << dollars << "." ;
	if (penny)		// no change
		cout << "00";
	else			// yes change
		cout << penny;
}