#include "Deck.h"
#include <iostream>
using std::cout;
#include <time.h>
#include <random>
using std::srand;
using std::rand;

Deck::Deck(int numCards)
	:m_numCards(numCards), m_fullDeck(nullptr), m_topCard(0)
{
	cout << "Building a " << numCards << " Card Deck\n";
	m_fullDeck = new Card*[numCards];
	int oddCards = numCards % 13;
	int suit = 0;
	for (; suit < numCards / 13; suit++)
	{
		for (int ii = 0; ii < 13; ii++)
		{
			m_fullDeck[(suit * 13) + ii] = new Card(static_cast<Suit>(suit), static_cast<Card_Val>(ii));
		}
	}
	if (oddCards != 0)
	{
		for (int ii = 0; ii < oddCards; ii++)
		{
			m_fullDeck[(suit * 13) + ii] = new Card(static_cast<Suit>(suit), static_cast<Card_Val>(ii));
		}
	}
	cout << "Deck Built\n";
}

Deck::~Deck()
{
	cout << "Destroying Deck\n";
	for (int ii = 0; ii < m_numCards; ii++)
	{
		delete m_fullDeck[ii];
		m_fullDeck[ii] = nullptr;
	}
	cout << "Deleting card pointer array\n";
	delete[] m_fullDeck;
	m_fullDeck = nullptr;
	cout << "Deck Destroyed\n";
}

void Deck::Shuffle()
{
	srand(static_cast<int>(time(NULL)));
	Card * temp;
	int random = 0;
	for (int ii = 0; ii < m_numCards; ii++)
	{
		random = rand() % m_numCards;
		temp = m_fullDeck[ii];
		m_fullDeck[ii] = m_fullDeck[random];
		m_fullDeck[random] = temp;
	}
}

void Deck::DisplayDeck()
{
	for (int ii = 0; ii < m_numCards; ii++)
	{
		m_fullDeck[ii]->DisplayCard();
	}
}

Card * Deck::Deal()
{
	Card * rtnptr = nullptr;
	if (this != nullptr)
	{
		while (m_fullDeck[m_topCard]->IsDealt())
		{
			if (m_topCard < m_numCards - 1)
				m_topCard++;
			else
				m_topCard = 0;
		}
		m_fullDeck[m_topCard]->Deal();
		rtnptr = m_fullDeck[m_topCard];

		if (m_topCard < m_numCards - 1)
			m_topCard++;
		else
			m_topCard = 0;
	}
	return rtnptr;
}
