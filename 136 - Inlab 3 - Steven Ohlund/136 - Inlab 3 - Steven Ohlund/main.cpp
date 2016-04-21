#define CRTDBG_MAP_ALLOC

#include <vector>
using std::vector;
#include <crtdbg.h>

#include "cBook.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	vector<cBook> library = { {"Prata", 100, false}, {"Nagler", 101, true}, {"Collins", 102, false} };
	cBook currentBook = library[0];
	currentBook = library[2];
	return 0;
}