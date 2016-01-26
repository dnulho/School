/******************************************************
* Author: Steven Ohlund
* Filename: Source.cpp
* Created: 1.20.16
* Modified:
******************************************************/
#define _CRTDBG_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <crtdbg.h>

// Global Constant Declarations
const int BUFFSIZE = 81;

// Function Declarations
void OpenFile(char *** ingList, int * numIngs, const char * filename);
int Menu();
void SearchIngredient(char ** ingList, int numIng);
int FindIng(char ** ingList, int numIng, char * findIng);
void AddIng(char **& ingList, int & numIng, char * nIng);
void RemoveIng();
void EditIng();
void SaveListToFile(char ** ingList, int numIng, const char * filename);
void DisplayList();
void CheckRecipe();
void PurgeMem(char **& ingList, int & numIng);
void AddIngredient();
void RemoveIngredient();
void EditIngredient();

/******************************************************
*
*
*
******************************************************/
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	char ** fullIngList = nullptr;
	int numIng = 0;
	bool done = false;

	OpenFile(&fullIngList, &numIng, "pantry.txt");
	

	while (!done)
	{
		switch (Menu())
		{
		case 0:
			SaveListToFile(fullIngList, numIng, "pantry.txt");
			PurgeMem(fullIngList, numIng);
			done = true;
			break;
		case 1:
			AddIngredient();
			break;
		case 2:
			RemoveIngredient();
			break;
		case 3:
			SearchIngredient(fullIngList, numIng);
			break;
		case 4:
			EditIngredient();
			break;
		case 5:
			SaveListToFile(fullIngList, numIng, "pantry.txt");
			break;
		case 6:
			DisplayList();
			break;
		case 7:
			CheckRecipe();
			break;
		}
	}
}

/******************************************************
*
*
*
******************************************************/
void OpenFile(char *** ingList, int * numIngs, const char * filename)
{
	char buffer[BUFFSIZE];
	ifstream fileIn(filename);
	if (fileIn.is_open())
	{
		while (!fileIn.eof())
		{
			fileIn.getline(buffer, BUFFSIZE);
			AddIng(*ingList, *numIngs, buffer);
		}
	}
	else
	{
		cout << "Error: Unable to find " << filename << endl;
	}
}

/******************************************************
*
*
*
******************************************************/
int Menu()
{
	system("CLS");
	int choice = 0;
	cout << "Menu Option\n"
		<< "1) Add Ingredient\n"
		<< "2) Remove ingredient\n"
		<< "3) Search Ingredient\n"
		<< "4) Edit Ingredient\n"
		<< "5) Save Ingredients to file\n"
		<< "6) Display Ingredients\n"
		<< "7) Check Recipe for Ingredients\n"
		<< "0) Exit\n";
	cin >> choice;
	return choice;
}

/******************************************************
*
*
*
******************************************************/
void SearchIngredient(char ** ingList, int numIng)
{
	char buffer[BUFFSIZE];
	int index;

	system("CLS");
	cout << "What are you searching for: ";
	cin >> buffer;
	index = FindIng(ingList, numIng, buffer);
	if (index != -1)
	{
		cout << buffer << " was found and is item " << index + 1;
	}
	else
	{
		cout << buffer << " was not found." << endl;
	}
	cout << endl;
	system("pause");
}

/******************************************************
* Purpose: Find the desired index of the passed ingredent.
*
* Precondition: All arguments must exist and be valid.
*
* Postcondition: returns the index of found, -1 if not.
* 
******************************************************/
int FindIng(char ** ingList, int numIng, char * findIng)
{
	int found = -1;
	int center = numIng / 2;
	int index = center;
	int highLow = 0;
	bool done = false;

	while (found == -1 && !done)
	{
		highLow = _stricmp(ingList[center], findIng);
		
		if (highLow == 0)
		{
			found = index;
		}
		else if (highLow == 1)
		{
			index += center;
		}
		else if (highLow == -1)
		{
			index -= center;
		}
		if (center == 1 || index == 0)
		{
			done = true;
		}
		center = (center + 1) / 2;

	}
	return found;
}

/******************************************************
* Purpose: Add the passed ingredient to the ingList, sorted by stricmp.
*
* Precondition: All arguments must exist and be valid.
*
* Postcondition: nIng is added to ingList in alphabetical order, numIng increased by one.
*
******************************************************/
void AddIng(char **& ingList, int & numIng, char * nIng)
{
	char ** temp = new char*[numIng + 1]{ nullptr };
	int ii = 0;
	if (ingList != nullptr && numIng != 0)
	{
		while (ii < numIng && _stricmp(nIng, *(ingList + ii)) > 0)
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
	}
	ingList = temp;
	numIng++;
}

/******************************************************
*
*
*
******************************************************/
void RemoveIng(char **& ingList, int & numIng, char * dIng)
{
	if (ingList != nullptr && numIng != 0)
	{
		char ** temp = new char*[numIng - 1]{ nullptr };
		int ii = 0;
		while (ii < numIng && _stricmp(dIng, *(ingList + ii)) != 0)
		{
			temp[ii] = ingList[ii];
			ii++;
		}
	}
	else if (ingList == nullptr && numIng == 0)
	{
		cout << "The passed array is empty, " << dIng << " was not found.";
	}
	else
	{
		cout << "Error: RemoveIng() was passed invalid values" << endl;
	}
}

/******************************************************
*
*
*
******************************************************/
void EditIng()
{

}

/******************************************************
*
*
*
******************************************************/
void SaveListToFile(char ** ingList, int numIng, const char * filename)
{
	ofstream fileOut(filename);
	for (int ii = 0; ii < numIng; ii++)
	{
		fileOut << ingList[ii] << endl;
	}
	fileOut.close();
}

/******************************************************
*
*
*
******************************************************/
void DisplayList()
{

}

/******************************************************
*
*
*
******************************************************/
void CheckRecipe()
{

}

/******************************************************
*
*
*
******************************************************/
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

/******************************************************
*
*
*
******************************************************/
void AddIngredient()
{

}

/******************************************************
*
*
*
******************************************************/
void RemoveIngredient()
{

}

/******************************************************
*
*
*
******************************************************/
void EditIngredient() 
{

}