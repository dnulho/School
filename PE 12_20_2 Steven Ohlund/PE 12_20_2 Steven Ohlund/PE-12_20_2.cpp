/*******************************************************************************
* Author: Steven Ohlund
* Filename: PE-12_20_2.cpp
* Created: 1.22.16
* Modified: 1.23.16 - Finished and completed code.
*
* Note: Try running this program on its own source code, it's cool what it does!
*
*******************************************************************************/
#define _CRTDBG_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iomanip>
using std::ios;
using std::setw;
#include <fstream>
using std::ifstream;
#include <crtdbg.h>

//Function Declaration
void GetTextFromFile(char *** words, int ** wCount, int * numWords);
void AddWord(char *** wordArr, int ** cntArr, char * Nword, int * numWords);
int FindiWord(char ** wordArr, char * nWord, int numWords);
void PrintReport(char ** wordArr, int * wCount, int numWords);
void PurgeArrays(char *** wordArr, int ** wCount, int * numWords);


/*******************************************************************************
* Purpose: Write a program that reads in a text file one word at a time. Store
* that word into a dynamically created array when it is first encountered. Create
* a parallel integer array to hold the count of the number of times that each word
* appears in the text file.
*
* Input: User input as necessary.
*		 Text file to count the words contained inside.
*
* Output: Print a report to the screen stating each word that was found and how
* many times it was found.
*
*******************************************************************************/
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	char ** words = nullptr;
	int * countArray = nullptr;
	int diffWdCnt = 0;
	GetTextFromFile(&words, &countArray, &diffWdCnt);
	PrintReport(words, countArray, diffWdCnt);
	system("pause");
	PurgeArrays(&words, &countArray, &diffWdCnt);
	return 0;
}

/*******************************************************************************
* Asks the user to input the name of a file and reads it into dynamic memory.
*
* Pre-condition: All arguments must be valid and exist.
*
* Post-condition: All words in a file passed by the user are inputted into wordArr.
*				  Each word has a matching value in wCount that counts the number of times that word is found in the file.
*				  numWords contains the number of words and values that wordArr and wCount contain.
*
*******************************************************************************/
void GetTextFromFile(char *** wordArr, int ** wCount, int * numWords)
{
	char buffer[82] = { '\0' };
	ifstream fileIn;
	bool done = false;
	int index = -1;

	while (!done)
	{
		cout << "Please enter the text file to read: ";
		cin >> buffer;
		fileIn.open(buffer);
		if (!fileIn.is_open())
		{
			cout << "I'm Sorry, I can't find the requested file. Please try again." << endl;
		}
		else
		{

			while (!fileIn.eof())
			{
				fileIn >> buffer;
				char * last = (buffer + sizeof(char) * strlen(buffer) - 1);
				if ((*last <= 'A' || *last >= 'Z') && (*last <= 'a' || *last >= 'z'))
				{
					*last = '\0';
				}
				index = FindiWord(*wordArr, buffer, *numWords);	// poor search function + multiple calls 
																// => small increase in memory + single call.
				if (index == -1) // if buffer does not exist in wordArr
				{
					AddWord(wordArr, wCount, buffer, numWords);
				}
				else // if buffer does exist in wordArr
				{
					(*(*wCount + index))++;
				}
			}
			done = true;
		}
		fileIn.close();
	}
}

/*******************************************************************************
* Adds passed new word to the array, a new value(1) to crtArr, and increments numWords.
*
* Pre-condition: All arguments must be valid and exist.
*
* Post-condition: numWords is incremented.
*				  nWord is added to the end of wordArr.
*				  cntArr is expanded by 1, and the value of that expansion is 1.
*
*******************************************************************************/
void AddWord(char *** wordArr, int ** cntArr, char * nWord, int * numWords)
{
	char ** wTemp = new char *[*numWords + 1]{ nullptr };
	int * cTemp = new int[*numWords + 1]{ 0 };

	for (int ii = 0; ii < *numWords; ii++)
	{
		*(wTemp + ii) = *(*wordArr + ii);
		*(cTemp + ii) = *(*cntArr + ii);
	}
	wTemp[*numWords] = new char[strlen(nWord) + 1]{ '\0' };
	strcpy(wTemp[*numWords], nWord);
	cTemp[*numWords] = 1;
	if (*wordArr != nullptr)
	{
		delete[] * wordArr;
		*wordArr = nullptr;
	}
	*wordArr = wTemp;

	if (*cntArr != nullptr)
	{
		delete[] * cntArr;
		*cntArr = nullptr;
	}

	*cntArr = cTemp;
	(*numWords)++;
}

/*******************************************************************************
* Looks for the given word in the given char ** array and returns the index number
* if found, or -1 if not found. *
*
* Pre-condition: All arguments must be valid and exist.
*
* Post-condition: Returns the index of the word if it is found or -1 if not.
*
*******************************************************************************/
int FindiWord(char ** wordArr, char * nWord, int numWords)
{
	int index = -1;
	int ii = 0;
	while (ii < numWords && index == -1)
	{
		if (_stricmp(wordArr[ii], nWord)) // same word returns 0/false.
		{
			ii++;
		}
		else
		{
			index = ii;
		}

	}
	return index;
}

/*******************************************************************************
* Prints all words and number of times each word occurs to screen.
*
* Pre-condition: All arguments must be valid and exist.
*
* Post-condition: Values and characters are displayed in a human readable form.
*
*******************************************************************************/
void PrintReport(char ** wordArr, int * wCount, int numWords)
{
	const int WIDTH = 20;
	cout.setf(ios::left);
	cout << setw(WIDTH) << "Word" << "Frequency" << endl;
	for (int ii = 0; ii < numWords; ii++)
	{
		cout << setw(WIDTH) << wordArr[ii] << wCount[ii] << endl;
	}
}

/*******************************************************************************
* Deletes all active dynamic memory used by program.
*
* Pre-condition: All arguments must be valid and exist.
*
* Post-condition: Passed dynamic memory pointers are released and set to nullptr.
*				  numWords is set to 0.
*
*******************************************************************************/
void PurgeArrays(char *** wordArr, int ** wCount, int * numWords)
{
	for (int ii = 0; ii < *numWords; ii++)
	{
		delete[] * (*wordArr + ii);
		*(*wordArr + ii) = nullptr;
	}
	delete[] * wordArr;
	*wordArr = nullptr;
	delete[] * wCount;
	*wCount = nullptr;
	*numWords = 0;
}