#define CRTDBG_MAP_ALLOC

#include <vector>
using std::vector;
#include <crtdbg.h>

#include "cBook.h"

void CheckBook(cBook book);
void CheckBookByRef(cBook& book);
void CheckTemp(cBook temp);
cBook CheckReturn();


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	vector<cBook> library = { {"Prata", 100, false}, {"Nagler", 101, true}, {"Collins", 102, false} };
	cout << endl;
	cBook currentBook = library[0];
	currentBook = library[2];
	cout << endl;
	currentBook.Display();
	cout << endl;
	CheckBook(library[1]);
	cout << endl;
	CheckBookByRef(library[2]);
	cout << endl;
	CheckTemp(cBook("Test", 901, true));
	cout << endl;
	library.emplace_back(CheckReturn());
	return 0;
}

void CheckBook(cBook book)
{
	cout << "Inside CheckBook()" << endl;
}

void CheckBookByRef(cBook& book)
{
	cout << "Inside CheckBookByRef()" << endl;
}

void CheckTemp(cBook temp)
{
	cout << "Inside CheckTemp()" << endl;
}

cBook CheckReturn()
{
	cout << "Inside CheckReturn()" << endl;
	return cBook("Using C++", 132);
}