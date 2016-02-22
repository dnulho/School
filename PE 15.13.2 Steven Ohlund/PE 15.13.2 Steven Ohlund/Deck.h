#include "Card.h"
#ifndef DECK_H
#define DECK_H

class Deck
{
public:
	Deck();
	~Deck();
private:
	char m_numCards;
	Card** m_fullDeck;
};
#endif

