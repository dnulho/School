#include "Card.h"

#ifndef HAND_H
#define HAND_H

class Hand
{
public:
	Hand();
	~Hand();

	void addCard(Card * addition);
	void exchangeCard(Card * newCard, __int8 cardToReplace );
	void discardCard(__int8 cardToDiscard);
	
private:
	__int8 m_numCards;
	Card ** m_currentCards;
};

#endif // !HAND_H