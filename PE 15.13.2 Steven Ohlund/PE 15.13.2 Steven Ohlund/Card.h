#include "Enums.h"
#ifndef CARD_H
#define CARD_H

class Card
{
public:
	Card(Suit suit, Card_Val value);
	~Card();
	int CardValue();
	void DisplayCard() const;
	Suit GetSuit();
	void Deal();
	void Return();
	bool IsDealt();

private:
	Card();
	bool m_dealt;
	Suit m_suit;
	Card_Val m_val;
};
#endif