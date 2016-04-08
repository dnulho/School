#ifndef SPORT_H
#define SPORT_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "cPlayer.h"

class Sport
{
public:
	Sport();
	~Sport();

	void DisplayMenu();
	void Add();
	void List();
	void Search() const;
	void Remove();

private:
	uint8_t m_playerCount;
	cPlayer** m_playerList;

};

#endif