#define _CRTDBG_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <iomanip>
using std::ios;
#include <crtdbg.h>

struct Person
{
	char * name;
	int age;
	char gender;
};

void ReadData(Person **& list, int & numElements, const char * filename);
void AddPerson(Person **& list, int & numElements, const Person * newPerson);
void PurgePersonList(Person **& list, int & numElements);
void DisplayOne(Person display);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int numElements = 0;
	Person ** list = nullptr;

	ReadData(list, numElements, "records.txt");
	for (int ii = 0; ii < numElements; ii++)
	{
		DisplayOne(*list[ii]);
	}
	system("pause");
	PurgePersonList(list, numElements);
}

void ReadData(Person **& list, int & numElements, const char * filename)
{
	const int BUFFSIZE = 81;
	char buffer[BUFFSIZE];
	ifstream filein(filename);
	Person temp;

	if (filein.is_open())
	{
		while (!filein.eof())
		{
			filein.getline(buffer, BUFFSIZE);
			temp.name = strtok(buffer, ",");
			temp.age = atoi(strtok(nullptr, " "));
			temp.gender = *strtok(nullptr, "\0");

			AddPerson(list, numElements, &temp);
		}
	}
	else 
	{
		cout << "Error: ReadData() could not open " << filename << endl;
	}
}

void AddPerson(Person **& list, int & numElements, const Person * newPerson)
{
	Person ** temp = new Person*[numElements + 1];
	for (int ii = 0; ii < numElements; ii++)
	{
		temp[ii] = list[ii];
	}
	temp[numElements] = new Person;
	temp[numElements]->name = new char[strlen(newPerson->name) + 1];
	strcpy(temp[numElements]->name, newPerson->name);
	temp[numElements]->age = newPerson->age;
	temp[numElements]->gender = newPerson->gender;
	delete[] list;
	list = temp;
	numElements++;
}

void PurgePersonList(Person **& list, int & numElements)
{
	for (int ii = 0; ii < numElements; ii++)
	{
		delete[] list[ii]->name;
		list[ii]->name = nullptr;
		delete list[ii];
		list[ii] = nullptr;
	}
	delete[] list;
	list = nullptr;
	numElements = 0;
}

void DisplayOne(Person display)
{
	cout.setf(ios::left);
	cout << "Name: " << std::setw(15) << display.name
		<< "Age: " << std::setw(8) << display.age
		<< "Gender: ";
	if (display.gender == 'm' || display.gender == 'M')
		cout << "Male";
	else if (display.gender == 'f' || display.gender == 'F')
		cout << "Female";
	else
		cout << "Indeterminate";
	cout << endl;
}