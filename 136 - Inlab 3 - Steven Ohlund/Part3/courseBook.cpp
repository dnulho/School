#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
using std::ifstream;

#include "courseBook.h"

void courseBook::loadFile(std::string file)
{
	char buffer[100];
	ifstream inFile(file.c_str());

	if (inFile.is_open())
	{
		while (inFile.getline(buffer, 100, '\n'))
		{
			char* name = strtok(buffer, ",");
			char* creditsstr = strtok(0, ",");
			int c = atoi(creditsstr);
			m_courses[m_courseCount] = course(name, c);
			m_courseCount++;
		}
	}
}

course& courseBook::getCourseById(const int &id)
{
	return (m_courses[id]);
}