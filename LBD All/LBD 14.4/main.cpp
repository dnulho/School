#define _CRTDBG_MAP_ALLOC
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include "Person.h"
#include <crtdbg.h>

int Menu();
void PergeDatabase(Person **& database, int & entries);
int FindPerson(Person ** database, int entries, string fname_to_find);
void OpenFile(Person **& database, int & entries, string filename);


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	string buffer;
	Person ** database = nullptr;
	int entries = 0;

	switch (Menu())
	{
	case 1:
		cout << "What first name are you looking for: ";
		FindPerson();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	}
	return 0;
}

int Menu()
{
	int select;
	cout << "-------------Menu-------------\n" << endl
		<< "1) Find a Person's Information by First Name\n"
		<< "2) Add a Person to the Database\n"
		<< "3) Edit a Person's Information\n"
		<< "4) Display All Records to Screen\n"
		<< "5) Quit\n";
	cin >> select;
	return select;
}

void PergeDatabase(Person **& database, int & entries)
{
	for (int ii = 0; ii < entries; ii++)
	{
		delete database[ii];
		database[ii] = nullptr;
	}
	delete[] database;
	database = nullptr;
	entries = 0;
}


int FindPerson(Person ** database, int entries, string fname_to_find)
{
	int found = -1;

	if (database != nullptr && entries != 0)
	{
		int low = 0;
		int high = entries - 1;
		int mid = (high + low) / 2;

		while ((found == -1) && (low <= high))
		{
			int comp = stricmp(database[mid]->Getfname().c_str(), fname_to_find.c_str());

			if (comp == 0)
			{
				found = mid;
			}
			else if (comp < 0)
			{
				low = (mid + 1);
			}
			else // (comp > 0)
			{
				high = (mid - 1);
			}
			mid = (high + low) / 2;
		}
	}
	return found;
}

void OpenFile(Person **& database, int & entries, string filename)
{
	int ii = 0;
	const int BUFFSIZE = 81;
	char buffer[BUFFSIZE];
	ifstream fileIn(filename);

	if (fileIn.is_open())
	{
		while (!fileIn.eof())
		{
			fileIn.getline(buffer, BUFFSIZE);

			database[ii];

		}
	}
	else
	{
		cout << "Error: Unable to find " << filename.c_str() << endl;
	}
}

bool AddPerson(Person **& database, int & entries, Person * newP)
{
	Person ** temp = new Person*[entries + 1];
	int ii = 0;
	bool good = true;

	if (FindPerson(database, entries, newP->Getfname) == -1)
	{
		if (database != nullptr && entries != 0)
		{
			while (ii < entries &&  stricmp(database[ii]->Getfname().c_str(), newP->Getfname().c_str()) > 0)
			{
				temp[ii] = database[ii];
				ii++;
			}
			temp[ii] = newP;
			while (ii < entries)
			{
				temp[ii + 1] = database[ii];
				ii++;
			}
			delete[] database;
			database = nullptr;
		}
		else if (database == nullptr && entries == 0)
		{
			temp[ii] = newP;
		}
		else
		{
			cout << "Error: AddPerson() passed invalid data." << endl;
			good = false;
		}
		database = temp;
		entries++;
	}
	else
	{
		delete[] temp;
		cout << "Person already present\n";
		good = false;
	}
	return good;
}