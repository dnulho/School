/******************************************************
* Author: Steven Ohlund
* Filename: main.cpp
* Created: 2.12.16
* Modified: 
******************************************************
* Hexdump of a binary file.
*
*
*
******************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <iomanip>
using std::ios;
using std::setw;

int main()
{
	const short BUFFSIZE = 80;
	char buffer[BUFFSIZE] = { '\0' };
	bool done = false;
	ifstream inFile;
	cout << "What file do you want to read: ";
	cin >> buffer;
	inFile.open(buffer, ios::in | ios::binary);
	while (!done)
	{
		if (inFile.is_open())
		{
			while (!inFile.eof())
			{
				inFile.read(buffer, BUFFSIZE);

			}
			inFile.close();
			done = true;
		}
		else
		{
			cout << "Error: Can't open " << buffer << endl;
		}
	}
	return 0;
}