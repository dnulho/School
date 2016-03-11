#include "Card.h"
const char* CARD_VAL[13]{ "Ace", "Deuce", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };

Card::Card(Suit suit, Card_Val value)
{
}

Card::~Card()
{}

int Card::CardValue()
{
	return 0;
}

void Card::DisplayCard()
{
}

Suit Card::GetSuit()
{
	return Suit();
}
