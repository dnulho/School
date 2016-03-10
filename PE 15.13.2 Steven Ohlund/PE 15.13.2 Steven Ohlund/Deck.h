#include "Card.h"
#ifndef DECK_H
#define DECK_H

class Deck
{
public:
	Deck(int numCards = 52);
	~Deck();
	void Shuffle();
	void DisplayDeck();
	Card * Deal();

private:
	char m_topCard;
	char m_numCards;
	Card ** m_fullDeck;
};
#endif

