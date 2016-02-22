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

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Deck deck;

	return 0;
}