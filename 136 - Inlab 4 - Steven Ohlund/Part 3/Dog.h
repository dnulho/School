#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <iomanip>

class Dog
{
	char m_name[20];
	char * m_breed;
	double m_weight;
	static int m_counter;
	// Add a data member (mCounter) to count number of dogs as they are being instantiated.
	// Not real sure where to put that but am sure you know – not sure but can you initialize
	// this value of this variable to 0 directly inside the class – try it
public:
	// Write the no-arg ctor & the dtor
	Dog() :m_name("UNKNOWN"), m_breed(nullptr), m_weight(-1) { m_counter++; };
	~Dog() { delete[] m_breed; m_counter--; };
	// Write a ctor that takes in three args for the respective data members
	Dog(char name[20], char* breed, double weight);
	// Write the copy ctor
	Dog(const Dog& copy);
	// Write a method to overload the op =
	Dog& operator=(Dog& rhs);
	// Write a member method (called Display) that will simply print out the data members 
	// values
	void Display();
	// Write a class method that we can use to make sure that the mCounter variable above was
	// 	set to 0 before we even instantiate a class.
	static int getCounter() { return m_counter; }
};