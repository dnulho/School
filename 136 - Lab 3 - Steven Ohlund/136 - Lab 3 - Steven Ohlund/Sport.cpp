#include "Sport.h"

Sport::Sport()
	:m_playerCount(0), m_playerList(nullptr)
{
}

Sport::~Sport()
{
	for (int ii = 0; ii < m_playerCount; ii++)
	{ 
		delete m_playerList[ii];
		m_playerList[ii] = nullptr;
	}
	delete[] m_playerList;
	m_playerList = nullptr;
	m_playerCount = 0;
}

void Sport::DisplayMenu()
{
	char choice = '\0';
	while (choice != 'e' && choice != 'E')
	{
		cout << "Oregon Institute of Technology" << endl
			<< "\tA - Add a Player" << endl
			<< "\tS - Search For / Display a Player" << endl
			<< "\tD - Display all Players" << endl
			<< "\tR - Remove a Player" << endl
			<< "\tE - Exit" << endl;
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> choice;
		switch (choice)
		{
		case 'a':
		case 'A':
			Add();
			break;
		case 's':
		case 'S':
			Search();
			break;
		case 'd':
		case 'D':
			List();
			break;
		case 'r':
		case 'R':
			Remove();
			break;
		case 'e':
		case 'E':
			break;
		default:
			break;
		}
	}
}

void Sport::Add()
{
	const int BUFFSIZE = 100;
	char name[BUFFSIZE];
	int grade;
	double gpa;

	cout << "Player Name: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(name, BUFFSIZE);
	cout << "What grade is the Player in: (13-16) ";
	cin >> grade;
	cout << "What is the Player's current GPA: ";
	cin >> gpa;

	int index = 0;

	cPlayer ** temp = new cPlayer*[m_playerCount + 1];
	if (m_playerList != nullptr)
		while (index < m_playerCount && m_playerList[index]->m_name < name)
		{
			temp[index] = m_playerList[index];
			index++;
		}
	temp[index] = new cPlayer(name, grade, gpa);
	while (index < m_playerCount)
	{
		temp[index + 1] = m_playerList[index];
		index++;
	}
	delete[] m_playerList;
	m_playerList = temp;
	m_playerCount++;
}

void Sport::List()
{
	for (int ii = 0; ii < m_playerCount; ii++)
	{
		m_playerList[ii]->Display();
		cout << endl;
	}
}

void Sport::Search() const
{
	bool done = false;
	int index = 0;

	char name[100] = { '\0' };
	cout << "Name of Player to be Found: ";
	cin.getline(name, 100);

	while (!done && index < m_playerCount)
	{
		if (m_playerList[index]->Search(name))
			done = true;
		else
			index++;
	}
	if (index != m_playerCount)  // player found
		m_playerList[index]->Display();
	else
		cout << name << " not found" << endl;
}

void Sport::Remove()
{
	char name[100] = { '\0' };
	cout << "Name of Player to be Removed: ";
	cin.getline(name, 100);

	bool done = false;
	int index = 0;
	while (!done && index < m_playerCount)
	{
		if (m_playerList[index]->Search(name))
			done = true;
		else
			index++;
	}

	cPlayer ** temp = new cPlayer*[m_playerCount - 1];
	for (int ii = 0; ii < index; ii++)
	{
		temp[ii] = m_playerList[ii];
	}
	delete m_playerList[index];
	for (int ii = index; ii < m_playerCount - 1; ii++)
	{
		temp[ii] = m_playerList[ii + 1];
	}

	m_playerCount--;
	delete[] m_playerList;
	m_playerList = temp;
}
