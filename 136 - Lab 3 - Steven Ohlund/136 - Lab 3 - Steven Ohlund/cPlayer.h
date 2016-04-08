#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "cString.h"

class cPlayer
{
public:
	cPlayer(const cString& name, int grade, double gpa);
	~cPlayer();

private:
	cString m_name;
	int m_grade;
	double m_gpa;
};

#endif