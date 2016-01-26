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
using std::ios;
#include <crtdbg.h>

// Global Constant Declarations
const int BUFFSIZE = 81;

// Function Declarations
void OpenFile(char *** ingList, int * numIngs, const char * filename);
int  Menu();
void SearchIngredient(char ** ingList, int numIng);
int  FindIng(char ** ingList, int numIng, char * findIng);
bool AddIng(char **& ingList, int & numIng, char * nIng);
bool RemoveIng(char **& ingList, int & numIng, char * dIng);
void EditIng(char **& ingList, int & numIng, int index, char * newIng);
void SaveListToFile(char ** ingList, int numIng, const char * filename);
void DisplayList(char ** ingList, int numIng);
void PurgeMem(char **& ingList, int & numIng);
void AddIngredient(char **& ingList, int & numIng);
void RemoveIngredient(char **& ingList, int & numIng);
void EditIngredient(char **& ingList, int & numIng);

void Recipe(char ** panList, int panNum);
int  RecipeMenu();
void OpenRecipeFile(char **& ingList, int & numIngs);
void FindMissing(char ** sourceList, int sourceNum, char ** searchList, int searchNum, char **& newList, int & newNum);
void DisplayMissingList(char ** recList, int recNum, char ** panList, int panNum);
void ShoppingList(char ** recList, int recNum, char ** panList, int panNum);


/******************************************************
*
*
*
******************************************************/
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	char ** ingList = nullptr;
	int numIng = 0;
	bool done = false;

	OpenFile(&ingList, &numIng, "pantry.txt");

	while (!done)
	{
		switch (Menu())
		{
		case 0:
			SaveListToFile(ingList, numIng, "pantry.txt");
			PurgeMem(ingList, numIng);
			done = true;
			break;
		case 1:
			AddIngredient(ingList, numIng);
			system("pause");
			break;
		case 2:
			RemoveIngredient(ingList, numIng);
			system("pause");
			break;
		case 3:
			SearchIngredient(ingList, numIng);
			system("pause");
			break;
		case 4:
			EditIngredient(ingList,numIng);
			system("pause");
			break;
		case 5:
			SaveListToFile(ingList, numIng, "pantry.txt");
			break;
		case 6:
			DisplayList(ingList, numIng);
			system("pause");
			break;
		case 7:
			Recipe(ingList, numIng);
			break;
		}
	}
}

/******************************************************
* Purpose: Load filename into ingList, set numIngs to correct value.
*
* Precondition: All arguments must exist and be valid.
*	filename must be .txt and newline deliminated.
*
* Postcondition: ingList is propigated with everything in filename.
* numIngs set to number of values in ingList.
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
* Purpose: Clean up main(). Allow user to pick what they want to do.
*
* Precondition: None.
*
* Postcondition: Returns user input.
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
		<< "7) Go to Recipe Menu\n"
		<< "0) Exit\n";
	cin >> choice;
	return choice;
}

/******************************************************
* Purpose: User friendly wrapper for FindIng().
*
* Precondition: All arguments must exist and be valid.
*
* Postcondition: User entered name is passed to FindIng() and the result is displayed in a human understandable form.
******************************************************/
void SearchIngredient(char ** ingList, int numIng)
{
	char buffer[BUFFSIZE];
	int index;

	system("CLS");
	cout << "What are you searching for: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(buffer, BUFFSIZE);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
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
}

