#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void RecurseChar(char * myArray, int numElements);

int main()
{
	const int BUFFSIZE = 81;
	char buffer[BUFFSIZE];
	cout << "What string do you want to recurse: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(buffer, BUFFSIZE);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	RecurseChar(buffer, strlen(buffer));
	cout << "Your recursed string is: " << buffer;
}

void RecurseChar(char * myArray, int numElements)
{
	char temp;
	char* last = (myArray + sizeof(char) * (numElements - 1));
	if (numElements > 2)
	{
		RecurseChar(myArray + sizeof(char), numElements - 2);
	}
	temp = *myArray;
	*myArray = *last;
	*last = temp;
}