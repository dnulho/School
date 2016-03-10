#include "Hand.h"

Hand::Hand()
	:m_numCards(0), m_currentCards(nullptr)
{
}

Hand::~Hand() // Deck class cleans up the cards, so don't do it here.
{
	delete[] m_currentCards;
	m_currentCards = nullptr;
}

void Hand::addCard(Card * addition)
{
	Card ** temp = new Card*[m_numCards + 1];
	for (int ii = 0; ii < m_numCards; ii++)
	{
		temp[ii] = m_currentCards[ii];
	}
	temp[m_numCards + 1] = addition;
	m_numCards++;
	delete[] m_currentCards;
	m_currentCards = temp;
}

void Hand::exchangeCard(Card * newCard, __int8 indexToReplace)
{
	m_currentCards[indexToReplace] = newCard;
}

void Hand::discardCard(__int8 indexToDiscard)
{
	Card ** temp = new Card*[m_numCards - 1];

	for (int ii = 0; ii < indexToDiscard; ii++)
	{
		temp[ii] = m_currentCards[ii];
	}
	for (int ii = indexToDiscard + 1; ii < m_numCards; ii++)
	{
		temp[ii] = m_currentCards[ii];
	}
	m_numCards--;
	delete[] m_currentCards;
	m_currentCards = temp;
}
