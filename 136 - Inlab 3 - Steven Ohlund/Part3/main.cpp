/*****************************************************************************************************
*	WELL, WE GOT A FEW ISSUES THAT NEED FIXING - WORK THROUGH THIS A PIECE AT A TIME!
*   BTW - YOU THINK MORE DOCUMENATION MIGHT HELP?
*   MAKE SURE YOU NOW BEGIN TO FOLLOW THE STYLE GUIDE AS APPROPRIATE FOR ALL OUTSIDE LABS THAT YOU TURN-IN!
*****************************************************************************************************/
#define NOMCX
#include <windows.h>

#include <iostream>
using std::cin;

#include "courseBook.h"

#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h>
#include <crtdBG.h>

const int MAX_STUDENTS = 100;

int menu();
int getCoursePick(courseBook &cb);
int getStudentPick(student s[], const int &count);
GRADE getGrade();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	SetConsoleTitle(L"Grade Book");

	courseBook cb;
	cb.loadFile("courses.txt");
	student students[MAX_STUDENTS];
	int studentCount(0);
	bool done = false;

	while (!done)
	{
		string name;

		switch (menu())
		{
		case 1: // Print out all courses
			cout << endl;
			for (int x = 0; x < cb.numberOfCourses(); x++)
				cout << cb.getCourseById(x).getCourseName() << endl;
			cout << endl;
			break;
		case 2: // Print out course grades
			cout << endl;
			cb.getCourseById(getCoursePick(cb)).print();
			cout << endl;
			break;
		case 3: // Add student to system
			cout << endl << "Enter name: ";
			cin >> name;
			students[studentCount] = student(name);
			studentCount++;
			cout << endl;
			break;
		case 4: // Add student to course
			cout << endl;
			if (studentCount > 0)
				cb.getCourseById(getCoursePick(cb)).addStudent(&(students[getStudentPick(students, studentCount)]));
			else
				cout << "ERROR: There are no students in the system" << endl;
			break;
		case 5: // Change student's grade in a course
			cout << endl;
			if (studentCount > 0)
			{
				course& ctCrs = cb.getCourseById(getCoursePick(cb));
				if (ctCrs.getStudentCount() > 0)
				{
					student* ctStu = &(students[getStudentPick(students, studentCount)]);
					ctCrs.setGrade(ctStu, getGrade());
				}
				else
					cout << "ERROR: There are no students in the course" << endl;
			}
			else
				cout << "ERROR: There are no students in the system" << endl;
			cout << endl;
			break;
		case 6: // Exit
			done = true;
			break;
		}
	}

	return 0;
}

int menu()
{
	int choice = -1;

	cout << "MAIN MENU\n" << endl;
	cout << "1) Print out all available courses" << endl;
	cout << "2) Print the grades for a course" << endl;
	cout << "3) Add a student to the system" << endl;
	cout << "4) Add a student to a course" << endl;
	cout << "5) Change a students grade" << endl;
	cout << "6) Exit" << endl;

	cin >> choice;

	return choice;
}

int getCoursePick(courseBook &cb)
{
	int choice;

	for (int x = 0; x < cb.numberOfCourses(); x++)
	{
		cout << x << ") " << cb.getCourseById(x).getCourseName() << endl;
	}

	cin >> choice;
	cout << endl << endl;
	return choice;
}

int getStudentPick(student s[], const int &count)
{
	int choice;

	for (int x = 0; x < count; x++)
		cout << x << ") " << s[x].getName() << endl;

	cout << "Enter choice: ";
	cin >> choice;

	return choice;
}

GRADE getGrade()
{
	GRADE g;
	int choice;
	cout << "4) A\n3) B\n2) C\n1) D\n0) F\n-1) Not Set" << endl;

	cin >> choice;
	g = (GRADE)choice;

	return g;
}
