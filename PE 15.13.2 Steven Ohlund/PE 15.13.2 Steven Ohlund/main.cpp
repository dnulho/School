/******************************************************
* Author: Steven Ohlund
* Filename: main.cpp
* Created: 2.19.16
* Modified:
*
*******************************************************
* Lab/Assignment: PE 15.13.2
*
* Overview:
*
*
* Input:
*
*
* Output:
*	Screen.
*
******************************************************/
#define _CRTDBG_MAP_ALLOC
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <crtdbg.h>

#include "Deck.h"
#include "Hand.h"

int Menu();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	bool done = false;
	Deck * deck = nullptr;
	unsigned __int8 input = 0;
	unsigned __int8 numPlayers = 0;
	Hand ** player = nullptr;

	while (!done)
	{
		switch (Menu())
		{
		case 1:
			cout << "How many cards do you want in your deck?";
			cin >> input;
			deck = new Deck(input);
			cout << "How many players are playing?";
			cin >> numPlayers;
			player = new Hand*[numPlayers];
			for (__int8 ii = 0; ii < numPlayers; ii++)
			{
				player[ii] = new Hand;
			}
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

			break;
		case 0:
			done = true;
		case 5:
			for (__int8 ii = 0; ii < numPlayers; ii++)
			{
				delete player[ii];
				player[ii] = nullptr;
			}
			delete[] player;
			player = nullptr;
			numPlayers = 0;
			delete deck;
			deck = nullptr;
			cout << "Game deleted.\n";
			break;
		}
	}
	return 0;
}

int Menu()
{
	int choice;
	cout << "1) Get Deck\n"
		<< "2) Display Deck\n"
		<< "3) Shuffle Deck\n"
		<< "4) Deal Hand\n"
		<< "5) Delete Game\n"
		<< "0) Exit\n";
	cin >> choice;
	return choice;
}