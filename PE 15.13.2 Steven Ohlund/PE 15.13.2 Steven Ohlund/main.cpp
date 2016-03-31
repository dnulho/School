/******************************************************
* Author: Steven Ohlund
* Filename: main.cpp
* Created: 2.19.16
* Modified:
*
******************************************************/

#define _CRTDBG_MAP_ALLOC
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <crtdbg.h>

#include "Deck.h"
#include "Card.h"

int Menu();

/******************************************************
* Lab/Assignment: PE 15.13.2
*
* Overview:
*	Create a Card and Deck class.
*	Build a main function that shows off the capability of these classes
*	Specifically the shuffle and deal functions within the Deck class.
*	Correctly manage dynamic memory.
*
* Input:
*	User Menu Selections from Keyboard.
*
* Output:
*	Card Values to Screen.
*
******************************************************/
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	bool done = false;
	Deck * deck = nullptr;
	int input = 0;
	Card * currentCard = nullptr;

	while (!done)
	{
		switch (Menu())
		{
		case 1:
			cout << "How many cards do you want in your deck?";
			cin >> input;
			delete deck;
			deck = new Deck(input);
			break;
		case 2:
			if (deck != nullptr)
				deck->DisplayDeck();
			else
				cout << "There is no deck to display.\n";
			break;
		case 3:
			if (deck != nullptr)
			{
				deck->Shuffle();
				cout << "Deck shuffled\n";
			}
			else
				cout << "There is no deck to shuffle.\n";
			break;
		case 4:
			currentCard = deck->Deal();
			cout << "Your Corrent Card is: ";
			currentCard->DisplayCard();
			currentCard->Return();
			currentCard = nullptr;
			cout << "Card Returned to Deck" << endl;
			break;
		case 0:
			done = true;
		case 5:
			delete deck;
			deck = nullptr;
			cout << "Deck deleted.\n";
			break;
		}
	}
	return 0;
}

// User Input Menu that drives the main switch option selection
int Menu()
{
	int choice;
	cout << "1) Get Deck\n"
		<< "2) Display Deck\n"
		<< "3) Shuffle Deck\n"
		<< "4) Deal A Card\n"
		<< "5) Delete Deck\n"
		<< "0) Exit\n";
	cin >> choice;
	return choice;
}