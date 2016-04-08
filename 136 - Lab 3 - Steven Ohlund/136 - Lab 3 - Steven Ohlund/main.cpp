/***********************************************************************************************************
* Author: Steven Ohlund
* Filename: main.cpp
* Created: 4.7.16
* Modified: NA
***********************************************************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <crtdbg.h>

#include "cString.h"
/***********************************************************************************************************
* Purpose:
*
*
*
***********************************************************************************************************/
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	cString test1;
	cString test2("This is a Test");
	cString test3(test2);
	cString test4 =  "Another Test";
	cString test5 = test4;
	cout << "test1: " << test1 
		<< "\ntest2: " << test2
		<< "\ntest3: " << test3
		<< "\ntest4: " << test4
		<< "\ntest5: " << test5;


	return 0;
}

/***********************************************************************************************************
* Purpose:
*
*
*
***********************************************************************************************************/