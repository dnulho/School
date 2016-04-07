#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "cDate.h"

int main()
{
	cDate today = { 4, 7, 2016 };
	for (int i = 0; i < 370; i++)
	{
		today.Increment();
		today.Display();
	}
	cout << "\nEnd of First Part " << endl;
	today.~cDate();
	today.SetMonth(6);
	for (int i(0); i < 16; i++)
	{
		today.Increment();
		today.Display();
	}
	cout << "\nEnd of Second Part " << endl;
	today.Set();
	for (int i = 0; i < 10; i++)
	{
		today.Display();
		today.Increment();
	}
	return 0;
}
