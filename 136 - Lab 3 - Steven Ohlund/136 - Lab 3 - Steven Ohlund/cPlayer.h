#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <iomanip>
using std::setw;

#include "cString.h"

class cPlayer
{
	friend class Sport;
public:
	cPlayer(const cString& name, int grade, double gpa);
	~cPlayer();
	
	bool Search(const cString& find) const { return find == m_name; };
	void Display() const;



private:
	cString m_name;
	int m_grade;
	double m_gpa;
};

#endif