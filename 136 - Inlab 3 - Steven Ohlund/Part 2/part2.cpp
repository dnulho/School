// File part2.cpp  - with a few modifications

// Make sure you watch how/when the ctor/dtor's fire
// NOTE:  sorry guys, looks like we got a bit of a problem here!  Please fix -
// and feel free to comment out any 'bad' code / problems at this point!  Just make 
// sure you know WHY you are copying it out...  The .h file ALSO has a slight problem or two.
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#include "mystring.h"


void foo(const String& obj1)
{
	String obj2 = obj1;

}

void WillThisFireCopyCtor(String x)
{
	cout << "\nWell, did it Fire Copy Ctor ?";
}


int main()
{
	String s1('A');	// what constructor gets called?

	String s2("Joe");

	WillThisFireCopyCtor(s2);

	char name[20];
	cout << "\nWhat is your name: ";
	cin >> name;
	cout << "\nHello " << name << "!\n\n";
	foo(name); // notice this - look whats passed - and how it
			   // will need to be converted - and impact upon the
			   // constructor - this gets a bit deep but is interesting
			   // REVIEW IT NOW!

	String s3;	// What is this supposed to be for?  Is it ok?
	String s4("WillEMakit");
	String s5;		// Who gets called and why - or is this a problem?
	s5 = s4;		//???

	return 0;
}