/******************************************************
* Purpose: Find the desired index of the passed ingredent.
*
* Precondition: All arguments must exist and be valid.
*
* Postcondition: returns the index if found, -1 if not.
*
******************************************************/
int FindIng(char ** ingList, int numIng, char * findIng)
{
	int found = -1;

	if (ingList != nullptr && numIng != 0)
	{
		int low = 0;
		int high = numIng;
		int mid;

		while ((found == -1) && (low < high))
		{
			mid = (high + low) / 2;
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
		}
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
bool AddIng(char **& ingList, int & numIng, char * nIng)
{
	char ** temp = new char*[numIng + 1]{ nullptr };
	int ii = 0;
	int sort;
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
		cout << "Ingredient already present\n";
		good = false;
	}
	return good;
}

/******************************************************
* Purpose: Remove the passed ingredient from ingList.
*
* Precondition: All arguments must exist and be valid.
* 
* Postcondition: If dIng exists in ingList, it is removed, numIng is decrememted, and returns true.
* If it is not found, prints appropriate message to display, and returns false.
******************************************************/
bool RemoveIng(char **& ingList, int & numIng, char * dIng)
{
	bool good = false;

	if (ingList != nullptr && numIng != 0)
	{
		int index = FindIng(ingList, numIng, dIng);
		if (index != -1)
		{
			char ** temp = new char*[numIng - 1]{ nullptr };
			int ii = 0;
			while (ii < index)
			{
				temp[ii] = ingList[ii];
				ii++;
			}
			delete ingList[ii];
			ingList[ii] = nullptr;
			while (ii < numIng - 1)
			{
				temp[ii] = ingList[ii + 1];
			}
			delete[] ingList;
			ingList = temp;
			numIng--;
			good = true;
		}
		else
		{
			cout << "Error: " << dIng << " could not be found." << endl;
		}
	}
	else if (ingList == nullptr && numIng == 0)
	{
		cout << "The passed array is empty, " << dIng << " was not found." <<endl;
	}
	else
	{
		cout << "Error: RemoveIng() was passed invalid values" << endl;
	}
	return good;
}

/******************************************************
* Purpose: Change a single element of ingList from existingIng to newIng
*
* Precondition: All arguments must exist and be valid.
*
* Postcondition: existinIng is removed from ingList and newIng takes its place.
******************************************************/
void EditIng(char **& ingList, int & numIng, int index, char * newIng)
{
	if (index >= numIng || index < 0)
	{
		cout << "Index is out of bounds." << endl;
	}
	else
	{
		delete[] ingList[index];
		ingList[index] = new char[strlen(newIng) + 1];
		strcpy(ingList[index], newIng);
	}

}

/******************************************************
* Purpose: Save the array to filename.
*
* Precondition: All arguments must exist and be valid.
*
* Postcondition: filename is overwritten wth the contents of ingList, newline deliminated.
******************************************************/
void SaveListToFile(char ** ingList, int numIng, const char * filename)
{
	ofstream fileOut(filename);
	if (fileOut.is_open())
	{
		for (int ii = 0; ii < numIng; ii++)
		{
			fileOut << ingList[ii];
			if (ii < numIng - 1)
			{
				fileOut << endl;
			}
		}
	}
	else
	{
		cout << "Error: Could not open " << filename << endl;
	}
	fileOut.close();
}

/******************************************************
* Purpose: Display the array to screen
*
* Precondition: All arguments must exist and be valid.
* 
* Postcondition: Array is displayed onscreen, newline deliminated.
******************************************************/
void DisplayList(char ** ingList, int numIng)
{
	system("CLS");
	for (int ii = 0; ii < numIng; ii++)
	{
		cout << ii+1 <<") " << ingList[ii] << endl;
	}
}

/******************************************************
* Purpose: To deallocate and release all dynamic memory and set everything back to 0 or nullptr.
*
* Precondition: All arguments must exist and be valid.
*
* Postcondition: All memory pointed to by ingList is released. ingList is nulled. numIng set to 0.
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
* Purpose: user friendly wrapper for AddIng().
*
* Precondition: All arguments must exist and be valid.
*
* Postcondition: User entered name is passed to ingList() to deal with.
******************************************************/
void AddIngredient(char **& ingList, int & numIng)
{
	char buffer[BUFFSIZE];

	system("CLS");
	cout << "What Ingredient would you like to add: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(buffer, BUFFSIZE);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	if (AddIng(ingList, numIng, buffer))
	{
		cout << buffer << " added\n";
	}
}

/******************************************************
* Purpose: User frinely wrapper for RemoveIng().
*
* Precondition: All arguments must exist and be valid.
*
* Postcondition: User enterd name is passed to RemoveIng() to deal with.
******************************************************/
void RemoveIngredient(char **& ingList, int & numIng)
{
	char buffer[BUFFSIZE];

	system("CLS");
	cout << "What Ingredient would you like to remove: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(buffer, BUFFSIZE);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	if (RemoveIng(ingList, numIng, buffer))
	{
		cout << buffer << " removed\n";
	}
}

/******************************************************
*
*
*
******************************************************/
void EditIngredient(char **& ingList, int & numIng)
{
	int choice = -1;
	char buffer[BUFFSIZE];

	while (choice < 0 || choice >= numIng)
	{
		DisplayList(ingList, numIng);
		cout << "What item number would you like to edit: ";
		cin >> choice;
	}
	choice--;
	
	cout << "What would you like to change it to: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(buffer, BUFFSIZE);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	
	cout << ingList[choice];
	EditIng(ingList, numIng, choice, buffer);
	cout << " changed to " << ingList[choice] << endl;
}

/******************************************************
* Purpose:
*
* Precondition:
*
* Postcondition:
******************************************************/
void Recipe(char ** panList, int panNum)
{
	char ** recList = nullptr;
	int recNum = 0;
	bool done = false;

	while (!done)
	{
		switch (RecipeMenu())
		{
		case 0:
			PurgeMem(recList, recNum);
			done = true;
			break;
		case 1:
			PurgeMem(recList, recNum);
			OpenRecipeFile(recList, recNum);
			break;
		case 2:
			DisplayList(recList, recNum);
			system("pause");
			break;
		case 3: // Missing ingredients
			DisplayMissingList(recList, recNum, panList, panNum);
			system("pause");
			break;
		case 4: // Shopping list
			ShoppingList(recList, recNum, panList, panNum);
			system("pause");
			break;
		}
	}
}

/******************************************************
* Purpose: Keep Recipe() clean.
*
* Precondition: None.
*
* Postcondition: Returns user input.
******************************************************/
int RecipeMenu()
{
	int choice;
	system("CLS");
	cout << "1) Load (New) Recipe file\n"
		<< "2) Show all ingredients\n"
		<< "3) Show missing ingredients\n"
		<< "4) Create/Add to Shopping list\n"
		<< "0) Exit\n";
	cin >> choice;
	return choice;
}

/******************************************************
* Purpose:
*
* Precondition:
*
* Postcondition:
******************************************************/
void OpenRecipeFile(char **& ingList, int & numIngs)
{
	char buffer[BUFFSIZE];
	bool done = false;
	bool write = false;

	while (!done)
	{
		cout << "What is the name of the file: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(buffer, BUFFSIZE);
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());

		ifstream fileIn(buffer);
		if (fileIn.is_open())
		{
			write = false;
			memset(buffer, '\0', sizeof(char)* BUFFSIZE);
			char current = '\0';
			int ii = 0;

			while (!fileIn.eof())
			{
				fileIn >> current;
				if ( current == '<')
				{
					write = true;
				}
				else if (current == '>')
				{
					write = false;
					AddIng(ingList, numIngs, buffer);
					memset(buffer, '\0', sizeof(char)* BUFFSIZE);
					ii = 0;
				}
				else if (write == true)
				{
					if (ii == BUFFSIZE - 1)
					{
						cout << "Error: Buffer overflow in OpenRecipeFile()" << endl;
						write = false;
						memset(buffer, '\0', sizeof(char)* BUFFSIZE);
						ii = 0;
					}
					else
					{
						buffer[ii] = current;
						ii++;
					}
				}
			}
			fileIn.close();
			done = true;
		}
		else
		{
			cout << "Error: Unable to find " << buffer << endl;
		}
	}
}

