#include <string>
#include <vector>
#include "student.h"
#include <iostream>
#include <iomanip>

using std::string;
using std::vector;
using std::cout;
using std::endl;

#ifndef COURSE
#define COURSE

enum GRADE
{
	A = 4,
	B = 3,
	C = 2,
	D = 1,
	F = 0,
	NOTSET = -1
};

struct entry
{
	student *s;
	GRADE g;
};

class course
{
public:
	course(string name = "", int credits = -1);
	~course() {}

	int getCredits() const { return m_credits; }

	void addStudent(student* s);
	void print();
	void setGrade(student *s, GRADE g);

	string& getCourseName() { return m_name; }
	int getStudentCount() { return m_studentCount; }

private:
	const char* getGrade(GRADE g);

	string m_name;
	int m_credits;
	entry m_students[100];
	int m_studentCount;
};

#endif