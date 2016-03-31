#ifndef ENUMS_H
#define ENUMS_H

// Suit Enum, Joker is 5th suit to allow jokers to exist.
enum Suit { Diamond, Club, Heart, Spade, Joker };
const char SUIT[5]{ 04, 05, 03, 06, 01 };

// Card Enum, ace is low by default, if it needs to be high, can be changed.
enum Card_Val { Ace = 0, Deuce, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
extern const char* CARD_VAL[];
#endif