/******************************************************
* Purpose: Compare sourceList and searchList, place any items that are in searchList but not in sourceList into newList
*
* Precondition: sourceList and searchList must be sorted alphabetically.
*				sourceNum and searchNum must equal the number of values in their respective lists.
*
* Postcondition: all items that are in searchList but not in sourceList are now in newList.
******************************************************/
void FindMissing(char ** sourceList, int sourceNum, char ** searchList, int searchNum, char **& newList, int & newNum)
{
	for (int ii = 0; ii < searchNum; ii++)
	{
		if (FindIng(sourceList, sourceNum, searchList[ii]) == -1)
		{
			AddIng(newList, newNum, searchList[ii]);
		}
	}
}

/******************************************************
* Purpose:
*
* Precondition:
*
* Postcondition:
******************************************************/
void DisplayMissingList(char ** recList, int recNum, char ** panList, int panNum)
{
	char ** tempList = nullptr;
	int tempNum = 0;

	FindMissing(panList, panNum, recList, recNum, tempList, tempNum);
	DisplayList(tempList, tempNum);
	PurgeMem(tempList, tempNum);
}

/******************************************************
* Purpose:
*
* Precondition:
*
* Postcondition:
******************************************************/
void ShoppingList(char ** recList, int recNum, char ** panList, int panNum)
{
	const char filename[] = "shoppingList.txt";
	char ** tempList = nullptr;
	int tempNum = 0;

	OpenFile(&tempList, &tempNum, filename);
	FindMissing(panList, panNum, recList, recNum, tempList, tempNum);
	SaveListToFile(tempList, tempNum, filename);
	PurgeMem(tempList, tempNum);
}