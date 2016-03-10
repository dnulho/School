#ifndef ENUMS_H
#define ENUMS_H
enum Suit { Diamond, Club, Heart, Spade, Joker };
const char SUIT[5]{ 04, 05, 03, 06, 01 };

enum Card_Val { Ace = 0, Deuce, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
extern const char* CARD_VAL[];
#endif