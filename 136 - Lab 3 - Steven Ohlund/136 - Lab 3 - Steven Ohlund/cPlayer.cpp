#include "cPlayer.h"

cPlayer::cPlayer(const cString & name, int grade, double gpa)
	:m_name(name), m_grade(grade), m_gpa(gpa)
{
}

cPlayer::~cPlayer()
{
}

void cPlayer::Display() const
{
	cout.setf(std::ios::left);
	cout << "Name: " << setw(20) << m_name << "Grade: " << setw(6) << m_grade << "GPA: " << m_gpa << endl;
}
