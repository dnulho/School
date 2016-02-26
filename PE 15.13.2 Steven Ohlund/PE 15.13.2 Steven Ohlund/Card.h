#include "Enums.h"
#ifndef CARD_H
#define CARD_H
enum Suit { Diamond, Club, Heart, Spade };
const char SUIT[4]{ 04, 05, 03, 06 };

enum Card_Val { Ace = 0, Deuce, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

extern const char* CARD_VAL[];

class Card
{
public:
	Card(Suit suit, Card_Val value);
	~Card();
	int CardValue();
	void DisplayCard();
	Suit GetSuit();

private:
	Card();
	Suit m_suit;
	Card_Val m_val;
};
#endif