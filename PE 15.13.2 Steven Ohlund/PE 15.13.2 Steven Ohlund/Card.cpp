#include "Card.h"
#include <iostream>
using std::cout;
using std::endl;

////// Public //////
Card::Card(Suit suit, Card_Val value)
	:m_suit(suit), m_val(value), m_dealt(false)
{
	cout << "Building " << CARD_VAL[m_val] << SUIT[m_suit] << endl;
}

Card::~Card()
{
	cout << "Deleting " << CARD_VAL[m_val] << SUIT[m_suit] << endl;
}

int Card::CardValue()
{
	int value = static_cast<int>(m_val + 1) + static_cast<int>(m_suit * 13);
	return value;
}

void Card::DisplayCard() const
{
	if (this)
		cout << CARD_VAL[m_val] << SUIT[m_suit] << endl;
	else
		cout << "Error: Null Card" << endl;
}

Suit Card::GetSuit()
{
	return m_suit;
}

void Card::Deal()
{
	if (this)
		m_dealt = true;
}

void Card::Return()
{
	if (this)
		m_dealt = false;
}

bool Card::IsDealt()
{
	bool rVal = false;
	if (this)
		rVal = m_dealt;
	return rVal;
}

////// Private //////
Card::Card()
{
	cout << "Error: Undefined Card Built\n";
}