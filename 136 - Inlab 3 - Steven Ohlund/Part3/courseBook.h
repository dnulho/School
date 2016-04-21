#include "course.h"

#ifndef COURSE_H
#define COURSE_H

const int MAX_COURSE = 50;

class courseBook
{
public:
	courseBook() :m_courseCount(0) {}
	inline ~courseBook();
	void loadFile(string file);

	int numberOfCourses() const { return m_courseCount; }

	course& getCourseById(const int &id);
private:
	course m_courses[MAX_COURSE];
	int m_courseCount;
};

inline courseBook::~courseBook()
{
	for (int ii = 0; ii < m_courseCount; ii++)
	{
	}
}
#endif
