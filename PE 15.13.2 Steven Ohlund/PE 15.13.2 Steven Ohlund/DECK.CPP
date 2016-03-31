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
	m_fullDeck = new Card*[numCards];		// Dynamic 2d array
	int oddCards = numCards % 13;			// check to see if there is going to be a partial suit
	int suit = 0;
	for (; suit < numCards / 13; suit++)	// Prepares full suits for population
	{
		for (int ii = 0; ii < 13; ii++)		// Populates full suits
		{
			m_fullDeck[(suit * 13) + ii] = new Card(static_cast<Suit>(suit), static_cast<Card_Val>(ii));
		}
	}
	if (oddCards != 0)
	{
		for (int ii = 0; ii < oddCards; ii++)// Populates partial suits as necessary.
		{
			m_fullDeck[(suit * 13) + ii] = new Card(static_cast<Suit>(suit), static_cast<Card_Val>(ii));
		}
	}
	cout << "Deck Built\n";
}

Deck::~Deck()
{						// pretty standard deletion algorithim
	cout << "Destroying Deck\n";			// delete each element
	for (int ii = 0; ii < m_numCards; ii++)
	{
		delete m_fullDeck[ii];
		m_fullDeck[ii] = nullptr;
	}
	cout << "Deleting card pointer array\n";
	delete[] m_fullDeck;					// delete array
	m_fullDeck = nullptr;
	m_numCards = 0;							// update element counter to 0
	cout << "Deck Destroyed\n";
}

void Deck::Shuffle()
{
	srand(static_cast<int>(time(NULL)));
	Card * temp;
	int random = 0;
	for (int ii = 0; ii < m_numCards; ii++)
	{
		random = rand() % m_numCards;			// Get a random number within the card range
		temp = m_fullDeck[ii];					// Swap the pointers between the current card
		m_fullDeck[ii] = m_fullDeck[random];	// and the random card.
		m_fullDeck[random] = temp;
	}
}

void Deck::DisplayDeck()
{
	for (int ii = 0; ii < m_numCards; ii++)		// Display each card in order
	{
		m_fullDeck[ii]->DisplayCard();
	}
}

Card * Deck::Deal()
{
	Card * rtnptr = nullptr;
	if (this != nullptr)
	{
		while (m_fullDeck[m_topCard]->IsDealt())	// If the dealt flag in the card is true,
		{											// move to the next card.
			if (m_topCard < m_numCards - 1)
				m_topCard++;
			else
				m_topCard = 0;
		}
		m_fullDeck[m_topCard]->Deal();				// Set the dealt flag on the card about
		rtnptr = m_fullDeck[m_topCard];				// to be dealt, and ready pointer to be returned.

		if (m_topCard < m_numCards - 1)				// Move to the next card.
			m_topCard++;
		else
			m_topCard = 0;
	}
	return rtnptr;									// Return pointer to card being dealt.
}
