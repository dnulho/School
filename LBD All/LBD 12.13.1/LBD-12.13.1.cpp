#define _CRTDBG_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <crtdbg.h>

const int BUFFSIZE = 81;

int Menu();
int FindIng(char ** ingList, int numIng, char * findIng);
bool AddIng(char **& ingList, int & numIng, char * nIng);
void DisplayList(char ** ingList, int numIng);
void AddIngredient(char **& ingList, int & numIng);
void PurgeMem(char **& ingList, int & numIng);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	char ** stocks = nullptr;
	int numStocks = 0;
	bool done = false;

	while (!done)
	{
		switch (Menu())
		{
		case 0:
			PurgeMem(stocks, numStocks);
			done = true;
			break;
		case 1: //Add Stock
			AddIngredient(stocks, numStocks);
			cout << "New list of stocks:\n";
		case 2: //Display Stocks
			DisplayList(stocks, numStocks);
			system("pause");
		}
	}
}

int Menu()
{
	system("CLS");
	int choice = 0;
	cout << "Menu Option\n"
		<< "1) Add Stock\n"
		<< "2) Display All Stocks\n"
		<< "0) Exit\n";
	cin >> choice;
	return choice;
}

int FindIng(char ** ingList, int numIng, char * findIng)
{
	int found = -1;

	if (ingList != nullptr && numIng != 0)
	{
		int low = 0;
		int high = numIng - 1;
		int mid = (high + low) / 2;

		while ((found == -1) && (low <= high))
		{
			int comp = _stricmp(ingList[mid], findIng);

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

bool AddIng(char **& ingList, int & numIng, char * nIng)
{
	char ** temp = new char*[numIng + 1]{ nullptr };
	int ii = 0;
	bool good = true;

	if (FindIng(ingList, numIng, nIng) == -1)
	{
		if (ingList != nullptr && numIng != 0)
		{
			while (ii < numIng &&  _stricmp(nIng, ingList[ii]) > 0)
			{
				temp[ii] = ingList[ii];
				ii++;
			}
			temp[ii] = new char[strlen(nIng) + 1];
			strcpy(temp[ii], nIng);
			while (ii < numIng)
			{
				temp[ii + 1] = ingList[ii];
				ii++;
			}
			delete[] ingList;
			ingList = nullptr;
		}
		else if (ingList == nullptr && numIng == 0)
		{
			temp[ii] = new char[strlen(nIng) + 1];
			strcpy(temp[ii], nIng);
		}
		else
		{
			cout << "Error: AddIng() passed invalid data." << endl;
			good = false;
		}
		ingList = temp;
		numIng++;
	}
	else
	{
		delete[] temp;
		cout << "Stock already present\n";
		good = false;
	}
	return good;
}

void DisplayList(char ** ingList, int numIng)
{
	for (int ii = 0; ii < numIng; ii++)
	{
		cout << ii + 1 << ") " << ingList[ii] << endl;
	}
}

void AddIngredient(char **& ingList, int & numIng)
{
	char buffer[BUFFSIZE];

	system("CLS");
	cout << "What Stock would you like to add: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(buffer, BUFFSIZE);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	if (AddIng(ingList, numIng, buffer))
	{
		cout << buffer << " added\n";
	}
	else
	{
		cout << buffer << " not added\n";
	}
}

void PurgeMem(char **& ingList, int & numIng)
{
	for (int ii = 0; ii < numIng; ii++)
	{
		delete[] ingList[ii];
		ingList[ii] = nullptr;
	}
	delete[] ingList;
	ingList = nullptr;
	numIng = 0;
}