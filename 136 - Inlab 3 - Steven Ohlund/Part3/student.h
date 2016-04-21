#include <string>

using std::string;

#ifndef STUDENT_H
#define STUDENT_H

class student
{
public:
	student(string name = "") { m_name = name; }

	const string& getName() const { return m_name; }

private:
	string m_name;
};

#endif