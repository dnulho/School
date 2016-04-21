#include "course.h"


course::course(std::string name, int credits)
	:m_name(name), m_credits(credits), m_students(), m_studentCount(0)
{
}

void course::addStudent(student* s)
{
	entry temp;
	temp.s = s;
	temp.g = NOTSET;

	m_students[m_studentCount] = temp;
	m_studentCount++;
}

void course::print()
{
	cout << this->m_name << "\nCredits: " << this->m_credits << endl;
	cout << "Student Name  Grade" << endl;
	for (int x = 0; x < m_studentCount; x++)
	{
		cout << std::setw(14) << std::left << m_students[x].s->getName() << getGrade(m_students[x].g) << endl;
	}
	cout << "\n" << endl;
}

void course::setGrade(student *s, GRADE g)
{
	for (int x = 0; x < m_studentCount; x++)
	{
		if (m_students[x].s == s)
			m_students[x].g = g;
	}
}

const char* course::getGrade(GRADE g)
{
	switch (g)
	{
	case A:
		return "A";
	case B:
		return "B";
	case C:
		return "C";
	case D:
		return "D";
	case F:
		return "F";
	case NOTSET:
		return "(Not Set)";
	default:
		return "Error: getGrade() passed invalid data";
	}
}
